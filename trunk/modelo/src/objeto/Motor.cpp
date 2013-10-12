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
	this->radio = w ;
}

Motor::~Motor() {
	// TODO Auto-generated destructor stub
}

void Motor::crearFisica(b2World * w, b2Body* ground) {

	float x = this->getX();
	float y = this->getY();
	b2Vec2 centro(x,y);
	centro.x = this->getX();
	centro.y = this->getY();
	b2CircleShape shapeCircle;
	shapeCircle.m_radius = this->w ;

	b2FixtureDef fixture;
	fixture.density = 600.00f;
	fixture.shape = &shapeCircle;
	fixture.friction = 0.01f;
	fixture.restitution = 0.00f;
	b2BodyDef bodyDef;
//	bodyDef.angularDamping = 0.00f;
	bodyDef.type = b2_dynamicBody;
//	bodyDef.fixedRotation = false;
	bodyDef.position.Set(x,y);
	double rotacionRad = this->getRotacion() * 3.14 / 180.0;
	bodyDef.angle = rotacionRad;
	b2Body* body = w->CreateBody(&bodyDef);
	body->CreateFixture(&fixture);
//	body->SetGravityScale(0);
//	body->SetAngularVelocity(5.0f*this->direccion);

	body->SetUserData(this);
	this->setBody(body);


	b2CircleShape shapeCircle2;
	shapeCircle2.m_radius = this->w / 4  ;

		b2FixtureDef fixture2;
//		fixture.density = 15.00f;
		fixture2.shape = &shapeCircle2;
//		fixture.friction = 0.01f;
//		fixture.restitution = 0.00f;
		b2BodyDef bodyDef2;
	//	bodyDef.angularDamping = 0.00f;
//		bodyDef2.type = b2_staticBody;
		bodyDef2.fixedRotation = false;
		bodyDef2.position.Set(x,y);
		double rotacionRad2 = this->getRotacion() * 3.14 / 180.0;
		bodyDef2.angle = rotacionRad2;
		b2Body* bodyCircle = w->CreateBody(&bodyDef2);
		bodyCircle->CreateFixture(&fixture2);


	b2RevoluteJointDef rjd;
	rjd.Initialize(bodyCircle,body,centro);
	rjd.motorSpeed =  this->direccion * 100;
	rjd.maxMotorTorque = 10000.0f;
	rjd.collideConnected = true;
	rjd.enableMotor = true;
	rjd.enableLimit = false;
//	rjd.
	w->CreateJoint(&rjd);

}

void Motor::acept(VisitorFigura* visitor){
	visitor->visit(this);
}

//TODO IMPLEMENTAR CONSTRUCTOR COPIA Y AGREGAR ESTO this->reg =figura.reg;

void Motor::modificarSentido() {
	this->direccion = this->direccion * (-1);
}

Motor::Motor(const Motor& figura):Objeto(x,y) {
	this->x = figura.getX();
	this->y = figura.getY();
	this->setRotacion(figura.getRotacion());
	this->setRadio(figura.getRadio());
	this->reg = figura.reg;
	this->direccion = -1;
	this->w = w;
	this->h = h;
	this->radio = radio;
}

Motor::Motor() {
	this->radio = 0;
}

float Motor::getRadio() const {
	return radio;
}

void Motor::setRadio(float radio) {
	this->radio = radio;
}
