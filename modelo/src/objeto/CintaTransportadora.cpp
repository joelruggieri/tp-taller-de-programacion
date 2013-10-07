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
#define RADIO (3.0f)

CintaTransportadora::CintaTransportadora(): Objeto (0,0) {
	this->longitud = 20;
	this->alto = 2*RADIO;
	this->ancho=this->longitud;
}

CintaTransportadora::~CintaTransportadora() {
	// TODO Auto-generated destructor stub
}

void CintaTransportadora::crearFisica(b2World* m_world) {
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
	circleShape.m_radius = 3;
	b2FixtureDef myFixtureDef;
	myFixtureDef.shape = &circleShape;
	myFixtureDef.friction=1;
	myFixtureDef.density = 1;

	ruedas[0]->CreateFixture(&myFixtureDef);
	ruedas[1]->CreateFixture(&myFixtureDef);

	myBodyDef.type = b2_dynamicBody;

	b2PolygonShape boxShape;
	boxShape.SetAsBox(1, 0.25); // semi-dimensiones de la pieza

	b2FixtureDef boxFixtureDef;
	boxFixtureDef.shape = &boxShape;
	boxFixtureDef.density = 1;

	b2RevoluteJointDef revoluteJointDef;
	revoluteJointDef.localAnchorA.Set( 1,0);
	revoluteJointDef.localAnchorB.Set(-1,0);
	b2Body *ant=NULL;
	for (int i=0; i<PIEZAS; ++i) {
		if (i==0){
			myBodyDef.angle=45*DEGTORAD;
			myBodyDef.position.Set(-RADIO + getX(),RADIO + getY());
		} else if (i>0 && i < (PIEZAS/2-1)) {
			myBodyDef.angle=0;
			myBodyDef.position.Set(i*longitud/(PIEZAS/2.0f-3) - longitud/(PIEZAS/2.0f-3) + getX(),(RADIO+1) + getY());
		} else if (i==PIEZAS/2-1) {
			myBodyDef.angle=-45*DEGTORAD;
			myBodyDef.position.Set(longitud+RADIO+getX(), RADIO+getY());
		} else if(i==PIEZAS/2){
			myBodyDef.angle=-90*DEGTORAD;
			myBodyDef.position.Set(longitud+RADIO+1 + getX() ,0 + getY());
		} else if(i==(PIEZAS/2+1)){
			myBodyDef.angle=-135*DEGTORAD;
			myBodyDef.position.Set(longitud+RADIO+getX(), -RADIO+getY());
		} else if (i>(PIEZAS/2+1) && i < (PIEZAS-2)) {
			myBodyDef.angle=-180*DEGTORAD;
			myBodyDef.position.Set(-i*longitud/(PIEZAS/2.0f-5.0f) + (longitud*(1.0f-3.0f/PIEZAS)/(0.5f-5.0f/PIEZAS)) + getX(), -RADIO-1.0f + getY());
		} else if (i == (PIEZAS-2)) {
			myBodyDef.angle=-225*DEGTORAD;
			myBodyDef.position.Set(-RADIO+getX(), -RADIO+getY());
		} else {
			myBodyDef.angle=-270*DEGTORAD;
			myBodyDef.position.Set(-RADIO-1 + getX(), 0 + getY());
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



}

void CintaTransportadora::acept(VisitorFigura* visitor) {
	visitor->visit(this);
}

CintaTransportadora::CintaTransportadora(int x, int y, int longitud) : Objeto(x,y) {
	this->longitud = longitud;
	this->ancho = longitud;
	this->alto = 2*RADIO;
}

int CintaTransportadora::getLongitud() const{
	return longitud;
}

void CintaTransportadora::setLongitud(int longitud) {
	this->longitud = longitud;
}
