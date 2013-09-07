/*
 * ViewFiguraFactory.cpp
 *
 *  Created on: 05/09/2013
 *      Author: jonathan
 */

#include "ViewFiguraFactory.h"

ViewFiguraFactory::ViewFiguraFactory(float ancho, float alto) {
	this->ancho = ancho;
	this->alto = alto;
}

float ViewFiguraFactory::getAlto() const {
	return alto;
}

void ViewFiguraFactory::setAlto(float alto) {
	this->alto = alto;
}

float ViewFiguraFactory::getAncho() const {
	return ancho;
}

void ViewFiguraFactory::setAncho(float ancho) {
	this->ancho = ancho;
}

ViewFiguraFactory::~ViewFiguraFactory() {
	// TODO Auto-generated destructor stub
}

