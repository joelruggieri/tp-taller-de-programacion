/*
 * EventDispatcherThread.cpp
 *
 *  Created on: 29/10/2013
 *      Author: jonathan
 */

#include "EventDispatcherThread.h"

#include <string>
#include "ThreadStatus.h"
using namespace std;

//dios... si esto funciona yo me recibo y se van todos a la concha de la madre.
EventDispatcherThread::EventDispatcherThread(ColaEventos * colaSalida, Disponibilidad * dispo) {
	this->params = new EventDispatcherThreadParams(colaSalida, dispo);
	th = NULL;
}

//esto genera un join
EventDispatcherThread::~EventDispatcherThread() {
	if (th == NULL) {
		cleanAll();
	}
	if(this->params != NULL){
		delete this->params;
	}

}

void * funcThread(void * arg) {
	ZonaSeguraMemoria * zona = (ZonaSeguraMemoria *) arg;
	EventDispatcherThreadParams * params = (EventDispatcherThreadParams*) (zona->getParams());
	ColaEventos* cola = params->getCola();
	Disponibilidad * disponibilidad = params->getDispo();
	list<NetworkMensaje*>::iterator it;
	Logger log;
//	TODO VER CONDICION DE CORTE, podría estar en los parametros
	while (true) {
		usleep(15000);
		list<NetworkMensaje*> msjs;
		cola->getAll(msjs);
		for(it= msjs.begin(); it != msjs.end(); ++it){
			NetworkMensaje* front = *it;
			disponibilidad->lock();
			ThreadStatus* destinatario = disponibilidad->getStatus(front->getDestinatario());
			disponibilidad->unlock();
			if(destinatario != NULL){
				destinatario->lock();
				ColaEventos* colaEvento = destinatario->getColaSalida();
				colaEvento->push(front);
				destinatario->unlock();
			} else {
				log.error("Mensaje enviado a un destinatario inexistente");
				delete front;
			}
		}

			//a repartir mijo.
	}
	pthread_exit(NULL);
}

void EventDispatcherThread::run() {
	if (th == NULL) {
		th = new ThreadPTM(funcThread,0,(void *)this->params);
	}
}

void EventDispatcherThread::cleanAll() {
	delete this->th;
	delete this->params;
	this->th = NULL;
	this->params = NULL;
}

void EventDispatcherThread::cancel() {
	if(this->th != NULL){
		this->th->cancel();
		cleanAll();
	}
}


EventDispatcherThreadParams::EventDispatcherThreadParams(ColaEventos * cola, Disponibilidad * disponibilidad) {
	this->cola =cola;
	this->dispo = disponibilidad;

}

ColaEventos* EventDispatcherThreadParams::getCola() {
	return cola;
}

Disponibilidad* EventDispatcherThreadParams::getDispo() {
	return dispo;
}

EventDispatcherThreadParams::~EventDispatcherThreadParams() {
}

