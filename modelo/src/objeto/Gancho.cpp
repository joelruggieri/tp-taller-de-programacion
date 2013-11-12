/*
 * Gancho.cpp
 *
 *  Created on: 12/11/2013
 *      Author: joel
 */

#include "Gancho.h"
#include "../Constantes.h"
Gancho::Gancho(): Objeto() {
	this->radio = 0;
}

Gancho::Gancho(float x,float y,float radio): Objeto(x,y){
	this->radio = radio;
	this->setRotacion(0);
	this->enganches.push_back(new Enganche(this,0,0));
}

Gancho::Gancho(const Gancho& figura){
	this->x = figura.getX();
	this->y = figura.getY();
	this->setRotacion(figura.getRotacion());
	this->setRadio(figura.getRadio());
	//this->reg = figura.reg;
	this->enganches.push_back(new Enganche(this,0,0));
}

Gancho::~Gancho() {
	// TODO Auto-generated destructor stub
}

void Gancho::crearFisica(){
	float x = this->getX();
	float y = this->getY();
	b2Vec2 centro(x, y);
	b2CircleShape shapeCircle;

	b2BodyDef bodyDef;
	bodyDef.type = b2_staticBody;
	bodyDef.position.Set(centro.x, centro.y);
	bodyDef.angle = this->getRotacion() * -3.14 / 180.0;
	bodyDef.fixedRotation = true;
	//bodyDef.linearDamping = 0.15;

	b2Body* body = myWorld->CreateBody(&bodyDef);
	shapeCircle.m_radius = this->radio;
	b2FixtureDef bodyGancho;
	bodyGancho.shape = &shapeCircle;
	bodyGancho.filter.categoryBits = CATEGORIA_FIGURAS;
	bodyGancho.filter.maskBits = CATEGORIA_FIGURAS;
	//bodyGancho.density = 1.0f;	//poca densidad, la densidad del aire cual es ?
	//bodyGancho.friction = 0.2f;
	//bodyGancho.restitution = 0.3f;
	body->CreateFixture(&bodyGancho)->SetUserData(this);
	body->SetUserData(this);
	this->setBody(body);
}

float Gancho::getRadio() const {
	return radio;
}

void Gancho::setRadio(float radio) {
	this->radio = radio;
}

void Gancho::acept(VisitorFigura* visitor) {
	visitor->visit(this);
}

