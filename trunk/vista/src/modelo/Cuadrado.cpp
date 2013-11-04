/*
 * Cuadrado.cpp
 *
 *  Created on: 04/09/2013
 *      Author: jonathan
 */

#include "Cuadrado.h"
#include <cmath>

Cuadrado::Cuadrado(float x, float y, float ancho, float alto) {
	this->ancho = ancho;
	this->alto = alto;
	this->x = x;
	this->y = y;
}

Cuadrado::Cuadrado() {
	this->x = 0;
	this->y = 0;
	this->ancho = 1;
	this->alto = 1;
}


void Cuadrado::setAlto(float alto){
	this->alto = alto;

}

void Cuadrado::setAncho(float ancho){
	this->ancho = ancho;

}

float Cuadrado::getAlto() const {
	return alto;

}

float Cuadrado::getAncho() const{
	return ancho;

}
Cuadrado::~Cuadrado() {
	// TODO Auto-generated destructor stub
}


bool Cuadrado::contacto(float posX, float posY) {
	double xc = posX;
	double yc= posY;
	return this->isAdentro1D(xc, this->x, this->ancho)
			&& this->isAdentro1D(yc, this->y, this->alto);
}


float Cuadrado::getX() const {
	return x;
}

void Cuadrado::setX(float x) {
	this->x = x;
}

float Cuadrado::getY() const {
	return y;
}

void Cuadrado::setY(float y) {
	this->y = y;
}
