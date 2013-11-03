/*
 * EventReceptorThread.cpp
 *
 *  Created on: 26/10/2013
 *      Author: jonathan
 */

#include "EventReceptorThread.h"

EventReceptorThread::EventReceptorThread(GeneralEventController * c,
		ColaEventos * in, ColaEventos * out) {
	th = NULL;
	this->colaIn = in;
	this->colaOut = out;
	this->controller = c;
	this->params = NULL;
	this->ejecutor = new EjecutorMensajes(c);
}

void * recibir(void *arg) {
	ZonaSeguraMemoria * zona = (ZonaSeguraMemoria *) arg;
	EventReceptorThreadParams * params =
			(EventReceptorThreadParams *) (zona->getParams());
	ColaEventos * colaEntrada = params->getColaIn();
	EjecutorMensajes * ejecutor = params->getEjecutor();
	//TODO VER CONDICION DE CORTE, podría estar en los parametros
	while (true) {
		usleep(10000);
		while (colaEntrada->hasNext()) {
			NetworkMensaje* pop = colaEntrada->front();
			if (pop != NULL) {
				ejecutor->consumir(pop);
			}
		}
	}
	pthread_exit(NULL);

}

void EventReceptorThread::run() {
	if (th == NULL) {
		params = new EventReceptorThreadParams(this->ejecutor, this->colaIn);
		th = new ThreadPTM(recibir, 0, (void *) params);
	}
}

void EventReceptorThread::clearAll() {
	delete th;
	delete params;
	delete ejecutor;
	th = NULL;
	params = NULL;
}

void EventReceptorThread::cancel() {
	if (this->th != NULL) {
		this->th->cancel();
		clearAll();
	}
}

//produce join
EventReceptorThread::~EventReceptorThread() {
	if (this->th != NULL) {
		clearAll();
	}
}

ColaEventos* EventReceptorThreadParams::getColaIn() {
	return colaIn;
}

EjecutorMensajes * EventReceptorThreadParams::getEjecutor() {
	return ejecutor;
}

EventReceptorThreadParams::EventReceptorThreadParams(EjecutorMensajes* c,
		ColaEventos* cola) {
	this->ejecutor = c;
	this->colaIn = cola;
}

EventReceptorThreadParams::~EventReceptorThreadParams() {
}

