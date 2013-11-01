/*
 * ClienteThread.cpp
 *
 *  Created on: 30/10/2013
 *      Author: jonathan
 */

#include "ClienteThread.h"

ClienteThread::ClienteThread(ColaEventos* in, ColaEventos* out,
		Status* status, int socketId) {
	this->in = in;
	this->out = out;
	this->status = status;
	thEntrada=NULL;
	this->socket=socketId;
}

ClienteThread::~ClienteThread() {
	// TODO Auto-generated destructor stub
}

void ClienteThread::run() {

	if (thEntrada== NULL || thSalida == NULL) {

		thEntrada = new thread([this]() {
			bool continuar = true;
			while(continuar) {
				//ENTREGA3 Escuchar pedidos y deserializar
				in->lock();
				//ENTREGA3  recibir pedidos de la cola
				in->unlock();
				//refrezco el status para que no muera el thread
				status->lock();
				status->refresh();
				status->unlock();
				this_thread::yield();
			}
		});
		//TODO PUEDE FALLAR ESTO porque estan leyendo los dos threads a este objeto JugadorThread?
		thSalida = new thread([this]() {
			bool continuar = true;
			while(continuar) {
				out->lock();
				NetworkMensaje* pop = out->front();
				out->unlock();
				if (pop != NULL) {
					//ENTREGA3 ENVIAR A TRAVEZ DEL SOCKET.
				}
			//refrezco el status para que no muera el thread
			status->lock();
			status->refresh();
			status->unlock();
			this_thread::yield();
			}
		});

	}
}
