/*
 * Yunque.cpp
 *
 *  Created on: 13/11/2013
 *      Author: ezequiel
 */

#include "Yunque.h"
#include <iostream>
#include "../Constantes.h"
Yunque::Yunque() : Objeto() {
	this->ancho = 0;
	this->alto = 0;
	this->anchoBack = 0 ;
	// TODO Auto-generated constructor stub

}

Yunque::Yunque(float x, float y, float w, float h) : Objeto(x,y){
	this->ancho = w;
	this->alto = h;
	this->anchoBack = this->ancho;
}

Yunque::~Yunque() {
	// TODO Auto-generated destructor stub
}

Yunque::Yunque(const Yunque& figura) {
}

void Yunque::crearFisica() {
	float x = this->getX();
	float y = this->getY();
	b2Vec2 centro(x, y);
	b2PolygonShape * polygon = new b2PolygonShape();

	b2MassData masa;
	/*masa.center = centro;
	 masa.mass = 100.00;
	 masa.I = 0.00;
	 polygon->ComputeMass(&masa,3);*/
	polygon->SetAsBox(this->ancho / 2, this->alto / 2);

	b2FixtureDef fixture;
	fixture.density = 200.00f;
	fixture.shape = polygon;
	fixture.friction = 1.0f;
	fixture.restitution = 0.00f;
	fixture.filter.categoryBits = CATEGORIA_FIGURAS;
	fixture.filter.maskBits = CATEGORIA_FIGURAS;
	b2BodyDef bodyDef;
	bodyDef.type = b2_dynamicBody;
	bodyDef.position.Set(x, y);
	bodyDef.fixedRotation = true;

	double rotacionRad = this->getRotacion() * -3.14 / 180.0;
	bodyDef.angle = rotacionRad;
	b2Body* body = myWorld->CreateBody(&bodyDef);
	//body->CreateFixture(polygon, 10.0f);
	body->CreateFixture(&fixture);
	body->SetUserData(this);
	this->setBody(body);
	b2DistanceJointDef jd;
}

void Yunque::acept(VisitorFigura* v) {
	v->visit(this);
}

float Yunque::getAlto() const {
	return alto;
}

void Yunque::setAlto(float alto) {
	this->alto = alto;
}

float Yunque::getAncho() const {
	return ancho;
}

void Yunque::setAncho(float ancho) {
	this->ancho = ancho;
}
