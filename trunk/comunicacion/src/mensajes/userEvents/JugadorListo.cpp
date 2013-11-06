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

