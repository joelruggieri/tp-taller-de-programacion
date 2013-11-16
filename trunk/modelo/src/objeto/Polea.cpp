/*
 * Polea.cpp
 *
 *  Created on: 28/09/2013
 *      Author: jonathan
 */

#include "Polea.h"
#include "../Constantes.h"
Polea::Polea(float x, float y, float radio) :
		Objeto(x, y) {
	this->radio = radio;
	Enganche * e = new Enganche(this,-radio,0);
	e->setRequiereEslabon(true);
	this->enganches.push_back(e);
	e = new Enganche(this,radio,0);
	e->setRequiereEslabon(true);
	this->enganches.push_back(e);
}

Polea::~Polea() {
}

void Polea::crearFisica() {
	float x = this->getX();
	float y = this->getY();
	b2Vec2 centro(x, y);
	b2CircleShape shapeCircle;
	b2BodyDef bodyDef;
	bodyDef.type = b2_staticBody;
	bodyDef.position.Set(centro.x, centro.y);
	bodyDef.angle = 0;
	bodyDef.fixedRotation = true;
	b2Body* body = myWorld->CreateBody(&bodyDef);
	shapeCircle.m_radius = this->radio;
	b2FixtureDef bodyGancho;
	bodyGancho.shape = &shapeCircle;
	bodyGancho.filter.categoryBits = CATEGORIA_FIGURAS;
	bodyGancho.filter.maskBits = CATEGORIA_FIGURAS;
	body->CreateFixture(&bodyGancho)->SetUserData(this);
	body->SetUserData(this);
	this->setBody(body);
}

void Polea::acept(VisitorFigura* visitor) {
	visitor->visit(this);
}

Polea::Polea(const Polea& figura) {
	this->x = figura.getX();
	this->y = figura.getY();
	this->setRotacion(figura.getRotacion());
	this->setRadio(figura.getRadio());
	this->reg = figura.reg;
	radio = figura.radio;
}

float Polea::getRadio() {
	return this->radio;
}

Polea::Polea() :
		Objeto() {
	this->radio = 0;
}

float Polea::getRadio() const {
	return radio;
}

void Polea::setRadio(float radio) {
	this->radio = radio;
}

