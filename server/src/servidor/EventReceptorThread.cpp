/*
 * EventReceptorThread.cpp
 *
 *  Created on: 26/10/2013
 *      Author: jonathan
 */

#include "EventReceptorThread.h"

EventReceptorThread::EventReceptorThread(GeneralEventController *, ColaEventos * in, ColaEventos * out) {
	th = NULL;
	this->colaIn = in;
	this->colaOut = out;

}

void EventReceptorThread::run() {
	if (th != NULL) {
		th = new thread([this]() {
			bool continuar = true;
			while(continuar) {
//				//a repartir mijo.
//				cola->lock();
//				NetworkMensaje* front = this->cola->front();
//				cola->unlock();
//				disponibilidad->lock();
//				ThreadStatus* destinatario = disponibilidad->getStatus(front->getDestinatario());
//				disponibilidad->unlock();
//
//				//TODO EL LOGGER NO ES MULTITHREAD :O
//				string msj = "Despacho mensaje a ";
//				log.concatenar(msj, front->getDestinatario());
//				log.debug(msj);
//				destinatario->lock();
//				ColaEventos* colaEvento = destinatario->getColaSalida();
//				destinatario->unlock();
//
//				colaEvento->lock();
//				colaEvento->push(front);
//				colaEvento->unlock();
				colaIn->lock();
				NetworkMensaje* front = colaIn->front();
				colaIn->unlock();

				front->getDestinatario();
				//ENTREGA3 PASAR MENSAJE AL GENERAL EVENT CONTROLLER.

			}
		});
	}}

EventReceptorThread::~EventReceptorThread() {
	if(this->th != NULL){
		delete th;
		th =NULL;
	}
}

