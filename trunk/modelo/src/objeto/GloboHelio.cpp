/*
 * GloboHelio.cpp
 *
 *  Created on: 02/10/2013
 *      Author: ezequiel
 */

#include "GloboHelio.h"
#include "../Constantes.h"
GloboHelio::GloboHelio(float x, float y, float radio) :
		Objeto(x, y) {
	this->radio = radio;
	this->setRotacion(0);
	this->enganches.push_back(new Enganche(0, -1 * radio));
}

GloboHelio::~GloboHelio() {

}

void GloboHelio::crearFisica() {
	float x = this->getX();
	float y = this->getY();
	b2Vec2 centro(x, y);
	b2CircleShape shapeCircle;

	b2BodyDef bodyDef;
	bodyDef.type = b2_dynamicBody;
	bodyDef.position.Set(centro.x, centro.y);
	bodyDef.angle = this->getRotacion() * -3.14 / 180.0;
	bodyDef.fixedRotation = true;
	bodyDef.linearDamping = 0.15;

	b2Body* body = myWorld->CreateBody(&bodyDef);
	shapeCircle.m_radius = this->radio;
	b2FixtureDef bodyBolaBoliche;
	bodyBolaBoliche.shape = &shapeCircle;
	bodyBolaBoliche.filter.categoryBits = CATEGORIA_FIGURAS;
	bodyBolaBoliche.filter.maskBits = CATEGORIA_FIGURAS;
	bodyBolaBoliche.density = 1.0f;	//poca densidad, la densidad del aire cual es ?
	bodyBolaBoliche.friction = 0.2f;
	bodyBolaBoliche.restitution = 0.3f;
	body->CreateFixture(&bodyBolaBoliche);
	body->SetUserData(this);
	this->setBody(body);

}

void GloboHelio::acept(VisitorFigura* visitor) {
	visitor->visit(this);
}

GloboHelio::GloboHelio(const GloboHelio& figura) {
	this->x = figura.getX();
	this->y = figura.getY();
	this->setRotacion(figura.getRotacion());
	this->setRadio(figura.getRadio());
	this->reg = figura.reg;
//	this->enganches.push_back(new Enganche((int)x, (int)y - (int)radio));
	this->enganches.push_back(new Enganche(0, -1 * radio));
}

GloboHelio::GloboHelio() :
		Objeto() {
	this->radio = 0;
}

float GloboHelio::getRadio() const {
	return radio;
}

void GloboHelio::setRadio(float radio) {
	this->radio = radio;
}

void GloboHelio::updateModelo() {
	super::updateModelo();
	if (getBody() != NULL && body->GetLinearVelocity().y < 10) {
		b2Vec2 p = body->GetWorldPoint(b2Vec2(0.0f, 2.0f));
		b2Vec2 f = body->GetWorldVector(b2Vec2(0.0f, 2500.0  ));
		body->ApplyForce(f, p);
	}
	if(getBody() != NULL && body->GetLinearVelocity().x > 0.1){
		b2Vec2 p = body->GetWorldPoint(b2Vec2(0.0, 1.0f));
		b2Vec2 f = body->GetWorldVector(b2Vec2(-100.0f* body->GetLinearVelocity().x, 0));
		body->ApplyForce(f,p);
	}
	if(getBody() != NULL && body->GetLinearVelocity().x <  -0.1){
		b2Vec2 p = body->GetWorldPoint(b2Vec2(-1.0f, 0.0f));
		b2Vec2 f = body->GetWorldVector(b2Vec2(-100.0f * body->GetLinearVelocity().x, 0));
		body->ApplyForce(f,p);
	}

}
