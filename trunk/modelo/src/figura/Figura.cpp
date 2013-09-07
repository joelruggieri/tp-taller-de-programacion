
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

float Figura::getRotacion() const {
	return rotacion;
}

void Figura::setX(float x){
	this->x = x;
}

void Figura::setY(float y){
	this->y = y;
}

void Figura::setRotacion(float rotation){
	this->rotacion = rotation;
}

Figura::Figura() {
	x= 0;
	y=0;
}

Figura::~Figura() {
}
