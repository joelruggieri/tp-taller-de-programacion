/*
 * EventReceptorThread.cpp
 *
 *  Created on: 26/10/2013
 *      Author: jonathan
 */

#include "EventReceptorThread.h"

EventReceptorThread::EventReceptorThread(GeneralEventController * c, ColaEventos * in, ColaEventos * out) {
	th = NULL;
	this->colaIn = in;
	this->colaOut = out;
	this->controller = c;
	this->params = NULL;
}

void * funcThread(void *arg) {
	ZonaSeguraMemoria * zona = (ZonaSeguraMemoria *) arg;
	EventReceptorThreadParams * params = (EventReceptorThreadParams *) (zona->getParams());
	ColaEventos * colaEntrada = params->getColaIn();
//	GeneralEventController * controller = params->getController();
	//TODO VER CONDICION DE CORTE, podría estar en los parametros
	while (true) {
		usleep(10000);
		while(colaEntrada->hasNext()){
			NetworkMensaje* pop = colaEntrada->front();
			if (pop != NULL) {
				//ENTREGA3 enviar controller
				delete pop;
			}

		}
//		controller->
	}
	pthread_exit(NULL);

}

void EventReceptorThread::run() {
	if (th != NULL) {
		params = new EventReceptorThreadParams(this->controller, this->colaIn);
		th = new ThreadPTM(funcThread, 0, (void *) params);
	}
}

void EventReceptorThread::clearAll() {
	delete th;
	delete params;
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

GeneralEventController* EventReceptorThreadParams::getController() {
	return controller;
}

EventReceptorThreadParams::EventReceptorThreadParams(GeneralEventController* c, ColaEventos* cola) {
	this->controller = c;
	this->colaIn = cola;
}

EventReceptorThreadParams::~EventReceptorThreadParams() {
}

