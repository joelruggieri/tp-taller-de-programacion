/*
 * BolaBoliche.cpp
 *
 *  Created on: 28/09/2013
 *      Author: jonathan
 */

#include "BolaBoliche.h"

BolaBoliche::BolaBoliche(float x, float y, float radio):Objeto(x,y) {
//this->x = x ;
//this->y = y;
this->radio = radio ;


}

BolaBoliche::~BolaBoliche() {
}

void BolaBoliche::crearFisica(b2World* world) {
	float x = this->getX();
	float y = this->getY();
	b2Vec2 centro(x,y);
	b2CircleShape shapeCircle;


		b2BodyDef bodyDef;
		bodyDef.type = b2_dynamicBody;
		bodyDef.position.Set(centro.x, centro.y);
		bodyDef.angle = this->getRotacion() * -3.14 / 180.0;
		b2Body* body = world->CreateBody(&bodyDef);
		shapeCircle.m_radius = this->radio ;
		b2FixtureDef bodyBolaBoliche;
		bodyBolaBoliche.shape = &shapeCircle;
		bodyBolaBoliche.density = 45.0f;
		bodyBolaBoliche.friction = 0.2f;
		bodyBolaBoliche.restitution	 = 0.05;	//poco coeficiente de restitucion
		body->CreateFixture(&bodyBolaBoliche);
//		b2MassData masa;
//		masa.mass = 50; //chequear la cantidad de masa
//		masa.I = 0.005; // chequear inercia rotacional
//		body->SetMassData(&masa);	//centro de masa esta en el centro de la esfera por defecto
		body->SetUserData(this);
		this->setBody(body);
}

void BolaBoliche::acept(VisitorFigura* visitor) {
	visitor->visit(this);
}

BolaBoliche::BolaBoliche(const BolaBoliche& figura) {
	this->x = figura.getX();
	this->y = figura.getY();
	this->setRotacion(figura.getRotacion());
	this->setRadio(figura.getRadio());
}

float BolaBoliche::getRadio() {
	return this->radio;
}

BolaBoliche::BolaBoliche():Objeto() {
	this->radio = 0 ;
}

float BolaBoliche::getRadio() const {
	return radio;
}

void BolaBoliche::setRadio(float radio) {
	this->radio =  radio;
}
