/*
 * DrawThread.cpp
 *
 *  Created on: 07/11/2013
 *      Author: jonathan
 */

#include "DrawThread.h"
#include "src/mensajes/internos/DrawEvent.h"

void * drawFunc(void * arg) {
	ZonaSeguraMemoria * zona = (ZonaSeguraMemoria *) arg;
	ColaEventos * cola = (ColaEventos*) zona->getParams();
	while (true) {
		usleep(33000);
		cola->push(new DrawEvent());
	}
	pthread_exit(NULL);
}

DrawThread::DrawThread(ColaEventos * colaEntrada) {
	cola = colaEntrada;
	th = NULL;

}

DrawThread::~DrawThread() {
	// TODO Auto-generated destructor stub
}

void DrawThread::run() {
	if (th == NULL) {
		th = new ThreadPTM(drawFunc, 0, (void *) this->cola);
	}
}

void DrawThread::cleanAll() {
	delete this->th;
	this->th = NULL;
}

void DrawThread::cancel() {
	if (this->th != NULL) {
		this->th->cancel();
		cleanAll();
	}
}
