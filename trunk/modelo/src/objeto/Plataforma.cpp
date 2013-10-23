/*
 * Plataforma.cpp
 *
 *  Created on: 02/10/2013
 *      Author: joel
 */

#include "Plataforma.h"
#include <iostream>
#include "../Constantes.h"
using namespace std;

Plataforma::Plataforma() :
		Objeto() {
	this->ancho = 0;
	this->alto = 0;
	this->anchoBack = this->ancho;
}

Plataforma::Plataforma(float x, float y, float ancho, float alto) :
		Objeto(x, y) {
	this->ancho = ancho;
	this->alto = alto;
	this->anchoBack = this->ancho;
}

Plataforma::Plataforma(const Plataforma& plataforma) {
	x = plataforma.getX();
	y = plataforma.getY();
	alto = plataforma.getAlto();
	ancho = plataforma.getAncho();
	anchoBack = plataforma.anchoBack;
	//TODO estos son medio duros los dos atributos, vista y body. cuidado con los punteros, puede traer problemas
	body = plataforma.body;
	vista = plataforma.vista;
	rotacion = plataforma.getRotacion();
	this->reg = plataforma.reg;
}

Plataforma::~Plataforma() {
	// TODO Auto-generated destructor stub
}

float Plataforma::getAlto() const {
	return this->alto;
}

float Plataforma::getAncho() const {
	return this->ancho;
}

void Plataforma::setAlto(float alto) {
	this->alto = alto;
}

void Plataforma::setAncho(float ancho) {
//	cout << "llama setAncho" << endl;
	if (ancho < 2) {
		ancho = 2;
	}
	if (ancho > 100) {
		ancho = 100;
	}
	this->ancho = ancho;
}

void Plataforma::crearFisica() {
	float x = this->getX();
	float y = this->getY();
	b2Vec2 centro(x, y);
	b2PolygonShape * polygon = new b2PolygonShape();

	b2MassData masa;
	/*masa.center = centro;
	 masa.mass = 100.00;
	 masa.I = 0.00;
	 polygon->ComputeMass(&masa,3);*/
	polygon->SetAsBox(this->ancho / 2, this->alto / 2);

	b2FixtureDef fixture;
	fixture.density = 50.00f;
	fixture.shape = polygon;
	fixture.friction = 0.4f;
	fixture.restitution = 0.00f;
	fixture.filter.categoryBits = CATEGORIA_FIGURAS;
	fixture.filter.maskBits = CATEGORIA_FIGURAS;
	b2BodyDef bodyDef;
	bodyDef.type = b2_staticBody;
	bodyDef.position.Set(x, y);
	bodyDef.fixedRotation = true;

	double rotacionRad = this->getRotacion() * -3.14 / 180.0;
	bodyDef.angle = rotacionRad;
	b2Body* body = myWorld->CreateBody(&bodyDef);
	//body->CreateFixture(polygon, 10.0f);
	body->CreateFixture(&fixture);
	body->SetUserData(this);
	this->setBody(body);
	b2DistanceJointDef jd;
//	b2Body* ground = NULL;
//		b2BodyDef bd;
//		bd.position = centro;
//		ground = myWorld->CreateBody(&bd);

}

void Plataforma::acept(VisitorFigura* visitor) {
	visitor->visit(this);
} /* namespace std */

void Plataforma::estirar(float delta){
	this->ancho = ancho + delta;
	if (ancho < 2) {
		ancho = 2;
	}
	if (ancho > 100) {
		ancho = 100;
	}
}

void Plataforma::makeBackUp(){
	super::makeBackUp();
	anchoBack = ancho;

}

void Plataforma::restoreBackUp(){
	super::restoreBackUp();
	ancho = anchoBack;
}

