/*
 * Zona.cpp
 *
 *  Created on: 30/08/2013
 *      Author: jonathan
 */

#include "ZonaDragAndDrop.h"
#include "../../vista/figura/FiguraView.h"


Zona::Zona(Cuadrado * cuerpo) {
	this->cuerpo = cuerpo;
}

Zona::~Zona() {
	delete this->cuerpo;
}


void Zona::setCuerpo(Cuadrado* cuerpo) {
	this->cuerpo = cuerpo;
}

Cuadrado*& Zona::getCuerpo() {
	return cuerpo;
}
