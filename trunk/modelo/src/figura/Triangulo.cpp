/*
 * Triangulo.cpp
 *
 *  Created on: 06/09/2013
 *      Author: jonathan
 */

#include "Triangulo.h"


Triangulo::Triangulo(float x, float y, float ancho, float alto) {
	this->x = x;
	this->y = y;
	this->ancho = ancho;
	this->alto = alto;
}

Triangulo::Triangulo() {
	this->x = 0;
	this->y = 0;
	this->ancho = 1;
	this->alto = 1;
}

void Triangulo::setAlto(float alto){
	this->alto = alto;

}

void Triangulo::setAncho(float ancho){
	this->ancho = ancho;

}

float Triangulo::getAlto() const{
	return alto;

}

float Triangulo::getAncho() const{
	return ancho;

}
Triangulo::~Triangulo() {
	// TODO Auto-generated destructor stub
}


bool Triangulo::contacto(float posX, float posY) {
	return this->isAdentro1D(posX, this->x, this->ancho)
			&& this->isAdentro1D(posY, this->y, this->alto);
}

bool Triangulo::contieneCentro(Figura* cuadrado) {
	return this->contacto(cuadrado->getX(), cuadrado->getY());
}
bool Triangulo::isAdentro1D(float pos, float posCentro, float ancho) {
	return (pos <= (posCentro + ancho / 2)) && (pos >= posCentro - ancho / 2);

}
