/*
 * Circulo.cpp
 *
 *  Created on: 04/09/2013
 *      Author: jonathan
 */

#include "Circulo.h"

Circulo::Circulo(){
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

void Circulo::setRadio(float radio){
	this->radio = radio;
}

Circulo::~Circulo() {
	// TODO Auto-generated destructor stub
}

bool Circulo::contacto(float float1, float float2) {
	return true;
}

bool Circulo::contieneCentro(Figura* cuadrado) {
	return true;
}
