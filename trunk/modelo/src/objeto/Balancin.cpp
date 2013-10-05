/*
 * Balancin.cpp
 *
 *  Created on: 05/10/2013
 *      Author: joel
 */

#include "Balancin.h"

Balancin::Balancin(): Objeto() {
	alto = 0;
	ancho = 0;

}


Balancin::Balancin(float x, float y, float ancho, float alto): Objeto(x,y) {
	this->ancho = ancho;
	this->alto = alto;
}

Balancin::Balancin(const Balancin& balancin){
	x = balancin.getX();
	y = balancin.getY();
	alto = balancin.getAlto();
	ancho = balancin.getAncho();
	body = balancin.body;
	rotacion  = balancin.getRotacion();
	vista = balancin.vista;
}

Balancin::~Balancin() {
	// TODO Auto-generated destructor stub
}

float Balancin::getAlto() const{
	return this->alto;
}

float Balancin::getAncho() const{
	return this->ancho;
}

void Balancin::setAlto(float alto){
	this->alto = alto;
}

void Balancin::setAncho(float ancho){
	this->ancho = ancho;
}

void Balancin::crearFisica(b2World * world){

	float x = this->getX();
	float y = this->getY();
	b2Vec2 centro(x,y);
	b2PolygonShape * polygon= new b2PolygonShape();

	b2MassData masa;
	polygon->SetAsBox(this->ancho/2,this->alto/2);

	b2FixtureDef fixture;
	fixture.density = 50.00f;
	fixture.shape = polygon;
	fixture.friction = 0.01f;
	fixture.restitution = 0.00f;
	b2BodyDef bodyDef;
	bodyDef.type = b2_dynamicBody;
	bodyDef.position.Set(x,y);
	bodyDef.fixedRotation = true;
	double rotacionRad = this->getRotacion() * -3.14 / 180.0;
	bodyDef.angle = rotacionRad;
	b2Body* body = world->CreateBody(&bodyDef);
	//body->CreateFixture(polygon, 10.0f);
	body->CreateFixture(&fixture);
	body->SetUserData(this);
	this->setBody(body);

	b2CircleShape shape;
	shape.m_radius = this->getAlto()/2 ;
	b2BodyDef bd;
	bd.type = b2_staticBody;
	bd.position.Set(centro.x,centro.y);
	b2Body* bodyCircle = world->CreateBody(&bd);
	body->CreateFixture(&shape, 5.0f);

	b2RevoluteJointDef rjd;
	rjd.Initialize(bodyCircle,body,centro);

	rjd.lowerAngle = -45 * 3.14 / 180.0; //TODO ver esto
	rjd.upperAngle = 45 * 3.14 / 180.0;  // TODO ver esto
	rjd.enableLimit = true;
	world->CreateJoint(&rjd);
}

void Balancin::acept(VisitorFigura* visitor){
	visitor->visit(this);
}


