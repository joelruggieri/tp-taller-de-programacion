/*
 * Cuadrado.cpp
 *
 *  Created on: 04/09/2013
 *      Author: jonathan
 */

#include "Cuadrado.h"
#include <cmath>

Cuadrado::Cuadrado(float x, float y, float ancho, float alto): Figura(x,y) {
	this->ancho = ancho;
	this->alto = alto;
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

float Cuadrado::getAlto() const{
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
	if(this->getRotacion() != 0){
		//traslado al centro, roto el punto y pruebo el contacto.
		xc = posX - this->x;
		yc = posY - this->y;
		//roto
		double rotacionRad = this->getRotacion() *-3.14 /180.0;
		xc = (posX - this->x) * cos(rotacionRad)- (posY - this->y) * sin(rotacionRad);
		yc = (posX - this->x) * sin(rotacionRad)+ (posY - this->y) * cos(rotacionRad);
		xc =xc + this->x;
		yc=yc + this->y;
	}

	return this->isAdentro1D(xc, this->x, this->ancho)
			&& this->isAdentro1D(yc, this->y, this->alto);
}

bool Cuadrado::contieneCentro(Posicionable* posicion) {
	return this->contacto(posicion->getX(), posicion->getY());
}
bool Cuadrado::isAdentro1D(float pos, float posCentro, float ancho) {
	return (pos <= (posCentro + ancho / 2)) && (pos >= posCentro - ancho / 2);

}

