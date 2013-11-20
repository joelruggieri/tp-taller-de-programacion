/*
 * Bomba.cpp
 *
 *  Created on: 17/11/2013
 *      Author: ezequiel
 */

#include "Bomba.h"
#include "../Constantes.h"
#include "../interaccion/ValidadorEnArea.h"
#include <iostream>
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

Bomba::Bomba(float x, float y, float radio) : Objeto(x,y, new ValidadorEnArea(this)) {
	this->radio = radio;
}

void Bomba::crearFisica() {
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
		bodyPelota.density = 1.0f;
		bodyPelota.friction = 0.3f;
		bodyPelota.restitution = 0.6f;	//mucho coeficiente de restitucion
		body->CreateFixture(&bodyPelota)->SetUserData(this);
	//		b2MassData masa;
	//		masa.mass = 50.0f; //chequear la cantidad de masa
	//		masa.I = 0.04; // chequear inercia rotacional
	//		body->SetMassData(&masa);	//centro de masa esta en el centro de la esfera por defecto
		body->SetUserData(this);
		this->setBody(body);

//		crearFisicaRadio(centro);
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

void Bomba::accionar() {
	crearFisicaRadio(b2Vec2(this->getX(), this->getY()));
	for (b2Body* b = myWorld->GetBodyList(); b; b = b->GetNext()) {
		if (b!= this->body && b!= this->radioAccion && b->GetFixtureList()!= NULL && b->GetFixtureList()->GetShape() != NULL) {
//			//solo da que si cuando golpea con otro radio de accion
			if (validarContactoBomba(this->radioAccion, b)) {
				Figura* fig = (Figura*)b->GetUserData();
				fig->recibirImpacto(b2Vec2(this->getX(), this->getY()));
			}

		}
	}
	notify(DESACTIVADO);
	myWorld->DestroyBody(this->getBody());
	myWorld->DestroyBody(this->radioAccion);
	viva = false;
}

void Bomba::crearFisicaRadio(b2Vec2 centro) {

	//definicion cuerpo radio de accion

	b2CircleShape shapeAccion;
	shapeAccion.m_radius = this->radio + 20.0;
	b2FixtureDef fixtureAccion;
	fixtureAccion.filter.categoryBits = CATEGORIA_RANGO_BOMBA;
	fixtureAccion.filter.maskBits = CATEGORIA_RANGO_BOMBA;
	fixtureAccion.density = 1.00f;
	fixtureAccion.shape = &shapeAccion;
	fixtureAccion.friction = 0.01f;
	fixtureAccion.restitution = 0.00f;
	b2BodyDef bodyDefAccion;
	bodyDefAccion.type = b2_dynamicBody;
	bodyDefAccion.position = centro;
	radioAccion = myWorld->CreateBody(&bodyDefAccion);
	radioAccion->CreateFixture(&fixtureAccion);
	radioAccion->SetUserData(this);

	//joint radio de accion con la tierra;
	b2RevoluteJointDef rjd2;
	rjd2.Initialize(this->body, radioAccion, centro);
	rjd2.collideConnected = false;
	myWorld->CreateJoint(&rjd2);
}

bool Bomba::validarContactoBomba(b2Body* verf, b2Body* b) {
	return b2TestOverlap(verf->GetFixtureList()->GetShape(), 0, b->GetFixtureList()->GetShape(), 0,
				verf->GetTransform(), b->GetTransform());
}

void Bomba::interactuar(Area& area, int jugador) {
	super::interactuarNoArea(area,jugador);
}

void Bomba::recibirImpacto(b2Vec2 direccion) {
	this->realizarImpacto(direccion);
}
