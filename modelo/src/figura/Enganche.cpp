/*
 * Enganche.cpp
 *
 *  Created on: Oct 5, 2013
 *      Author: matias
 */

#include "Enganche.h"
#include "Figura.h"
Enganche::Enganche(Figura * centro, float posX, float posY) {
	this->pos = b2Vec2(posX,posY);
	this->ocupado = false;
	this->centro = centro;
	requiereEslabon = false;
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

b2Vec2 Enganche::getWorldPos() {
	b2Vec2 centroVec(centro->getX(), centro->getY());
	double radianes = centro->gradosARadianes(centro->getRotacion());
	b2Rot rotacion(-1 * radianes);
	b2Vec2 rotado = b2Mul(rotacion, pos);
	return rotado + centroVec;
}

b2Body* Enganche::getBody() {
	return centro->getBody();
}

bool Enganche::getRequiereEslabon() {
	return requiereEslabon;
}

void Enganche::setRequiereEslabon(bool r) {
	requiereEslabon = r;

}
