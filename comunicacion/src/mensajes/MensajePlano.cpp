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

void MensajePlano::serialize(YAML::Emitter & out) {
	out << TAG_MSJ_PLANO;
	out << msj;
}

NetworkMensaje* MensajePlano::deserialize(YAML::const_iterator & it) {
	string msj = it->as<string>();
	it++;
	NetworkMensaje * salida = new MensajePlano(msj);
	return salida;
}

string MensajePlano::getMensaje() {
	return msj;
}

string MensajePlano::getTag() {
	return TAG_MSJ_PLANO;
}

void MensajePlano::acept(MensajeVisitor* v) {
	v->visit(this);
}

void MensajePlano::acept(MensajePlanoVisitor* v) {
	v->visit(this);
}
