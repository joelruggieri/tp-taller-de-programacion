/*
 * Yunque.cpp
 *
 *  Created on: 13/11/2013
 *      Author: ezequiel
 */

#include "Yunque.h"
#include <iostream>
#include "../Constantes.h"
Yunque::Yunque() : Objeto() {
	this->ancho = 0;
	this->alto = 0;
	this->anchoBack = 0 ;
	// TODO Auto-generated constructor stub
//	this->enganches.push_back(new Enganche(this,0,this->alto));

}

Yunque::Yunque(float x, float y, float w, float h) : Objeto(x,y){
	this->ancho = w;
	this->alto = h;
	this->anchoBack = this->ancho;
	this->enganches.push_back(new Enganche(this,0,this->alto / 2));
}

Yunque::~Yunque() {
	// TODO Auto-generated destructor stub
}

Yunque::Yunque(const Yunque& figura) {
	this->enganches.push_back(new Enganche(this,0,this->alto));
}

void Yunque::crearFisica() {
	float x = this->getX();
		float y = this->getY();
		b2Vec2 centro(x, y);
		b2PolygonShape shape;

		b2BodyDef bodyDef;
		bodyDef.type = b2_dynamicBody;
		bodyDef.position.Set(centro.x, centro.y);
		bodyDef.angle = this->getRotacion() * -3.14 / 180.0;
		b2Body* body = myWorld->CreateBody(&bodyDef);
//		shape.m_radius = this->radio;
		shape.SetAsBox(this->ancho / 2, this->alto / 2);
		b2FixtureDef bodyPelota;
		bodyPelota.filter.categoryBits = CATEGORIA_FIGURAS;
		bodyPelota.filter.maskBits = CATEGORIA_FIGURAS;
		bodyPelota.shape = &shape;
		bodyPelota.density = 200.0f;
		bodyPelota.friction = 0.3f;
		bodyPelota.restitution = 0.0f;	//mucho coeficiente de restitucion
		body->CreateFixture(&bodyPelota)->SetUserData(this);
	//		b2MassData masa;
	//		masa.mass = 50.0f; //chequear la cantidad de masa
	//		masa.I = 0.04; // chequear inercia rotacional
	//		body->SetMassData(&masa);	//centro de masa esta en el centro de la esfera por defecto
		body->SetUserData(this);
		this->setBody(body);

}

void Yunque::acept(VisitorFigura* v) {
	v->visit(this);
}

float Yunque::getAlto() const {
	return alto;
}

void Yunque::setAlto(float alto) {
	this->alto = alto;
}

float Yunque::getAncho() const {
	return ancho;
}

void Yunque::setAncho(float ancho) {
	this->ancho = ancho;
}
