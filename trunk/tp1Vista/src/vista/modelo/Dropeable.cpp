/*
 * Dropeable.cpp
 *
 *  Created on: 29/08/2013
 *      Author: jonathan
 */

#include "Dropeable.h"

Dropeable::Dropeable(string modelo) {
	this->modelo = modelo;
}

Dropeable::~Dropeable() {
	// TODO Auto-generated destructor stub
}

float Dropeable::getPosX() const {
	return this->posX;
}

void Dropeable::setPosX(float posX) {
	this->posX = posX;
}

float Dropeable::getPosY() const {
	return this->posY;
}

void Dropeable::setPosY(float posY) {
	this->posY = posY;
}

string Dropeable::getModelo() {
	return this->modelo;
}
