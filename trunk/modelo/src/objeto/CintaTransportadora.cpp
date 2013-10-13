/*
 * CintaTransportadora.cpp
 *
 *  Created on: 05/10/2013
 *      Author: javier
 */

#include <Box2D/Box2D.h>
#include "CintaTransportadora.h"
#include "../Constantes.h"

#define DEGTORAD 0.0174532925199432957f
#define RADTODEG 57.295779513082320876f


CintaTransportadora::CintaTransportadora(): Objeto (0,0) {
	this->longitud = LONGITUD_CINTA;
	ruedas[0] = NULL;
	ruedas[1]=NULL;
	base = NULL;
	cuerpo = NULL;
	mundo = NULL;
	cantPiezas=longitud+7;
}

CintaTransportadora::~CintaTransportadora() {

}

void CintaTransportadora::crearFisica(b2World* m_world, b2Body * ground) {
	this->mundo = m_world;

	// Corro el centro de la vista porque en TestBed programe las posiciones
	// de las piezas haciendo referencia a la rueda izquierda.
	this->setX(getX()-longitud/2);

	// ruedas
	b2BodyDef myBodyDef;
	myBodyDef.type = b2_kinematicBody;
	myBodyDef.position.Set(getX(), getY()); //<----posicion del modelo
	myBodyDef.angle = 0;

	// rueda izq
	ruedas[0] = m_world->CreateBody(&myBodyDef);

	// rueda derecha
	myBodyDef.position.Set(getX() + longitud, getY());
	ruedas[1] = m_world->CreateBody(&myBodyDef);

	ruedas[0]->SetAngularVelocity( 360 * DEGTORAD );
	ruedas[1]->SetAngularVelocity( 360 * DEGTORAD );

	b2CircleShape circleShape;
	circleShape.m_p.Set(0, 0);
	circleShape.m_radius = RADIO_EJE_CINTA;
	b2FixtureDef myFixtureDef;
	myFixtureDef.shape = &circleShape;
	myFixtureDef.friction=1;
	myFixtureDef.density = 1;

	ruedas[0]->CreateFixture(&myFixtureDef);
	ruedas[1]->CreateFixture(&myFixtureDef);

	// Cuerpo de la cinta
	myBodyDef.type = b2_staticBody;
	myBodyDef.position.Set(getX()+longitud/2, getY());
	cuerpo = m_world->CreateBody(&myBodyDef);

	b2PolygonShape boxShape;
	boxShape.SetAsBox((longitud-2*RADIO_EJE_CINTA)/2*0.99, RADIO_EJE_CINTA * 0.95f);
	b2FixtureDef boxFixtureDef;
	boxFixtureDef.friction=0;
	boxFixtureDef.shape = &boxShape;
	boxFixtureDef.density = 5;
	cuerpo->CreateFixture(&boxFixtureDef);

	// Base
	myBodyDef.position.Set(getX()+longitud/2, getY() - RADIO_EJE_CINTA - 0.85);
	base = m_world->CreateBody(&myBodyDef);
	boxShape.SetAsBox(longitud/2, 0.25f);
	boxFixtureDef.friction=0;
	boxFixtureDef.shape = &boxShape;
	boxFixtureDef.density = 5;
	base->CreateFixture(&boxFixtureDef);


	// piezas de la cinta
	myBodyDef.type = b2_dynamicBody;
	boxShape.SetAsBox(1, 0.20); // semi-dimensiones de la pieza

	boxFixtureDef.friction=1;
	boxFixtureDef.density = 1;

	b2RevoluteJointDef revoluteJointDef;
	revoluteJointDef.localAnchorA.Set( 1,0);
	revoluteJointDef.localAnchorB.Set(-1,0);
	b2Body *ant=NULL;
	cantPiezas = ((int)(longitud+1))+7; // Casteo hacia arriba de la longitud
	piezas.clear();
	for (int i=0; i <cantPiezas;++i){
		piezas.push_back(NULL);
	}
	for (int i=0; i<cantPiezas; ++i) {
		if (i==0){
			myBodyDef.angle=45*DEGTORAD;
			myBodyDef.position.Set(-RADIO_EJE_CINTA + getX(),RADIO_EJE_CINTA + getY());
		} else if (i>0 && i < (cantPiezas/2-1)) {
			myBodyDef.angle=0;
			myBodyDef.position.Set(i*longitud/(cantPiezas/2.0f-3) - longitud/(cantPiezas/2.0f-3) + getX(),(RADIO_EJE_CINTA+0.1) + getY());
		} else if (i==cantPiezas/2-1) {
			myBodyDef.angle=-45*DEGTORAD;
			myBodyDef.position.Set(longitud+RADIO_EJE_CINTA+getX(), RADIO_EJE_CINTA+getY());
		} else if(i==cantPiezas/2){
			myBodyDef.angle=-90*DEGTORAD;
			myBodyDef.position.Set(longitud+RADIO_EJE_CINTA+0.1 + getX() ,0 + getY());
		} else if(i==(cantPiezas/2+1)){
			myBodyDef.angle=-135*DEGTORAD;
			myBodyDef.position.Set(longitud+RADIO_EJE_CINTA+getX(), -RADIO_EJE_CINTA+getY());
		} else if (i>(cantPiezas/2+1) && i < (cantPiezas-2)) {
			myBodyDef.angle=-180*DEGTORAD;
			myBodyDef.position.Set(-i*longitud/(cantPiezas/2.0f-5.0f) + (longitud*(1.0f-3.0f/cantPiezas)/(0.5f-5.0f/cantPiezas)) + getX(), -RADIO_EJE_CINTA-0.1 + getY());
		} else if (i == (cantPiezas-2)) {
			myBodyDef.angle=-225*DEGTORAD;
			myBodyDef.position.Set(-RADIO_EJE_CINTA+getX(), -RADIO_EJE_CINTA+getY());
		} else {
			myBodyDef.angle=-270*DEGTORAD;
			myBodyDef.position.Set(-RADIO_EJE_CINTA-0.1 + getX(), 0 + getY());
		}
		piezas[i] = m_world->CreateBody(&myBodyDef);
		piezas[i]->CreateFixture(&boxFixtureDef);
		if (ant==NULL) {
			ant = piezas[0];
		} else {
			revoluteJointDef.bodyA = ant;
			revoluteJointDef.bodyB = piezas[i];
			m_world->CreateJoint( &revoluteJointDef );
			ant = piezas[i];
		}
	}
	myBodyDef.angle=0;
	revoluteJointDef.bodyA = ant;
	revoluteJointDef.bodyB = piezas[0];
	m_world->CreateJoint( &revoluteJointDef );
	cuerpo->SetUserData(this);
	this->setBody(cuerpo);
	this->setX(getX()+longitud/2);
}

void CintaTransportadora::acept(VisitorFigura* visitor) {
	visitor->visit(this);
}

CintaTransportadora::CintaTransportadora(int x, int y, int longitud) : Objeto(x,y) {
	this->longitud = longitud;
	cuerpo = NULL;
	mundo = NULL;
	base = NULL;
	cantPiezas = longitud+7;
}


CintaTransportadora::CintaTransportadora(const CintaTransportadora& figura):Objeto(x,y) {
	this->longitud = figura.longitud;
	this->reg = figura.reg;
	this->cuerpo = figura.cuerpo;
	this->base = figura.base;
	this->mundo = figura.mundo;
	this->cantPiezas = figura.cantPiezas;
}

int CintaTransportadora::getLongitud() const{
	return longitud;
}

void CintaTransportadora::setLongitud(int longitud) {
	this->longitud = longitud;
}

void CintaTransportadora::crearFisicaEstaticaTemplate(b2World* m_world,
		b2Body* ground) {
	b2PolygonShape * polygon = new b2PolygonShape();

	b2MassData masa;
	polygon->SetAsBox(longitud/2, RADIO_EJE_CINTA);

	b2FixtureDef fixture;
	fixture.shape = polygon;
	fixture.filter.categoryBits = CATEGORIA_FIGURAS;
	b2BodyDef bodyDef;
	bodyDef.position.Set(x, y);

	b2Body* body = m_world->CreateBody(&bodyDef);
	body->CreateFixture(&fixture);
	setBody(body);
	body->SetUserData(this);
}

