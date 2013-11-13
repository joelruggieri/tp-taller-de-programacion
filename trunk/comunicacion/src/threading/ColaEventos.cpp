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
	NetworkMensaje * msj = NULL;
	if (msjs.size() != 0) {
		msj = this->msjs.front();
		this->msjs.pop_front();
	}
	this->unlock();
	return msj;
}

void ColaEventos::clear() {
	this->lock();
	list<NetworkMensaje*>::iterator it;
	for (it = this->msjs.begin(); it != this->msjs.end(); ++it) {
		delete (*it);
	}
	msjs.clear();
	this->unlock();
}

bool ColaEventos::hasNext() {
	lock();
	bool result = msjs.size() > 0;
	unlock();
	return result;
}

void ColaEventos::push(list<NetworkMensaje*> msjsin) {
	list<NetworkMensaje*>::iterator it;
	for (it = msjsin.begin(); it != msjsin.end(); ++it) {
		push(*it);
	}
}

void ColaEventos::getAll(list<NetworkMensaje*>& salida) {
	lock();
	list<NetworkMensaje*>::iterator it;
	if (msjs.size() > 0) {
		for (it = msjs.begin(); it != msjs.end(); ++it) {
			salida.push_back(*it);
		}
	}
	msjs.clear();
	unlock();
}

void ColaEventos::habilitar() {
	lock();
	habilitada = true;
	unlock();

}

void ColaEventos::deshabilitada() {
}

bool ColaEventos::isHabilitada() {
	return habilitada;
}
