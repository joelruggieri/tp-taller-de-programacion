/*
 * Triangulo.cpp
 *
 *  Created on: 06/09/2013
 *      Author: jonathan
 */

#include "Triangulo.h"
#include <cmath>
#include "VisitorFigura.h"

Triangulo::Triangulo(float x, float y,Rotador * rotador, float ancho, float alto):Figura(x,y,rotador) {
	this->ancho = ancho;
	this->alto = alto;
}

Triangulo::Triangulo() {
	this->x = 0;
	this->y = 0;
	this->ancho = 1;
	this->alto = 1;
}

void Triangulo::setAlto(float alto) {
	this->alto = alto;

}

void Triangulo::setAncho(float ancho) {
	this->ancho = ancho;

}

float Triangulo::getAlto() const {
	return alto;

}

float Triangulo::getAncho() const {
	return ancho;

}
Triangulo::~Triangulo() {
	// TODO Auto-generated destructor stub
}

bool Triangulo::contacto(float posX, float posY) {
	double xc = posX;
	double yc = posY;
	if (this->getRotacion() != 0) {
		//traslado al centro, roto el punto y pruebo el contacto.
		xc = posX - this->x;
		yc = posY - this->y;
		//roto
		double rotacionRad = this->getRotacion() * -3.14 / 180.0;
		xc = (posX - this->x) * cos(rotacionRad)
				- (posY - this->y) * sin(rotacionRad);
		yc = (posX - this->x) * sin(rotacionRad)
				+ (posY - this->y) * cos(rotacionRad);
		xc = xc + this->x;
		yc = yc + this->y;
	}

	return this->isAdentro1D(xc, this->x, this->ancho)
			&& this->isAdentro1D(yc, this->y, this->alto);
}

bool Triangulo::contieneCentro(Posicionable* cuadrado) {
	return this->contacto(cuadrado->getX(), cuadrado->getY());
}
bool Triangulo::isAdentro1D(float pos, float posCentro, float ancho) {
	return (pos <= (posCentro + ancho / 2)) && (pos >= posCentro - ancho / 2);

}

void Triangulo::acept(VisitorFigura* visitor) {
	visitor->visit(this);
}
