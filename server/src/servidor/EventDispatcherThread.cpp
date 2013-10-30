/*
 * EventDispatcherThread.cpp
 *
 *  Created on: 29/10/2013
 *      Author: jonathan
 */

#include "EventDispatcherThread.h"

#include <string>
using namespace std;

#include "ThreadStatus.h"

//dios... si esto funciona yo me recibo y se van todos a la concha de la madre.
EventDispatcherThread::EventDispatcherThread(ColaEventos * colaSalida, Disponibilidad * dispo) {
	this->cola = colaSalida;
	this->disponibilidad = dispo;
	th = NULL;
}

EventDispatcherThread::~EventDispatcherThread() {
	if (th == NULL) {
		delete th;
		th = NULL;

	}
}

void EventDispatcherThread::run() {
	if (th != NULL) {
		th = new thread([this]() {
			bool continuar = true;
			while(continuar) {
				//a repartir mijo.
				cola->lock();
				NetworkMensaje* front = this->cola->front();
				cola->unlock();
				disponibilidad->lock();
				ThreadStatus* destinatario = disponibilidad->getStatus(front->getDestinatario());
				disponibilidad->unlock();

				//TODO EL LOGGER NO ES MULTITHREAD :O
//				string msj = "Despacho mensaje a ";
//				log.concatenar(msj, front->getDestinatario());
//				log.debug(msj);
				destinatario->lock();
				ColaEventos* colaEvento = destinatario->getColaSalida();
				destinatario->unlock();

				colaEvento->lock();
				colaEvento->push(front);
				colaEvento->unlock();
			}
		});
	}
}
