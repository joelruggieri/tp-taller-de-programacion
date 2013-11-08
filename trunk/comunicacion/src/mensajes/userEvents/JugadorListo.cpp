/*
 * JugadorListo.cpp
 *
 *  Created on: 04/11/2013
 *      Author: jonathan
 */

#include "JugadorListo.h"
//NO ME MATEN, ME DIO PAJA POSTA HACER OTRA HERENCIA DISTINTA.
JugadorListo::JugadorListo(bool listo):UserEventMsj(false, false) {
	this->listo = listo;
}

void JugadorListo::acept(UserEventVisitor* v) {
	v->visit( this);
}

bool JugadorListo::isListo() const {
	return listo;
}


JugadorListo::~JugadorListo() {
	// TODO Auto-generated destructor stub
}

void JugadorListo::serialize(YAML::Node* nodo) {
	nodo->push_back(TAG_JUGADOR_LISTO);
	nodo->push_back(this->isListo());
}

NetworkMensaje* JugadorListo::deserialize(YAML::const_iterator& it) {
	bool listo = it->as<bool>();
		it++;
	return new JugadorListo(listo);
}
