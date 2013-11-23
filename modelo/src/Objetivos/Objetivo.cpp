/*
 * Objetivo.cpp
 *
 *  Created on: 21/11/2013
 *      Author: ezequiel
 */

#include "Objetivo.h"

Objetivo::Objetivo(float x, float y, int numero) {
this->xD = x;
this->yD = y;
this->numeroObjetivo = numero;

}

Objetivo::~Objetivo() {
	// TODO Auto-generated destructor stub
}

int Objetivo::getNumeroObjetivo() const {
	return numeroObjetivo;
}

void Objetivo::setNumeroObjetivo(int numeroObjetivo) {
	this->numeroObjetivo = numeroObjetivo;
}

float Objetivo::getXD() const {
	return xD;
}

void Objetivo::setXD(float d) {
	xD = d;
}

float Objetivo::getYD() const {
	return yD;
}

void Objetivo::setYD(float d) {
	yD = d;
}
