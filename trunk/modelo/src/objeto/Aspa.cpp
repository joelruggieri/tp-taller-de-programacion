/*
 6 * Aspa.cpp
 *
 *  Created on: 17/11/2013
 *      Author: joel
 */

#include "Aspa.h"
#include <math.h>
#include "../Constantes.h"
#define DEGTORAD 0.0174532925199432957f
Aspa::Aspa() :
		Objeto() {
	alto = 0;
	ancho = 0;
	numeroAspa = 0;
	tijera = NULL;

}

Aspa::Aspa(float x, float y, float ancho, float alto, double rotacion, int numero, Tijera* tijera) :
		Objeto(x, y) {
	this->ancho = ancho;
	this->alto = alto;
	this->rotacion = rotacion;
	this->numeroAspa = numero;
	this->tijera = tijera;
	this->numeroJugadorDuenio = tijera->getNumeroJugador();
	//Enganche* enganche= new Enganche(this,cos(rotacionEnRadianes)*ancho/2.0,sin(rotacionEnRadianes)*ancho/2.0);
	//enganches.push_back(enganche);
}

Aspa::~Aspa() {

}

float Aspa::getAlto() const {
	return this->alto;
}

float Aspa::getAncho() const {
	return this->ancho;
}

void Aspa::setAlto(float alto) {
	this->alto = alto;
}

void Aspa::setAncho(float ancho) {
	this->ancho = ancho;
}

void Aspa::crearFisica() {
	float x = this->getX();
	float y = this->getY();
	b2Vec2 centro(x, y);

	b2BodyDef bodyDef;
	bodyDef.type = b2_dynamicBody;
	bodyDef.position.Set(x, y);
//	bodyDef.angularDamping=1.0;
//	bodyDef.gravityScale = 0;
	//bodyDef.fixedRotation = true;
	double rotacionRad = this->getRotacion()*-1 * b2_pi / 180.0;
	bodyDef.angle = rotacionRad;
	b2Body* bodyAspa = myWorld->CreateBody(&bodyDef);
	bodyAspa->SetUserData(this->tijera);
	this->setBody(bodyAspa);
	crearShapes();
	b2RevoluteJointDef rjd;
	rjd.bodyA = ground;
	rjd.bodyB = bodyAspa;
	rjd.collideConnected = false;
	rjd.enableLimit = true;
	rjd.localAnchorA = b2Vec2(x,y);
	rjd.localAnchorB = b2Vec2_zero;


//	aspa1 = new Aspa(x, y,ancho, alto,-35,1,this);
//	aspa2 = new Aspa(x,y, ancho,alto,35,2,this);

	rjd.referenceAngle = 0;
	if (numeroAspa == 1) {
		rjd.lowerAngle = 36 * b2_pi / 180.0;
		rjd.upperAngle = 0;
	} else {
		rjd.lowerAngle = -36 * b2_pi / 180.0;
		rjd.upperAngle = 0;
	}

	this->jointCuerpoTierra = (b2RevoluteJoint*) myWorld->CreateJoint(&rjd);
}

b2RevoluteJoint* Aspa::getJoint() {
	return this->jointCuerpoTierra;

}

void Aspa::crearFisicaEstaticaTemplate(b2World * w, b2Body* ground) {
	float x = this->getX();
	float y = this->getY();
	b2Vec2 centro(x, y);

	b2BodyDef bodyDef;
	bodyDef.type = b2_staticBody;
	bodyDef.position.Set(x, y);
	bodyDef.fixedRotation = true;

	double rotacionRad = this->getRotacion() * -3.14 / 180.0;
	bodyDef.angle = rotacionRad;
	b2Body* body = w->CreateBody(&bodyDef);
//	body->CreateFixture(&fixture);
	body->SetUserData(this->tijera);
	this->setBody(body);
	crearShapes();

}

void Aspa::acept(VisitorFigura*) {

}

void Aspa::crearShapes() {
	b2PolygonShape polygon;
		b2FixtureDef fixture;
	polygon.SetAsBox(this->ancho / 2, this->alto / 2);
	fixture.filter.categoryBits = CATEGORIA_FIGURAS;
	fixture.filter.maskBits = CATEGORIA_FIGURAS;
	fixture.density = 10.00f;
	fixture.shape = &polygon;
	fixture.friction = 0.01f;
	fixture.restitution = 0.00f;
	body->CreateFixture(&fixture);
//	float mitadAncho =ancho/2.0;
//	float mitadAlto =alto/2.0;
//	b2Vec2 vertices[6];
//	vertices[0].Set(-mitadAncho, mitadAlto);
//	vertices[1].Set(-mitadAncho, -mitadAlto);
//	vertices[2].Set(0, -mitadAlto);
//	vertices[3].Set(mitadAncho*0.45, -alto/4.0);
//	vertices[4].Set(mitadAncho, -alto/4.0);
//	vertices[5].Set(mitadAncho, alto/2.0);
//	b2PolygonShape polygon;
//	polygon.Set(vertices, 6);
//	b2FixtureDef fixture;
//	fixture.filter.categoryBits = CATEGORIA_FIGURAS;
//	fixture.filter.maskBits = CATEGORIA_FIGURAS;
//	fixture.density = 2.00f;
//	fixture.shape = &polygon;
//	fixture.friction = 0.01f;
//	fixture.restitution = 0.00f;
//	body->CreateFixture(&fixture);
//
//
//	b2CircleShape shapeCircle;
//	shapeCircle.m_radius = mitadAlto;
//	shapeCircle.m_p.Set(mitadAncho - mitadAlto, mitadAlto);
//	fixture.shape= &shapeCircle;
//	body->CreateFixture(&fixture);
}
