/*
 * EventReceptorThread.cpp
 *
 *  Created on: 26/10/2013
 *      Author: jonathan
 */

#include "EventReceptorThread.h"
EventReceptorThread::EventReceptorThread(ColaEventos * in, UserEventVisitor* u, ViewMsjVisitor * v,
		MensajePlanoVisitor * m, MensajeInternoVisitor* i) {
	th = NULL;
	this->colaIn = in;
	this->params = NULL;
	this->distribuidor = new DistribuidorMensajes(u, v, m, i);
}

void * recibir(void *arg) {
	ZonaSeguraMemoria * zona = (ZonaSeguraMemoria *) arg;
	EventReceptorThreadParams * params = (EventReceptorThreadParams *) (zona->getParams());
	ColaEventos * colaEntrada = params->getColaIn();
	DistribuidorMensajes * ejecutor = params->getDistribuidor();
	//TODO VER CONDICION DE CORTE, podría estar en los parametros
	list<NetworkMensaje*> msjs;
	list<NetworkMensaje*>::iterator it;
	while (true) {
		usleep(10000);
		colaEntrada->getAll(msjs);
		if (msjs.size() > 0) {
			for (it = msjs.begin(); it != msjs.end(); ++it) {
//				YAML::Node node;
//				(*it)->serialize(&node);
//				cout << node << endl;
				ejecutor->procesar(*it);
			}
		}
		msjs.clear();
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

EventReceptorThreadParams::EventReceptorThreadParams(DistribuidorMensajes* c, ColaEventos* cola) {
	this->distribuidor = c;
	this->colaIn = cola;
}

EventReceptorThreadParams::~EventReceptorThreadParams() {
}

DistribuidorMensajes* EventReceptorThreadParams::getDistribuidor() {
	return distribuidor;
}
