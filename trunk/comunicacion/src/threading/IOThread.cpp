/*
 * IOThread.cpp
 *
 *  Created on: 01/11/2013
 *      Author: ezequiel
 */

#include "IOThread.h"
#include "../Serializador.h"
#include "../mensajes/MensajePlano.h"

void * func_entrada(void * arg) {
	ZonaSeguraMemoria * zona = (ZonaSeguraMemoria *) arg;
	IOThreadParams * params = (IOThreadParams *) (zona->getParams());
	ColaEventos* colaEntrada = params->getCola();
	Status * status = params->getStatus();
	int socket = params->getSocketDesc();
	int destinatario = params->getJugador();
	Serializador * serializador = new Serializador(destinatario);
	zona->setDatosLiberables((void*) serializador);
	//TODO VER CONDICION DE CORTE, podría estar en los parametros
	while (true) {
		usleep(20000);
		list<NetworkMensaje*> lectura;
		try {
			serializador->leer(socket, lectura);
			if(status->isAlive()){
				colaEntrada->push(lectura);
				status->refresh();
			}
			//refrezco el status para que no muera el thread
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
	int nroJugador= params->getJugador();
	Serializador*  serializador = new Serializador(nroJugador);
	zona->setDatosLiberables((void *) serializador);
	Status * status = params->getStatus();
	//TODO VER CONDICION DE CORTE, podría estar en los parametros
	status->lock();
	bool continuar = status->isAlive();
	status->unlock();
	list<NetworkMensaje*>::iterator it;
	while (continuar) {
		usleep(25000);
		list<NetworkMensaje*> lectura;
		pthread_setcancelstate(PTHREAD_CANCEL_DISABLE, NULL);
		colaSalida->getAll(lectura);
		try {
			if (lectura.size()>0) {
				serializador->escribir(lectura,socketDesc);
				for(it= lectura.begin(); it!= lectura.end(); ++it){
					delete (*it);
				}
			}
			pthread_setcancelstate(PTHREAD_CANCEL_ENABLE, NULL);

		} catch (SerializacionException & e) {
			for(it= lectura.begin(); it!= lectura.end(); ++it){
				delete (*it);
			}
			pthread_setcancelstate(PTHREAD_CANCEL_ENABLE, NULL);
			cout << e.what() << endl;
			status->kill();
		}
		status->lock();
		continuar = status->isAlive();
		status->unlock();
	}
	pthread_exit(NULL);
}


void * func_mantener_vivo(void * arg) {
	ZonaSeguraMemoria * zona = (ZonaSeguraMemoria *) arg;
	IOThreadParams * params = (IOThreadParams *) (zona->getParams());
	ColaEventos* colaSalida = params->getCola();
	int nroJugador= params->getJugador();
	Status * status = params->getStatus();
	status->lock();
	bool continuar = status->isAlive();
	status->unlock();
	int tiempoMuerto = TIMEOUT *0.8;
	list<NetworkMensaje*>::iterator it;
	NetworkMensaje * msje;
	Logger log;
	while (continuar) {
		sleep(tiempoMuerto);
		log.debug("Encolando mensaje para mantener viva la conexion");
		msje=new MensajePlano(TAG_MSJ_NOTIMEOUT);
		msje->setDestinatario(nroJugador);
		colaSalida->push(msje);
		status->lock();
		continuar = status->isAlive();
		status->unlock();
	}
	pthread_exit(NULL);
}

void * clean(void * arg) {
	//esto se va a ejecutar si se llama al cancel de los threads.
	Serializador * ser = (Serializador*) arg;
	delete ser;
	return 0;
}

IOThread::IOThread(ColaEventos* a, ColaEventos* b, Status * status, int socket, int jugador, bool mantenervivo) {
	this->colaEntrada = a;
	this->colaSalida = b;
	this->jugador = jugador;
	this->status  = status;
	thEntrada = NULL;
	thSalida = NULL;
	this->socket = socket;
	param1 = NULL;
	param2 = NULL;
	param3 = NULL;
	thMantenerVivo = NULL;
	mantenerVivo = mantenervivo;
}

void IOThread::run() {
	if (thSalida == NULL) {
		this->param1 = new IOThreadParams(this->colaEntrada, status, this->socket, jugador);
		thEntrada = new ThreadPTM(func_entrada, clean, (void *) param1);

		this->param2 = new IOThreadParams(this->colaSalida, status, this->socket, jugador);
		thSalida = new ThreadPTM(func_salida, clean, (void *) param2);
		if(mantenerVivo){
			this->param3 = new IOThreadParams(this->colaSalida, status, this->socket, jugador);
			thMantenerVivo = new ThreadPTM(func_mantener_vivo, clean, (void *) param2);
		}
	}
}

IOThreadParams::IOThreadParams(ColaEventos* cola, Status* status, int socketDesc,  int jugador) {
	this->cola = cola;
	this->status = status;
	this->socketDesc = socketDesc;
	this->jugador = jugador;
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
		log.debug("Cancelando Thread");
		thEntrada->cancel();
		log.debug("Cancelada Entrada");
		thSalida->cancel();
		log.debug("Cancelada Salida");
		if(mantenerVivo){
			thMantenerVivo->cancel();
			log.debug("Cancelado refresco de timeouts");
		}
		log.debug("Thread Cancelado");
//		close(param1->getSocketDesc());
		deleteAll();
	}

}

void IOThread::deleteAll() {
	close(this->socket);
	delete thEntrada;
	delete thSalida;
	delete param1;
	delete param2;
	if(mantenerVivo){
		delete thMantenerVivo;
		delete param3;
	}
	thEntrada = NULL;
	thSalida = NULL;
	thMantenerVivo = NULL;
	param1 = NULL;
	param2 = NULL;
	param3 = NULL;
}

IOThread::~IOThread() {
	//esto hace un join de los threads
	if (thEntrada != NULL) {
		deleteAll();
	}
}

IOThreadParams::~IOThreadParams() {
}

int IOThreadParams::getJugador() {
	return jugador;
}
