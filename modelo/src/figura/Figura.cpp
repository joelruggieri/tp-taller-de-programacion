
/*
 * Figura.cpp
 *
 *  Created on: 06/09/2013
 *      Author: jonathan
 */
#include "Figura.h"
float Figura::getX() const {
	return x;
}

float Figura::getY() const {
	return y;
}

double Figura::getRotacion() const {
	return rotacion;
}

void Figura::setX(float x){
	this->x = x;
}

void Figura::setY(float y){
	this->y = y;
}

void Figura::setRotacion(double rotation){
	this->rotacion = rotation;
	if(this->rotacion < 0){
		this->rotacion =  this->rotacion * -1;
		this->rotacion = 360 - (int)this->rotacion % 360;
	} else if(this->rotacion > 360){
		this->rotacion = (int)this->rotacion % 360;
	}
}

Figura::Figura() {
	x= 0;
	y=0;
	rotacion = 0;
	this->rotador = 0;
}

Figura::Figura(float x, float y, Rotador * rotador) {
	this->x = x;
	this->y = y;
	this->rotacion = 0;
	this->rotador = rotador;
}


Figura::~Figura() {
}

void Figura::setRotador(Rotador* rotador) {
	this->rotador = rotador;
}
