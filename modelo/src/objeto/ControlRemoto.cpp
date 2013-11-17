/*
 * ControlRemoto.cpp
 *
 *  Created on: 17/11/2013
 *      Author: ezequiel
 */

#include "ControlRemoto.h"
#include "../Constantes.h"

ControlRemoto::ControlRemoto(const ControlRemoto&) {
	// TODO Auto-generated constructor stub

}

ControlRemoto::~ControlRemoto() {
	// TODO Auto-generated destructor stub
}

ControlRemoto::ControlRemoto() {
}

void ControlRemoto::crearFisica() {
	float x = this->getX();
	float y = this->getY();
	b2Vec2 centro(x,y);
	b2PolygonShape shape;
	shape.SetAsBox(this->ancho / 2, this->alto / 2);
	b2BodyDef bodyDef;
	bodyDef.type = b2_staticBody;
	bodyDef.position.Set(centro.x, centro.y);
	bodyDef.angle = this->getRotacion() * -3.14 / 180.0;
	b2Body* body = myWorld->CreateBody(&bodyDef);
	b2FixtureDef bodyControl ;
	bodyControl.filter.categoryBits = CATEGORIA_FIGURAS;
	bodyControl.filter.maskBits = CATEGORIA_FIGURAS;
	bodyControl.density = 10.0f ;
	bodyControl.shape = &shape;
	body->CreateFixture(&bodyControl);
	body->SetUserData(this);
	this->setBody(body);

}

void ControlRemoto::acept(VisitorFigura* visitor) {
	visitor->visit(this);
}

float ControlRemoto::getAlto() const {
	return alto;
}

void ControlRemoto::setAlto(float alto) {
	this->alto = alto;
}

float ControlRemoto::getAncho() const {
	return ancho;
}

ControlRemoto::ControlRemoto(float x, float y, float ancho, float alto) : Objeto(x,y) {
this->ancho = ancho ;
this->alto = alto ;
}

void ControlRemoto::setAncho(float ancho) {
	this->ancho = ancho;
}

