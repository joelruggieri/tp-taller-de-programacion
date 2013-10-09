/*
 * CintaTransportadora.cpp
 *
 *  Created on: 05/10/2013
 *      Author: javier
 */

#include <Box2D/Box2D.h>
#include "CintaTransportadora.h"

#define DEGTORAD 0.0174532925199432957f
#define RADTODEG 57.295779513082320876f
#define RADIO (4.9f)

CintaTransportadora::CintaTransportadora(): Objeto (0,0) {
	this->longitud = 20;
	this->alto = 2*RADIO;
	this->ancho=this->longitud;
}

CintaTransportadora::~CintaTransportadora() {
	this->mundo->DestroyBody(ruedas[0]);
	this->mundo->DestroyBody(ruedas[1]);
	this->mundo->DestroyBody(ruedas[2]);
	this->mundo->DestroyBody(ruedas[3]);
}

void CintaTransportadora::crearFisica(b2World* m_world) {
	this->mundo = m_world;
	// ruedas
	b2BodyDef myBodyDef;
	myBodyDef.type = b2_kinematicBody;
	myBodyDef.position.Set(getX(), getY()); //<----posicion del modelo
	myBodyDef.angle = 0;

	// rueda izq
	ruedas[0] = m_world->CreateBody(&myBodyDef);
	// rueda derecha
	myBodyDef.position.Set(getX() + 2*RADIO, getY());
	ruedas[1] = m_world->CreateBody(&myBodyDef);
	// rueda derecha
	myBodyDef.position.Set(getX() + 4*RADIO, getY());
	ruedas[2] = m_world->CreateBody(&myBodyDef);
	// rueda derecha
	myBodyDef.position.Set(getX() + 6*RADIO, getY());
	ruedas[3] = m_world->CreateBody(&myBodyDef);

	ruedas[0]->SetAngularVelocity( 360 * DEGTORAD );
	ruedas[1]->SetAngularVelocity( 360 * DEGTORAD );
	ruedas[2]->SetAngularVelocity( 360 * DEGTORAD );
	ruedas[3]->SetAngularVelocity( 360 * DEGTORAD );

	b2CircleShape circleShape;
	circleShape.m_p.Set(0, 0);
	circleShape.m_radius = RADIO;
	b2FixtureDef myFixtureDef;
	myFixtureDef.shape = &circleShape;
	myFixtureDef.friction=1;
	myFixtureDef.density = 1;

	ruedas[0]->CreateFixture(&myFixtureDef);
	ruedas[1]->CreateFixture(&myFixtureDef);
	ruedas[2]->CreateFixture(&myFixtureDef);
	ruedas[3]->CreateFixture(&myFixtureDef);

	ruedas[0]->SetUserData(this);
	ruedas[1]->SetUserData(this);
	ruedas[2]->SetUserData(this);
	ruedas[3]->SetUserData(this);

	this->setBody(ruedas[0]);
}

void CintaTransportadora::acept(VisitorFigura* visitor) {
	visitor->visit(this);
}

CintaTransportadora::CintaTransportadora(int x, int y, int longitud) : Objeto(x,y) {
	this->longitud = longitud;
	this->ancho = longitud;
	this->alto = 2*RADIO;
}


CintaTransportadora::CintaTransportadora(const CintaTransportadora& figura):Objeto(x,y) {
	this->longitud = longitud;
	this->ancho = longitud;
	this->alto = 2*RADIO;
	this->reg = figura.reg;
}

int CintaTransportadora::getLongitud() const{
	return longitud;
}

void CintaTransportadora::setLongitud(int longitud) {
	this->longitud = longitud;
}
