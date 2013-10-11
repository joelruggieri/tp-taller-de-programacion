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
	this->direccion = -1 ; //por defecto gira en sentido horario
}

Motor::~Motor() {
	// TODO Auto-generated destructor stub
}

void Motor::crearFisica(b2World* world) {

	float x = this->getX();
	float y = this->getY();
	b2Vec2 centro(x,y);
//	b2PolygonShape * polygon= new b2PolygonShape();

	b2MassData masa;
	/*masa.center = centro;
	masa.mass = 100.00;
	masa.I = 0.00;
	polygon->ComputeMass(&masa,3);*/
	b2CircleShape shapeCircle;
//	shp(this->w/2,this->h/2);
	shapeCircle.m_radius = this->w ;

	b2FixtureDef fixture;
	fixture.density = 60000.00f;
	fixture.shape = &shapeCircle;
	fixture.friction = 0.01f;
	fixture.restitution = 0.00f;
	b2BodyDef bodyDef;
	bodyDef.angularDamping = 0.00f;
	bodyDef.type = b2_dynamicBody;
//	bodyDef.fixedRotation = false;
	bodyDef.position.Set(x,y);
	double rotacionRad = this->getRotacion() * 3.14 / 180.0;
	bodyDef.angle = rotacionRad;
	b2Body* body = world->CreateBody(&bodyDef);
	//body->CreateFixture(polygon, 10.0f);
	body->CreateFixture(&fixture);
	body->SetGravityScale(0);
	body->SetAngularVelocity(5.0f*this->direccion);

//	body->SetFixedRotation(false);
	body->SetUserData(this);
	this->setBody(body);
//
//		b2CircleShape shape;
//		shape.m_radius = this->h/2 ;
//		b2BodyDef bd;
//		bd.position.Set(x,y);
//		b2Body* bodyCircle = world->CreateBody(&bd);
//		body->CreateFixture(&shape, 5.0f);
//		bodyCircle->SetAngularVelocity(5.0f*this->direccion);
//		b2RevoluteJointDef rjd;
//		rjd.Initialize(bodyCircle,body,centro);
//		rjd.motorSpeed = 1.0f * b2_pi;
//		rjd.maxMotorTorque = 10000.0f;
//		rjd.collideConnected = true;
//		rjd.enableLimit = true;
//		world->CreateJoint(&rjd);

}

void Motor::acept(VisitorFigura* visitor){
	visitor->visit(this);
}

//TODO IMPLEMENTAR CONSTRUCTOR COPIA Y AGREGAR ESTO this->reg =figura.reg;

void Motor::modificarSentido() {
	this->direccion = this->direccion * (-1);
}
