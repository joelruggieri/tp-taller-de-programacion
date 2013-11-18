/*
 * Bomba.cpp
 *
 *  Created on: 17/11/2013
 *      Author: ezequiel
 */

#include "Bomba.h"
#include "../Constantes.h"
Bomba::Bomba() {
this->radio = 0;
}

Bomba::Bomba(const Bomba& figura) {
	this->x = figura.getX();
	this->y = figura.getY();
	this->setRotacion(figura.getRotacion());
	this->setRadio(figura.getRadio());
	this->reg = figura.reg;
}

Bomba::Bomba(float x, float y, float radio) : Objeto(x,y) {
	this->radio = radio;
}

void Bomba::crearFisica() {
	float x = this->getX();
		float y = this->getY();
		b2Vec2 centro(x, y);
		b2CircleShape shapeCircle;

		b2BodyDef bodyDef;
		bodyDef.type = b2_staticBody;
		bodyDef.position.Set(centro.x, centro.y);
		bodyDef.angle = this->getRotacion() * -3.14 / 180.0;
		b2Body* body = myWorld->CreateBody(&bodyDef);
		shapeCircle.m_radius = this->radio;
		b2FixtureDef bodyPelota;
		bodyPelota.filter.categoryBits = CATEGORIA_FIGURAS;
		bodyPelota.filter.maskBits = CATEGORIA_FIGURAS;
		bodyPelota.shape = &shapeCircle;
		bodyPelota.density = 10.0f;
		bodyPelota.friction = 0.3f;
		bodyPelota.restitution = 0.6f;	//mucho coeficiente de restitucion
		body->CreateFixture(&bodyPelota)->SetUserData(this);
	//		b2MassData masa;
	//		masa.mass = 50.0f; //chequear la cantidad de masa
	//		masa.I = 0.04; // chequear inercia rotacional
	//		body->SetMassData(&masa);	//centro de masa esta en el centro de la esfera por defecto
		body->SetUserData(this);
		this->setBody(body);
}

void Bomba::acept(VisitorFigura* v) {
	v->visit(this);
}

Bomba::~Bomba() {
	// TODO Auto-generated destructor stub
}

float Bomba::getRadio() const {
	return radio;
}

void Bomba::setRadio(float radio) {
	this->radio = radio;
}
