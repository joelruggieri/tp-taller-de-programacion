/*
 * EventReceptorThread.cpp
 *
 *  Created on: 26/10/2013
 *      Author: jonathan
 */

#include "EventReceptorThread.h"

EventReceptorThread::EventReceptorThread(ColaEventos * in, UserEventVisitor* u, ViewMsjVisitor * v, MensajePlanoVisitor * m, MensajeInternoVisitor* i) {
	th = NULL;
	this->colaIn = in;
	this->params = NULL;
	this->distribuidor = new DistribuidorMensajes(u, v, m, i);
}

void * recibir(void *arg) {
	ZonaSeguraMemoria * zona = (ZonaSeguraMemoria *) arg;
	EventReceptorThreadParams * params =
			(EventReceptorThreadParams *) (zona->getParams());
	ColaEventos * colaEntrada = params->getColaIn();
	DistribuidorMensajes * ejecutor = params->getDistribuidor();
	//TODO VER CONDICION DE CORTE, podría estar en los parametros
	while (true) {
		usleep(10000);
		while (colaEntrada->hasNext()) {
			NetworkMensaje* pop = colaEntrada->front();
			if (pop != NULL) {
				ejecutor->procesar(pop);
			}
		}
	}
	pthread_exit(NULL);

}

void EventReceptorThread::run() {
	if (th == NULL) {
		params = new EventReceptorThreadParams(this->distribuidor, this->colaIn);
		th = new ThreadPTM(recibir, 0, (void *) params);
	}
}

void EventReceptorThread::clearAll() {
	delete th;
	delete params;
	th = NULL;
	params = NULL;
	delete distribuidor;
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

EventReceptorThreadParams::EventReceptorThreadParams(DistribuidorMensajes* c,
		ColaEventos* cola) {
	this->distribuidor = c;
	this->colaIn = cola;
}

EventReceptorThreadParams::~EventReceptorThreadParams() {
}

DistribuidorMensajes* EventReceptorThreadParams::getDistribuidor() {
	return distribuidor;
}
