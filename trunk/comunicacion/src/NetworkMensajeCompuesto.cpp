/*
 * NetworkMensajeCompuesto.cpp
 *
 *  Created on: 24/10/2013
 *      Author: jonathan
 */

#include "NetworkMensajeCompuesto.h"
#include "NetworkMensaje.h"
NetworkMensajeCompuesto::NetworkMensajeCompuesto(int destinatario):NetworkMensaje(destinatario) {
	// TODO Auto-generated constructor stub

}

NetworkMensajeCompuesto::~NetworkMensajeCompuesto() {
	list<NetworkMensaje *>::iterator it;
	for(it= this->mensajes.begin(); it != this->mensajes.end(); ++it){
		delete (*it);
	}
}

void NetworkMensajeCompuesto::addMensaje(NetworkMensaje* mensaje) {
}

string NetworkMensajeCompuesto::serialize() {
	string msj = "";
	list<NetworkMensaje *>::iterator it;
	for(it= this->mensajes.begin(); it != this->mensajes.end(); ++it){
		msj.append((*it)->serialize() + "|");
	}
	//TODO PROBAR
	if (!msj.empty())
	 msj =  msj.substr(0,msj.length() -1);
	return msj;

}
