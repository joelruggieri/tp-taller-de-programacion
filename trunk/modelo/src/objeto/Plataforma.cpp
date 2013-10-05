/*
 * Plataforma.cpp
 *
 *  Created on: 02/10/2013
 *      Author: joel
 */

#include "Plataforma.h"

Plataforma::Plataforma(): Objeto(){
	this->ancho = 0;
	this->alto = 0;
}

Plataforma::Plataforma(float x, float y, float ancho, float alto): Objeto(x,y) {
	this->ancho = ancho;
	this->alto = alto;
}

Plataforma::Plataforma(const Plataforma& plataforma){
	x = plataforma.getX();
	y = plataforma.getY();
	alto = plataforma.getAlto();
	ancho = plataforma.getAncho();
	body = plataforma.body;
	rotacion  = plataforma.getRotacion();
	vista = plataforma.vista;
}

Plataforma::~Plataforma() {
	// TODO Auto-generated destructor stub
}

float Plataforma::getAlto() const{
	return this->alto;
}

float Plataforma::getAncho() const{
	return this->ancho;
}

void Plataforma::setAlto(float alto){
	this->alto = alto;
}

void Plataforma::setAncho(float ancho){
	this->ancho = ancho;
}

void Plataforma::crearFisica(b2World * world){
	float x = this->getX();
	float y = this->getY();
	b2Vec2 centro(x,y);
	b2PolygonShape * polygon= new b2PolygonShape();

	b2MassData masa;
	/*masa.center = centro;
	masa.mass = 100.00;
	masa.I = 0.00;
	polygon->ComputeMass(&masa,3);*/
	polygon->SetAsBox(this->ancho/2,this->alto/2);

	b2FixtureDef fixture;
	fixture.density = 50.00f;
	fixture.shape = polygon;
	fixture.friction = 0.01f;
	fixture.restitution = 0.00f;
	b2BodyDef bodyDef;
	bodyDef.type = b2_staticBody;
	bodyDef.position.Set(x,y);
	bodyDef.fixedRotation = true;
	double rotacionRad = this->getRotacion() * -3.14 / 180.0;
	bodyDef.angle = rotacionRad;
	b2Body* body = world->CreateBody(&bodyDef);
	//body->CreateFixture(polygon, 10.0f);
	body->CreateFixture(&fixture);
	body->SetUserData(this);
	this->setBody(body);
}

void Plataforma::acept(VisitorFigura* visitor){
	visitor->visit(this);
} /* namespace std */

