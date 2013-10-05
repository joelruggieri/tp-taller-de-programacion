/*
 * Motor.cpp
 *
 *  Created on: 28/09/2013
 *      Author: jonathan
 */

#include "Motor.h"
#include <iostream>
using namespace std;

Motor::Motor(float x, float y, float w, float h):Objeto(x,y) {
	this->w = w;
	this->h = h;

}

Motor::~Motor() {
	// TODO Auto-generated destructor stub
}

void Motor::crearFisica(b2World* world) {

	float x = this->getX();
	float y = this->getY();
	b2Vec2 centro(x,y);
	b2PolygonShape * polygon= new b2PolygonShape();

	b2MassData masa;
	/*masa.center = centro;
	masa.mass = 100.00;
	masa.I = 0.00;
	polygon->ComputeMass(&masa,3);*/
	polygon->SetAsBox(this->w/2,this->h/2);

	b2FixtureDef fixture;
	fixture.density = 50.00f;
	fixture.shape = polygon;
	fixture.friction = 0.01f;
	fixture.restitution = 0.00f;
	b2BodyDef bodyDef;
	bodyDef.angularDamping = 0.05f;
	bodyDef.type = b2_dynamicBody;
	bodyDef.position.Set(x,y);
	double rotacionRad = this->getRotacion() * 3.14 / 180.0;
	bodyDef.angle = rotacionRad;
	b2Body* body = world->CreateBody(&bodyDef);
	//body->CreateFixture(polygon, 10.0f);
	body->CreateFixture(&fixture);
	body->SetUserData(this);
	this->setBody(body);

}

void Motor::acept(VisitorFigura* visitor){

}
