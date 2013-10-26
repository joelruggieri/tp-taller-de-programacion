/*
 * JugadorThread.cpp
 *
 *  Created on: 25/10/2013
 *      Author: jonathan
 */

#include "JugadorThread.h"

JugadorThread::JugadorThread(int jugador, int socketDesc) {
	this->nroJugador = jugador;
	this->socketDesc = socketDesc;
}

void JugadorThread::run() {

	th = new thread ([this](){
		bool continuar = true;
		while(continuar){
			//ENTREGA3 Escuchar pedidos y deserializar
			cola->lock();
			//ENTREGA3  poner pedido en la cola
			cola->unlock();
			this_thread::yield();
			//ENTREGA3 si paso x tiempo de time out y no mando nada.
			//continuar = false;
		}
		dispo->lock();
		dispo->setDisponibilidad(this->nroJugador, -2);
		dispo->unlock();
	});


}

JugadorThread::~JugadorThread() {
	if(th != NULL){
		th->join();
		delete th;
	}
}

