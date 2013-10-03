/*
 * Motor.cpp
 *
 *  Created on: 28/09/2013
 *      Author: jonathan
 */

#include "Motor.h"
#include <iostream>
using namespace std;

Motor::Motor(float x, float y,Rotador * rot, float w, float h):Objeto(x,y,rot) {
	this->w = w;
	this->h = h;

}

Motor::~Motor() {
	// TODO Auto-generated destructor stub
}

void Motor::crearFisica(b2World* world) {
	float x = this->getX();
	float y = this->getY();
	b2PolygonShape * polygon= new b2PolygonShape();
	polygon->SetAsBox(this->w/2,this->h/2);
	b2BodyDef bodyDef;
	bodyDef.type = b2_dynamicBody;
	bodyDef.position.Set(x,y);
	bodyDef.fixedRotation = true;
	double rotacionRad = this->getRotacion() * -3.14 / 180.0;
	bodyDef.angle = rotacionRad;
	b2Body* body = world->CreateBody(&bodyDef);
	body->CreateFixture(polygon, 10.0f);
	body->SetUserData(this);
	this->setBody(body);
//	b2Vec2 pos = body->GetPosition();
//	body->SetTransform(pos, rotacionRad);
//	int i =world->GetBodyCount();
//	cout << i << endl;
//	body->Dump();
}

void Motor::acept(VisitorFigura* visitor){

}
