/*
 * JugadorThread.cpp
 *
 *  Created on: 25/10/2013
 *      Author: jonathan
 */

#include "JugadorThread.h"
#include "ThreadStatus.h"
#include "src/Serializador.h"
JugadorThread::JugadorThread(ColaEventos*c, ThreadStatus *status) {
	this->nroJugador = status->getNroJugador();
	this->status = status;
	this->socketDesc = status->getSockedDesc();
	thEntrada = NULL;
	thSalida = NULL;
	params1=NULL;
	params2=NULL;
	colaEntrada = c;
	colaSalida = status->getColaSalida();
}

void * func_entrada(void * arg){
	ZonaSeguraMemoria * zona = (ZonaSeguraMemoria * )arg;
	JugadorThreadParams * params = (JugadorThreadParams * )(zona->getParams());
	ColaEventos* colaEntrada = params->getCola();
	ThreadStatus * status = params->getStatus();
	Serializador * serializador = new Serializador();
	zona->setDatosLiberables((void *) serializador);
	//TODO VER CONDICION DE CORTE, podría estar en los parametros
	while(true) {
		//ENTREGA3 Escuchar pedidos y deserializar
		colaEntrada->lock();
		//ENTREGA3  poner pedido en la colaEntrada
		colaEntrada->unlock();
		//refrezco el status para que no muera el thread
		status->lock();
		status->refresh();
		status->unlock();
	}
	delete	serializador;

	pthread_exit(NULL);
}

void * func_salida(void * arg){
	ZonaSeguraMemoria * zona = (ZonaSeguraMemoria * )arg;
	JugadorThreadParams * params = (JugadorThreadParams * )(zona->getParams());
	ColaEventos* colaSalida = params->getCola();
	ThreadStatus * status = params->getStatus();
	Serializador * serializador = new Serializador();
	zona->setDatosLiberables((void *) serializador);
	//TODO VER CONDICION DE CORTE, podría estar en los parametros
	while(true) {
		colaSalida->lock();
		NetworkMensaje* pop = colaSalida->front();
		colaSalida->unlock();
		if (pop != NULL) {
			//ENTREGA3 ENVIAR A TRAVEZ DEL SOCKET antes del delete
			delete pop;
		}
	//refrezco el status para que no muera el thread
	status->lock();
	status->refresh();
	status->unlock();
	}
	delete serializador;
	pthread_exit(NULL);
}


void * clean(void * arg){
	//esto se va a ejecutar si se llama al cancel de los threads.
	Serializador * ser = (Serializador*) arg;
	delete ser;
	return 0;
}



void JugadorThread::run() {
	if (thSalida != NULL || thEntrada != NULL) {
		this->params1 = new JugadorThreadParams(this->colaEntrada,this->status,this->nroJugador,this->socketDesc);
		thEntrada = new ThreadPTM(func_entrada,clean,(void *) params1);

		this->params2 = new JugadorThreadParams(this->colaSalida,this->status,this->nroJugador,this->socketDesc);
		thSalida = new ThreadPTM (func_salida,clean, (void *) params2);
	}
}

void JugadorThread::cancel() {
	if(thEntrada ) {
		thEntrada->cancel();
		thSalida->cancel();
		deleteAll();
	}



}

void JugadorThread::deleteAll() {
	delete thEntrada;
	delete thSalida;
	delete params1;
	delete params2;
	thEntrada = NULL;
	thSalida = NULL;
	params1 = NULL;
	params2 = NULL;
}

JugadorThread::~JugadorThread() {
	//esto hace un join de los threads
	if (thEntrada != NULL) {
		deleteAll();
	}
}



JugadorThreadParams::JugadorThreadParams(ColaEventos * cola, ThreadStatus * status, int nrojug, int socketDesc) {
	this->cola = cola;
	this->nroJug = nrojug;
	this->socketDesc = socketDesc;
	this->status = status;
}

JugadorThreadParams::~JugadorThreadParams() {
}

ColaEventos* JugadorThreadParams::getCola() {
	return cola;
}

int JugadorThreadParams::getNroJug() {
	return nroJug;
}

ThreadStatus* JugadorThreadParams::getStatus(){
	return status;
}

int JugadorThreadParams::getSocketDesc(){
	return socketDesc;
}
