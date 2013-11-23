/*
 * ControlRemoto.cpp
 *
 *  Created on: 17/11/2013
 *      Author: ezequiel
 */

#include "ControlRemoto.h"
#include "../Constantes.h"
#include "Densidades.h"
ControlRemoto::ControlRemoto(const ControlRemoto&) {
	// TODO Auto-generated constructor stub

}

ControlRemoto::~ControlRemoto() {
	// TODO Auto-generated destructor stub
}

ControlRemoto::ControlRemoto() {
}

void ControlRemoto::crearFisica() {
	float x = this->getX();
	float y = this->getY();
	b2Vec2 centro(x, y);
	b2PolygonShape shape;
	shape.SetAsBox(this->ancho / 2, this->alto / 2);
	b2BodyDef bodyDef;
	bodyDef.type = b2_staticBody;
	bodyDef.position.Set(centro.x, centro.y);
//	bodyDef.angle = this->getRotacion() * -3.14 / 180.0;
	bodyDef.fixedRotation = true;
	b2Body* body = myWorld->CreateBody(&bodyDef);
	b2FixtureDef bodyControl;
	bodyControl.filter.categoryBits = CATEGORIA_TACHO;
	bodyControl.filter.maskBits = CATEGORIA_TACHO;
//			bodyControl.density = 1.0f ;
	bodyControl.shape = &shape;

	b2PolygonShape shapeDown;
	shapeDown.SetAsBox(this->ancho / 2, this->alto / 20,
			b2Vec2(0, -this->alto / 2), 0);
	b2FixtureDef defDown;
	defDown.filter.categoryBits = CATEGORIA_FIGURAS;
	defDown.filter.maskBits = CATEGORIA_FIGURAS;
	defDown.density = DENSIDAD_TACHO;
	defDown.shape = &shapeDown;
	body->CreateFixture(&defDown);

	b2PolygonShape shapeLeft;
	shapeLeft.SetAsBox(this->ancho / 2, this->alto / 20,
			b2Vec2(-this->ancho / 2, 0), 90 * -3.14 / 180.0);
	b2FixtureDef defLeft;
	defLeft.filter.categoryBits = CATEGORIA_FIGURAS;
	defLeft.filter.maskBits = CATEGORIA_FIGURAS;
	defLeft.density = DENSIDAD_TACHO;
	defLeft.shape = &shapeLeft;
	body->CreateFixture(&defLeft);

	b2PolygonShape shapeRight;
	shapeRight.SetAsBox(this->ancho / 2, this->alto / 20,
			b2Vec2(this->ancho / 2, 0), 90 * -3.14 / 180.0);
	b2FixtureDef defRight;
	defRight.filter.categoryBits = CATEGORIA_FIGURAS;
	defRight.filter.maskBits = CATEGORIA_FIGURAS;
	defRight.density = DENSIDAD_TACHO;
	defRight.shape = &shapeRight;
	body->CreateFixture(&defRight);

	body->CreateFixture(&bodyControl);
	body->SetUserData(this);
	this->setBody(body);

}

void ControlRemoto::acept(VisitorFigura* visitor) {
	visitor->visit(this);
}

float ControlRemoto::getAlto() const {
	return alto;
}

void ControlRemoto::setAlto(float alto) {
	this->alto = alto;
}

float ControlRemoto::getAncho() const {
	return ancho;
}

ControlRemoto::ControlRemoto(float x, float y, float ancho, float alto) :
		Objeto(x, y) {
	this->ancho = ancho;
	this->alto = alto;
}

void ControlRemoto::setAncho(float ancho) {
	this->ancho = ancho;
}

void ControlRemoto::accionar() {
	for (b2Body* b = myWorld->GetBodyList(); b; b = b->GetNext()) {
		Figura* figura = (Figura*) b->GetUserData();
		figura->explotar();

	}
}

void ControlRemoto::crearFisicaEstaticaTemplate() {
	float x = this->getX();
	float y = this->getY();
	b2Vec2 centro(x, y);
	b2PolygonShape shape;
	shape.SetAsBox(this->ancho / 2, this->alto / 2);
	b2BodyDef bodyDef;
	bodyDef.type = b2_staticBody;
	bodyDef.position.Set(centro.x, centro.y);
	bodyDef.angle = this->getRotacion() * -3.14 / 180.0;
	b2Body* body = myWorld->CreateBody(&bodyDef);
	b2FixtureDef bodyControl;
	bodyControl.filter.categoryBits = CATEGORIA_FIGURAS;
	bodyControl.filter.maskBits = CATEGORIA_FIGURAS;
	bodyControl.density = 10.0f;
	bodyControl.shape = &shape;
	body->CreateFixture(&bodyControl);
	body->SetUserData(this);
	this->setBody(body);
}
