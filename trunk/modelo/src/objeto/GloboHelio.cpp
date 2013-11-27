/*
 * GloboHelio.cpp
 *
 *  Created on: 02/10/2013
 *      Author: ezequiel
 */

#include "GloboHelio.h"
#include "../Constantes.h"
#include "../interaccion/ValidadorEnArea.h"
#include "Densidades.h"
using namespace std;

GloboHelio::GloboHelio(float x, float y, float radio) :
		Objeto(x, y, new ValidadorEnArea(this)) {
	this->radio = radio;
	this->setRotacion(0);
	this->enganches.push_back(new Enganche(this,0, -1 * radio));
	rebentable = false;
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
	bodyDef.angle = this->getRotacion() * -b2_pi/ 180.0;
	bodyDef.fixedRotation = true;
	bodyDef.linearDamping = 0.15;
	bodyDef.gravityScale=0;
	b2Body* body = myWorld->CreateBody(&bodyDef);
	shapeCircle.m_radius = this->radio;
	b2FixtureDef bodyBolaBoliche;
	bodyBolaBoliche.shape = &shapeCircle;
	bodyBolaBoliche.filter.categoryBits = CATEGORIA_FIGURAS;
	bodyBolaBoliche.filter.maskBits = CATEGORIA_FIGURAS;
	bodyBolaBoliche.density = DENSIDAD_GLOBO;	//poca densidad, la densidad del aire cual es ?
	bodyBolaBoliche.friction = 0.2f;
	bodyBolaBoliche.restitution = 0.3f;
	body->CreateFixture(&bodyBolaBoliche)->SetUserData(this);
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
	this->enganches.push_back(new Enganche(this,0, -1 * radio));
	rebentable = false;
	radio = figura.radio;
}

GloboHelio::GloboHelio() :
		Objeto() {
	this->radio = 0;
	rebentable = false;
}

float GloboHelio::getRadio() const {
	return radio;
}

void GloboHelio::setRadio(float radio) {
	this->radio = radio;
}

void GloboHelio::updateModelo() {
	super::updateModelo();
	if (getBody() != NULL && body->GetLinearVelocity().y < 8) {
		b2Vec2 p = body->GetWorldPoint(b2Vec2(0.0f, 2.0f));
		b2Vec2 f = body->GetWorldVector(b2Vec2(0.0f, 450.0  ));
		body->ApplyForce(f, p);
	}
	if(getBody() != NULL && body->GetLinearVelocity().x > 0.1){
		b2Vec2 p = body->GetWorldPoint(b2Vec2(0.0, 1.0f));
		b2Vec2 f = body->GetWorldVector(b2Vec2(-10.0f* body->GetLinearVelocity().x, 0));
		body->ApplyForce(f,p);
	}
	if(getBody() != NULL && body->GetLinearVelocity().x <  -0.1){
		b2Vec2 p = body->GetWorldPoint(b2Vec2(-1.0f, 0.0f));
		b2Vec2 f = body->GetWorldVector(b2Vec2(-10.0f * body->GetLinearVelocity().x, 0));
		body->ApplyForce(f,p);
	}

}

void GloboHelio::setRebentable(bool reb) {
	rebentable = reb;
}

void GloboHelio::interactuar(Area& area, int jugador) {
	if(rebentable){
		super::interactuar(area,jugador);
	}
}

void GloboHelio::accionar() {
	notify(DESACTIVADO);
	myWorld->DestroyBody(this->getBody());
	viva = false;
	this->vista->alertarEvento(VALOR_ACTIVAR_SONIDO_DEFECTO);
}

void GloboHelio::recibirImpacto(b2Vec2 direccion) {
this->realizarImpacto(direccion);
}

bool GloboHelio::hacerContacto(float numero){
	return false;
}
