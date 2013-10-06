/*
 * Enganche.cpp
 *
 *  Created on: Oct 5, 2013
 *      Author: matias
 */

#include "Enganche.h"

Enganche::Enganche(int posX, int posY) {
	this->posX = posX;
	this->posY = posY;
	this->ocupado = false;
}

Enganche::~Enganche() {
	// TODO Auto-generated destructor stub
}

int Enganche::getPosX(){ return this->posX;}

int Enganche::getPosY(){return this->posY;}

bool Enganche::estaOcupado(){return this->ocupado;}

void Enganche::ocupar(){ this->ocupado = true;}

void Enganche::liberar(){this->ocupado = false;}
