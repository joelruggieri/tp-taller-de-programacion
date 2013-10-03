/*
 * ObjetoCualquiera.cpp
 *
 *  Created on: 01/10/2013
 *      Author: jonathan
 */

#include "ObjetoCualquiera.h"

ObjetoCualquiera::ObjetoCualquiera(float x, float y):Objeto(x,y,0) {
	// TODO Auto-generated constructor stub

}

ObjetoCualquiera::~ObjetoCualquiera() {
	// TODO Auto-generated destructor stub
}

void ObjetoCualquiera::crearFisica(b2World* world) {
	float x = this->getX();
	float y = this->getY();
	b2Vec2 centro(x,y);

	b2PolygonShape * polygon= new b2PolygonShape();
	polygon->SetAsBox(5,5);
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
}

void ObjetoCualquiera::acept(VisitorFigura*) {

}
