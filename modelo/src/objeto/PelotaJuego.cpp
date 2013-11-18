/*
 * PelotaJuego.cpp
 *
 *  Created on: 28/09/2013
 *      Author: jonathan
 */

#include "PelotaJuego.h"
#include "../Constantes.h"
#include <iostream>
PelotaJuego::PelotaJuego(float x, float y, float radio) :
		Objeto(x, y) {
	this->radio = radio;
}

PelotaJuego::~PelotaJuego() {
	// TODO Auto-generated destructor stub
}

void PelotaJuego::crearFisica() {
	float x = this->getX();
	float y = this->getY();
	b2Vec2 centro(x, y);
	b2CircleShape shapeCircle;

	b2BodyDef bodyDef;
	bodyDef.type = b2_dynamicBody;
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

void PelotaJuego::acept(VisitorFigura* visitor) {
	visitor->visit(this);
}

PelotaJuego::PelotaJuego(const PelotaJuego& figura) {
	this->x = figura.getX();
	this->y = figura.getY();
	this->setRotacion(figura.getRotacion());
	this->setRadio(figura.getRadio());
	this->reg = figura.reg;
}

PelotaJuego::PelotaJuego() {
	this->radio = 0;
}

float PelotaJuego::getRadio() const {
	return radio;
}

void PelotaJuego::setRadio(float radio) {
	this->radio = radio;
}

void PelotaJuego::recibirImpacto(b2Vec2 direccion) {
//	b2Vec2 centro(this->getX(), this->getY());
//	b2Vec2 versor = (centro - direccion);
//	float modulo = (centro - direccion).Length();
//	versor.x = versor.x / modulo;
//	versor.y = versor.y / modulo;
//	this->body->ApplyLinearImpulse(7500*versor, b2Vec2(this->getX(), this->getY()));
	this->realizarImpacto(direccion);
}
