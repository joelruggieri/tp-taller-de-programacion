/*
 * Cuadrado.cpp
 *
 *  Created on: 04/09/2013
 *      Author: jonathan
 */

#include "Cuadrado.h"

Cuadrado::Cuadrado(float x, float y, float ancho, float alto) {
	this->x = x;
	this->y = y;
	this->ancho = ancho;
	this->alto = alto;
}

Cuadrado::~Cuadrado() {
	// TODO Auto-generated destructor stub
}


bool Cuadrado::contacto(float posX, float posY) {
	return this->isAdentro1D(posX, this->x, this->ancho)
			&& this->isAdentro1D(posY, this->y, this->alto);
}

bool Cuadrado::contieneCentro(Figura* cuadrado) {
	return this->contacto(cuadrado->getX(), cuadrado->getY());
}
bool Cuadrado::isAdentro1D(float pos, float posCentro, float ancho) {
	return (pos <= (posCentro + ancho / 2)) && (pos >= posCentro - ancho / 2);

}

