/*
 * JugadorListo.cpp
 *
 *  Created on: 04/11/2013
 *      Author: jonathan
 */

#include "JugadorListo.h"

JugadorListo::JugadorListo(bool listo) {
	this->listo = listo;
}

void JugadorListo::procesar(UserEventVisitor* v) {
	v->visit( this);
}

bool JugadorListo::isListo() const {
	return listo;
}


JugadorListo::~JugadorListo() {
	// TODO Auto-generated destructor stub
}

