/*
 * ColaSalida.cpp
 *
 *  Created on: 26/10/2013
 *      Author: joel
 */

#include "ColaEventos.h"

ColaEventos::ColaEventos() {
	// TODO Auto-generated constructor stub

}

ColaEventos::~ColaEventos() {
	// TODO Auto-generated destructor stub
}

void ColaEventos::push(NetworkMensaje* msj) {
	this->lock();
	this->msjs.push_back(msj);
	this->unlock();
}

NetworkMensaje* ColaEventos::front() {
	this->lock();
	NetworkMensaje * msj =this->msjs.front();
	this->msjs.remove(msj);
	this->unlock();
	return msj;
}

void ColaEventos::clear() {
	this->lock();
	list<NetworkMensaje*>::iterator it;
	for(it= this->msjs.begin(); it != this->msjs.end(); ++it){
		delete (*it);
	}
	msjs.clear();
	this->unlock();
}

bool ColaEventos::hasNext() {
	return !msjs.empty();
}