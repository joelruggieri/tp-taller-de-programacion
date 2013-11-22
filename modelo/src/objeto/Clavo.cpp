/*
 * Clavo.cpp
 *
 *  Created on: 13/11/2013
 *      Author: ezequiel
 */

#include "Clavo.h"
#include "../Constantes.h"
#include "Densidades.h"
Clavo::Clavo(const Clavo& figura) {
	this->x = figura.getX();
	this->y = figura.getY();
	body = figura.body;
	vista = figura.vista;
	rotacion = figura.getRotacion();
	alto = figura.getAlto();
	ancho = figura.getAncho();
	this->reg = figura.reg;
}

Clavo::~Clavo() {
	// TODO Auto-generated destructor stub
}

Clavo::Clavo(float x, float y, float w, float h) :
		Objeto(x, y) {
	this->alto = h;
	this->ancho = w;
}

void Clavo::acept(VisitorFigura* v) {
	v->visit(this);
}

void Clavo::crearFisica() {
	float x = this->getX();
	float y = this->getY();
	b2Vec2 centro(x, y);
	b2PolygonShape shape;
	shape.SetAsBox(this->ancho / 2.0, this->alto / 6.0);
	b2BodyDef bodyDef;
	bodyDef.type = b2_staticBody;
	bodyDef.position.Set(x, y);
	bodyDef.angle = this->getRotacion() * -b2_pi / 180.0;
	b2Body* body = myWorld->CreateBody(&bodyDef);
	b2FixtureDef bodyClavo;
	bodyClavo.filter.categoryBits = CATEGORIA_FIGURAS;
	bodyClavo.filter.maskBits = CATEGORIA_FIGURAS;
	bodyClavo.shape = &shape;
	bodyClavo.density = DENSIDAD_CLAVO;
	bodyClavo.friction = 0.3f;
	bodyClavo.restitution = 0.6f;	//mucho coeficiente de restitucion
	b2PolygonShape shape2;
	shape2.SetAsBox(this->ancho / 10, this->alto / 10,
			b2Vec2(this->ancho / 2 - this->ancho / 12, 0), 0);
	b2FixtureDef bodyClavoPunta;
	bodyClavoPunta.filter.categoryBits = CATEGORIA_FIGURAS;
	bodyClavoPunta.filter.maskBits = CATEGORIA_FIGURAS;
	bodyClavoPunta.shape = &shape2;
	body->CreateFixture(&bodyClavoPunta)->SetUserData(this);
	body->CreateFixture(&bodyClavo);
	body->SetUserData(this);
	this->setBody(body);

	b2PolygonShape shape3;
	float anchoCabeza = ancho * 0.125;
	shape2.SetAsBox(anchoCabeza, this->alto / 2,
			b2Vec2(-this->ancho / 2 + anchoCabeza, 0), 0);
	b2FixtureDef fixtureCabeza;
	fixtureCabeza.filter.categoryBits = CATEGORIA_FIGURAS;
	fixtureCabeza.filter.maskBits = CATEGORIA_FIGURAS;
	fixtureCabeza.shape = &shape2;
	body->CreateFixture(&fixtureCabeza);

}

Clavo::Clavo() {
	this->ancho = 0;
	this->alto = 0;
	this->rotacion = 0;
}
