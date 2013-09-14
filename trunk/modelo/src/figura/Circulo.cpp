/*
 * Circulo.cpp
 *
 *  Created on: 04/09/2013
 *      Author: jonathan
 */

#include "Circulo.h"
#include "VisitorFigura.h"

Circulo::Circulo() {
	// TODO Auto-generated constructor stub
}

Circulo::Circulo(float x, float y, float radio) {
	this->x = x;
	this->y = y;
	this->radio = radio;

}

float Circulo::getRadio() const {
	return radio;
}

void Circulo::setRadio(float radio) {
	this->radio = radio;
}

Circulo::~Circulo() {
	// TODO Auto-generated destructor stub
}

bool Circulo::contacto(float x, float y) {
	float cx = this->getX();
	float cy = this->getY();

	//Distancia al punto
	float SqrDist = ((cx - x) * (cx - x)) + ((cy - y) * (cy - y));
	float SqrRadius = radio * radio;
	return (SqrDist <= SqrRadius);
}

bool Circulo::contieneCentro(Posicionable* cuadrado) {
	return false;
}

void Circulo::acept(VisitorFigura* visitor) {
	visitor->visit(this);
}
