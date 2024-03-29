/*
 * Enganche.cpp
 *
 *  Created on: Oct 5, 2013
 *      Author: matias
 */

#include "Enganche.h"
#include "Figura.h"
#include "../objeto/Soga.h"
Enganche::Enganche(Figura * centro, float posX, float posY) {
	this->pos = b2Vec2(posX,posY);
	this->ocupado = false;
	this->centro = centro;
	requiereEslabon = false;
	eslabon= NULL;
	soga =NULL;
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

void Enganche::ocupar(Soga * s) {
	this->ocupado = true;
	soga = s;
}

void Enganche::liberar() {
	this->ocupado = false;
	eslabon = NULL;
	soga = NULL;
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

void Enganche::setEslabon(b2Body* b) {
	eslabon = b;
}

b2Body* Enganche::getEslabon() {
	return eslabon;
}

void Enganche::desprenderDeSoga() {
	if(soga){
		soga->desactivarJoint(this);
	}
}

void Enganche::desenganchado() {
	centro->desenganchado(this);

}

void Enganche::matarSoga() {
	soga->cortar(this);
}

Figura* Enganche::getFigura() {
	return centro;
}
