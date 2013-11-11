/*
 * StepModeloThread.cpp
 *
 *  Created on: 07/11/2013
 *      Author: jonathan
 */

#include "StepModeloThread.h"
#include "src/mensajes/internos/StepModelo.h"
#include "src/ConstantesVista.h"

void * stepFunc(void * arg) {
	ZonaSeguraMemoria * zona = (ZonaSeguraMemoria *) arg;
	ColaEventos * cola = (ColaEventos*) zona->getParams();
	int sl = 100000.0/VELOCIDAD_REFRESCO;
	while (true) {
		usleep(sl);
		cola->push(new StepModelo());
	}
	pthread_exit(NULL);
}

StepModeloThread::StepModeloThread(ColaEventos * colaEntrada) {
	cola = colaEntrada;
	th = NULL;

}

StepModeloThread::~StepModeloThread() {
	// TODO Auto-generated destructor stub
}

void StepModeloThread::run() {
	if (th == NULL) {
		th = new ThreadPTM(stepFunc, 0, (void *) this->cola);
	}
}

void StepModeloThread::cleanAll() {
	delete this->th;
	this->th = NULL;
}

void StepModeloThread::cancel() {
	if (this->th != NULL) {
		this->th->cancel();
		cleanAll();
	}
}
