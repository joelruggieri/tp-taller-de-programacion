/*
 * IOThread.cpp
 *
 *  Created on: 01/11/2013
 *      Author: ezequiel
 */

#include "IOThread.h"
#include "src/Serializador.h"
void * func_entrada(void * arg) {
	ZonaSeguraMemoria * zona = (ZonaSeguraMemoria *) arg;
	IOThreadParams * params = (IOThreadParams *) (zona->getParams());
//	ColaEventos* colaEntrada = params->getCola();
	Status * status = params->getStatus();
Serializador serializador;
	//TODO VER CONDICION DE CORTE, podría estar en los parametros
	while (true) {
		usleep(250);
		//
		//ENTREGA3  poner pedido en la colaEntrada
		status->lock();
		status->refresh();
		status->unlock();
	}

	pthread_exit(NULL);
}

void * func_salida(void * arg) {
	ZonaSeguraMemoria * zona = (ZonaSeguraMemoria *) arg;
	IOThreadParams * params = (IOThreadParams *) (zona->getParams());
	Status* status = params->getStatus();
	ColaEventos* colaSalida = params->getCola();
	int socketDesc = params->getSocketDesc();
	Serializador serializador;
	int contador = 0;
	//TODO VER CONDICION DE CORTE, podría estar en los parametros
	while (contador < 20) {
		usleep(100000);
		NetworkMensaje* pop = colaSalida->front();
		MensajePlano msj("EZE COMETRABA");
		try {
			serializador.escribir(&msj, socketDesc);
		} catch (SerializacionException & e) {
			cout << e.what() << endl;
			contador++;
		}
		if (pop != NULL) {
			//ENTREGA3 ENVIAR A TRAVEZ DEL SOCKET antes del delete
			delete pop;
		}
		//refrezco el status para que no muera el thread
		status->lock();
		status->refresh();
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

//IOThread::~IOThread() {
//	// TODO Auto-generated destructor stub
//}

IOThread::IOThread(ColaEventos* a, ColaEventos* b, int socket) {
	this->colaEntrada = a;
	this->colaSalida = b;
	thEntrada = NULL;
	thSalida = NULL;
	this->socket = socket;
}

IOThread::~IOThread() {
}

void IOThread::run(Status* status) {
	if (thSalida == NULL) {
		this->param1 = new IOThreadParams(this->colaEntrada, status, this->socket);
		thEntrada = new ThreadPTM(func_entrada, clean, (void *) param1);

		this->param2 = new IOThreadParams(this->colaSalida, status,this->socket);
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

IOThreadParams::~IOThreadParams() {
}

Status* IOThreadParams::getStatus() {
	return this->status;
}
