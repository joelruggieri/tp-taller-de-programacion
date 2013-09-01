/*
 * Objeto.cpp
 *
 *  Created on: 31/08/2013
 *      Author: javier
 */

#include "Objeto.h"

Objeto::Objeto() {
	this->posX = 0;
	this->posY = 0;
}

Objeto::Objeto(float x, float y) {
	this->posX = x;
	this->posY = y;
}

Objeto::~Objeto() {
	// TODO Auto-generated destructor stub
}

float Objeto::getPosX() {
	return posX;
}

float Objeto::getPosY() {
	return posY;
}
