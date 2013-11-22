/*
 6 * Aspa.cpp
 *
 *  Created on: 17/11/2013
 *      Author: joel
 */

#include "Aspa.h"
#include <math.h>
#include "../Constantes.h"
#include "Densidades.h"
#define DEGTORAD 0.0174532925199432957f
Aspa::Aspa() :
		Objeto() {
	alto = 0;
	ancho = 0;
	numeroAspa = 0;
	tijera = NULL;
	switchContacto = NULL;
}

Aspa::Aspa(float x, float y, float ancho, float alto, double rotacion, int numero, Tijera* tijera) :
		Objeto(x, y) {
	this->ancho = ancho;
	this->alto = alto;
	this->rotacion = rotacion;
	this->numeroAspa = numero;
	this->tijera = tijera;
	this->numeroJugadorDuenio = tijera->getNumeroJugador();
	switchContacto = NULL;
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
	bodyDef.angularDamping = 2.0;
	bodyDef.gravityScale = 0;
	double rotacionRad = this->getRotacion() * -1 * b2_pi / 180.0;
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
	rjd.localAnchorA = centro;
	rjd.localAnchorB = b2Vec2_zero;
	rjd.referenceAngle = 0;
	if (numeroAspa == 1) {
		if (getRotacion() == -ANGULO_DEFECTO_ASPA) {
			rjd.upperAngle = ANGULO_DEFECTO_ASPA * b2_pi / 180.0;
			rjd.lowerAngle = 3 * b2_pi / 180.0;
		}
		if (getRotacion() == 90 - ANGULO_DEFECTO_ASPA) {
			rjd.upperAngle = (ANGULO_DEFECTO_ASPA - 90) * b2_pi / 180.0;
			rjd.lowerAngle = (3 - 90) * b2_pi / 180.0;
		}
		if (getRotacion() == 180 - ANGULO_DEFECTO_ASPA) {
			rjd.upperAngle = (ANGULO_DEFECTO_ASPA - 180) * b2_pi / 180.0;
			rjd.lowerAngle = (3 - 180) * b2_pi / 180.0;
		}
		if (getRotacion() == 270 - ANGULO_DEFECTO_ASPA) {
			rjd.upperAngle = (ANGULO_DEFECTO_ASPA - 270) * b2_pi / 180.0;
			rjd.lowerAngle = (3 - 270) * b2_pi / 180.0;
		}
		anguloTrabado = rjd.lowerAngle;
	} else {
		if (getRotacion() == ANGULO_DEFECTO_ASPA) {
			rjd.lowerAngle = -ANGULO_DEFECTO_ASPA * b2_pi / 180.0;
			rjd.upperAngle = -3 * b2_pi / 180.0;
			;
		}
		if (getRotacion() == 90 + ANGULO_DEFECTO_ASPA) {
			rjd.lowerAngle = (-90 - ANGULO_DEFECTO_ASPA) * b2_pi / 180.0;
			rjd.upperAngle = (-90 - 3) * b2_pi / 180.0;
			;
		}
		if (getRotacion() == 180 + ANGULO_DEFECTO_ASPA) {
			rjd.lowerAngle = (-180 - ANGULO_DEFECTO_ASPA) * b2_pi / 180.0;
			rjd.upperAngle = (-180 - 3) * b2_pi / 180.0;
			;
		}

		if (getRotacion() == 270 + ANGULO_DEFECTO_ASPA) {
			rjd.lowerAngle = (-270 - ANGULO_DEFECTO_ASPA) * b2_pi / 180.0;
			rjd.upperAngle = (-270 - 3) * b2_pi / 180.0;
			;
		}
		anguloTrabado = rjd.upperAngle;

	}

	this->jointCuerpoTierra = (b2RevoluteJoint*) myWorld->CreateJoint(&rjd);
	crearSwitch();
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

	double rotacionRad = this->getRotacion() * -1 * b2_pi / 180.0;
	bodyDef.angle = rotacionRad;
	b2Body* body = w->CreateBody(&bodyDef);
	body->SetUserData(this->tijera);
	this->setBody(body);
	crearShapes();
}

void Aspa::acept(VisitorFigura*) {

}

void Aspa::crearShapes() {
	//creo el cuerpo
	b2CircleShape shapeCircle;
	shapeCircle.m_radius = this->alto;
	b2Vec2 vertices[4];
	if (numeroAspa == 1) {
		//es La de la aleta para arriba.
		b2PolygonShape shape;
		vertices[0].Set(0, alto / 2.0);
		vertices[1].Set(0, 0);
		vertices[2].Set(ancho / 2.0, 0);
		vertices[3].Set(ancho / 2.0, alto / 2.0);
		shapeCircle.m_p.Set(ancho/2.0- alto,alto);
	} else {
		vertices[0].Set(0, 0);
		vertices[1].Set(0, -alto / 2.0);
		vertices[2].Set(ancho / 2.0, -alto / 2.0);
		vertices[3].Set(ancho / 2.0, 0);
		shapeCircle.m_p.Set(ancho/2- alto,-alto);
	}
	b2PolygonShape shapeMango;
	b2FixtureDef fixture;
	shapeMango.Set(vertices, 4);
	fixture.filter.categoryBits = CATEGORIA_FIGURAS;
	fixture.filter.maskBits = CATEGORIA_FIGURAS;
	fixture.density = DENSIDAD_ASPA;
	fixture.shape = &shapeMango;
	fixture.friction = 0.01f;
	fixture.restitution = 0.00f;
	body->CreateFixture(&fixture);

	b2PolygonShape shapeAspa;
	shapeAspa.SetAsBox(ancho/4.0, alto/2,b2Vec2(-ancho/4.0, 0),0);
	fixture.shape = &shapeAspa;
	body->CreateFixture(&fixture);

	fixture.shape = &shapeCircle;
	body->CreateFixture(&fixture);

	fixture.shape = &shapeCircle;

	body->CreateFixture(&fixture);
	//creo el ojal
//	b2FixtureDef bodyBolaBoliche;
//	bodyBolaBoliche.filter.categoryBits = CATEGORIA_FIGURAS;
//		bodyBolaBoliche.filter.maskBits = CATEGORIA_FIGURAS;
//	bodyBolaBoliche.shape = &shapeCircle;
//	bodyBolaBoliche.density = 10.0f;
//	bodyBolaBoliche.friction = 0.3f;
//	bodyBolaBoliche.restitution = 0.05;	//poco coeficiente de restitucion
//	body->CreateFixture(&bodyBolaBoliche);


//	b2PolygonShape shapeMango;
//	b2FixtureDef fixture;
//	shapeMango.SetAsBox(this->ancho / 2, this->alto / 2);
//	fixture.filter.categoryBits = CATEGORIA_FIGURAS;
//	fixture.filter.maskBits = CATEGORIA_FIGURAS;
//	fixture.density = 10.00f;
//	fixture.shape = &shapeMango;
//	fixture.friction = 0.01f;
//	fixture.restitution = 0.00f;
//	body->CreateFixture(&fixture);
}

void Aspa::trabar() {
	jointCuerpoTierra->SetLimits(anguloTrabado, anguloTrabado);
	myWorld->DestroyBody(switchContacto);
}

void Aspa::crearSwitch() {
	//body
	b2Vec2 pos = body->GetWorldPoint(b2Vec2(-0.4 * ancho, 0));
	b2BodyDef bodyDef;
	bodyDef.type = b2_dynamicBody;
	bodyDef.position = pos;
	bodyDef.gravityScale = 0;
	switchContacto = myWorld->CreateBody(&bodyDef);
	switchContacto->SetUserData(this->tijera);
//shape
	b2CircleShape polygon;
	b2FixtureDef fixture;
	polygon.m_radius = (alto / 4.0);
	fixture.filter.categoryBits = CATEGORIA_SWITCH_TIJERA;
	fixture.filter.maskBits = CATEGORIA_SWITCH_TIJERA;
	fixture.density = DENSIDAD_ASPA;
	fixture.shape = &polygon;
	fixture.friction = 0.01f;
	fixture.restitution = 0.00f;
	switchContacto->CreateFixture(&fixture)->SetUserData(this->tijera);
	//joint
	b2RevoluteJointDef rjd;
	rjd.bodyA = body;
	rjd.bodyB = switchContacto;
	rjd.collideConnected = false;
	rjd.localAnchorA = b2Vec2(-0.4 * ancho, 0);
	rjd.localAnchorB = b2Vec2_zero;
	myWorld->CreateJoint(&rjd);

}

void Aspa::removerFisica() {
	super::removerFisica();
	if (switchContacto) {
		myWorld->DestroyBody(switchContacto);
		switchContacto = NULL;
	}
}

void Aspa::limpiarReferenciasB2D() {
	super::limpiarReferenciasB2D();
	jointCuerpoTierra = NULL;
	switchContacto = NULL;
}
