/*
 * Enganche.cpp
 *
 *  Created on: Oct 5, 2013
 *      Author: matias
 */

#include "Enganche.h"

Enganche::Enganche(float posX, float posY) {
	this->pos = b2Vec2(posX,posY);
	this->ocupado = false;
}

Enganche::~Enganche() {
	// TODO Auto-generated destructor stub
}

float Enganche::getPosX() {
	return this->pos.x;
}

float Enganche::getPosY() {
	return this->pos.y;
}

bool Enganche::estaOcupado() {
	return this->ocupado;
}

void Enganche::ocupar() {
	this->ocupado = true;
}

void Enganche::liberar() {
	this->ocupado = false;
}

b2Vec2& Enganche::getPos() {
	return this->pos;
}
