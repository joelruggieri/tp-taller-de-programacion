/*
 * IOThread.cpp
 *
 *  Created on: 01/11/2013
 *      Author: ezequiel
 */

#include "IOThread.h"
#include "../Serializador.h"

#include <unistd.h>


void * func_entrada(void * arg) {
	ZonaSeguraMemoria * zona = (ZonaSeguraMemoria *) arg;
	IOThreadParams * params = (IOThreadParams *) (zona->getParams());
	ColaEventos* colaEntrada = params->getCola();
	Status * status = params->getStatus();
	int socket = params->getSocketDesc();
	Serializador * serializador = new Serializador();
	zona->setDatosLiberables((void*) serializador);
	//TODO VER CONDICION DE CORTE, podría estar en los parametros
	while (true) {
		usleep(250);
		list<NetworkMensaje*> lectura;
		try {
			serializador->leer(socket, lectura);
			colaEntrada->push(lectura);
			//refrezco el status para que no muera el thread
			status->refresh();
		} catch (SerializacionException & e) {
			status->kill();
		}
	}

	pthread_exit(NULL);
}

void * func_salida(void * arg) {
	ZonaSeguraMemoria * zona = (ZonaSeguraMemoria *) arg;
	IOThreadParams * params = (IOThreadParams *) (zona->getParams());
	ColaEventos* colaSalida = params->getCola();
	int socketDesc = params->getSocketDesc();
	Serializador*  serializador = new Serializador();
	zona->setDatosLiberables((void *) serializador);
	Status * status = params->getStatus();
	//TODO VER CONDICION DE CORTE, podría estar en los parametros
	status->lock();
	bool continuar = status->isAlive();
	status->unlock();
	while (continuar) {
		usleep(100000);
		NetworkMensaje* pop = colaSalida->front();
		try {
			pop = new MensajePlano ("pruieba");
			if (pop != NULL) {
				serializador->escribir(pop,socketDesc);
				delete pop;
			}

		} catch (SerializacionException & e) {
			cout << e.what() << endl;
			status->kill();
		}
		status->lock();
		continuar = status->isAlive();
		status->unlock();
	}
	close(socketDesc);
	pthread_exit(NULL);
}

void * clean(void * arg) {
	//esto se va a ejecutar si se llama al cancel de los threads.
	Serializador * ser = (Serializador*) arg;
	delete ser;
	return 0;
}

IOThread::IOThread(ColaEventos* a, ColaEventos* b, Status * status, int socket) {
	this->colaEntrada = a;
	this->colaSalida = b;
	this->status  = status;
	thEntrada = NULL;
	thSalida = NULL;
	this->socket = socket;
	param1 = NULL;
	param2 = NULL;
}

void IOThread::run() {
	if (thSalida == NULL) {
		this->param1 = new IOThreadParams(this->colaEntrada, status, this->socket);
		thEntrada = new ThreadPTM(func_entrada, clean, (void *) param1);

		this->param2 = new IOThreadParams(this->colaSalida, status, this->socket);
		thSalida = new ThreadPTM(func_salida, clean, (void *) param2);
	}
}

IOThreadParams::IOThreadParams(ColaEventos* cola, Status* status, int socketDesc) {
	this->cola = cola;
	this->status = status;
	this->socketDesc = socketDesc;
}

ColaEventos* IOThreadParams::getCola() {
	return this->cola;
}

int IOThreadParams::getSocketDesc() {
	return this->socketDesc;
}

Status* IOThreadParams::getStatus() {
	return this->status;
}


void IOThread::cancel() {
	if (thEntrada) {
		//cancelo solo el de entrada, ya que es el que puede estar muerto esperando, el de salida puede dar error y matar el mismo al cliente
		thEntrada->cancel();
		thSalida->cancel();
		deleteAll();
	}

}

void IOThread::deleteAll() {
	close(this->socket);
	delete thEntrada;
	delete thSalida;
	delete param1;
	delete param2;
	thEntrada = NULL;
	thSalida = NULL;
	param1 = NULL;
	param2 = NULL;
}

IOThread::~IOThread() {
	//esto hace un join de los threads
	if (thEntrada != NULL) {
		deleteAll();
	}
}

IOThreadParams::~IOThreadParams() {
}
