/*
 * MensajePlano.cpp
 *
 *  Created on: 30/10/2013
 *      Author: jonathan
 */

#include "MensajePlano.h"
#include "../ConstantesComunicacion.h"
MensajePlano::MensajePlano(string m) {
	this->msj= m;
}

MensajePlano::~MensajePlano() {
}

void MensajePlano::serialize(YAML::Node* nodo) {
	nodo->push_back(TAG_MSJ_PLANO);
	nodo->push_back(msj);
}

NetworkMensaje* MensajePlano::deserialize(YAML::const_iterator & it) {
	string msj = it->as<string>();
	NetworkMensaje * salida = new MensajePlano(msj);
	return salida;
}
