/*
 * JugadorThread.cpp
 *
 *  Created on: 25/10/2013
 *      Author: jonathan
 */

#include "JugadorThread.h"
#include "ThreadStatus.h"
JugadorThread::JugadorThread(ColaEventos*c, ThreadStatus *status) {
	this->nroJugador = status->getNroJugador();
	this->status = status;
	this->socketDesc = status->getSockedDesc();
	thEntrada = NULL;
	colaEntrada = c;
	colaSalida = status->getColaSalida();
}

void JugadorThread::run() {
	if (thSalida != NULL || thEntrada != NULL) {

		thEntrada = new thread([this]() {
			bool continuar = true;
			while(continuar) {
				//ENTREGA3 Escuchar pedidos y deserializar
				colaEntrada->lock();
				//ENTREGA3  poner pedido en la colaEntrada
				colaEntrada->unlock();
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
				colaSalida->lock();
				NetworkMensaje* pop = colaSalida->front();
				colaSalida->unlock();
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

void JugadorThread::exit() {
	delete thEntrada;
	thEntrada = NULL;
	delete thSalida;
	thSalida = NULL;
}

JugadorThread::~JugadorThread() {
	if (thEntrada != NULL) {
		//MANDALE HACHA
		exit();
	}
}

