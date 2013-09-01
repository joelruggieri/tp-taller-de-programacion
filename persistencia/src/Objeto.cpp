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

float Objeto::getPosX() const {
	return posX;
}

float Objeto::getPosY() const {
	return posY;
}

void Objeto::setPosX(float posX) {
	this->posX = posX;
}

void Objeto::setPosY(float posY) {
	this->posY = posY;
}

bool Objeto::operator == (const Objeto &p) const
{
    return this->posX == p.posX && this->posY == p.posY;
}
