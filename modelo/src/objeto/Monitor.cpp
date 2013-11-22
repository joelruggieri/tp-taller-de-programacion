/*
 * Monitor.cpp
 *
 *  Created on: 21/11/2013
 *      Author: ezequiel
 */

#include "Monitor.h"
#include "../Constantes.h"
Monitor::Monitor(float x, float y, float w, float h) :
		Objeto(x, y) {
	this->ancho = w;
	this->alto = h;
}

Monitor::~Monitor() {
	// TODO Auto-generated destructor stub
}

bool Monitor::crearFisicaEstatica() {
	return false;
}

void Monitor::crearFisica() {
	float x = this->getX();
	float y = this->getY();
	b2Vec2 centro(x, y);
	b2PolygonShape shape;
	shape.SetAsBox(this->ancho / 2, this->alto / 2);
	b2BodyDef bodyDef;
	bodyDef.type = b2_staticBody;
	bodyDef.position.Set(centro.x, centro.y);
	bodyDef.angle = this->getRotacion() * -3.14 / 180.0;
	b2Body* body = myWorld->CreateBody(&bodyDef);
	b2FixtureDef bodyMonitor;
	bodyMonitor.filter.categoryBits = CATEGORIA_MONITOR;
	bodyMonitor.filter.maskBits = CATEGORIA_MONITOR;
	bodyMonitor.density = 10.0f;
	bodyMonitor.shape = &shape;
	body->CreateFixture(&bodyMonitor)->SetUserData(this);
	body->SetUserData(this);
	this->setBody(body);
}

void Monitor::acept(VisitorFigura*) {
}

void Monitor::setFiguraEsperada(Figura* f) {
	this->figuraEsperada = f;
}

void Monitor::contactar(Figura* f) {
	if (this->figuraEsperada == f) {
		//Esto llama a los observers y les pasa el evento ACCIONADO en la implementacion de la madre.
		accionar();
	}
}
