/*
 * Clavo.cpp
 *
 *  Created on: 13/11/2013
 *      Author: ezequiel
 */

#include "Clavo.h"
#include "../Constantes.h"
Clavo::Clavo(const Clavo& figura) {
	this->x = figura.getX();
	this->y = figura.getY();
	this->rotacion = figura.getRotacion();
//	this->setRadio(figura.getRadio());

		this->reg = figura.reg;
}

Clavo::~Clavo() {
	// TODO Auto-generated destructor stub
}

Clavo::Clavo(float x, float y, float w, float h) : Objeto(x,y){
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
		shape.SetAsBox(this->ancho / 2, this->alto / 2);
		b2BodyDef bodyDef;
		bodyDef.type = b2_staticBody;
		bodyDef.position.Set(centro.x, centro.y);
		bodyDef.angle = this->getRotacion() * -3.14 / 180.0;
		b2Body* body = myWorld->CreateBody(&bodyDef);
//		shapeCircle.m_radius = this->radio;
		b2FixtureDef bodyPelota;
		bodyPelota.filter.categoryBits = CATEGORIA_FIGURAS;
		bodyPelota.filter.maskBits = CATEGORIA_FIGURAS;
		bodyPelota.shape = &shape;
		bodyPelota.density = 10.0f;
		bodyPelota.friction = 0.3f;
		bodyPelota.restitution = 0.6f;	//mucho coeficiente de restitucion
		body->CreateFixture(&bodyPelota)->SetUserData(this);
	//		b2MassData masa;
	//		masa.mass = 50.0f; //chequear la cantidad de masa
	//		masa.I = 0.04; // chequear inercia rotacional
	//		body->SetMassData(&masa);	//centro de masa esta en el centro de la esfera por defecto
		body->SetUserData(this);
		this->setBody(body);
}

Clavo::Clavo() {
	this->x = 0;
	this->y = 0;
	this->rotacion = 0 ;
}
