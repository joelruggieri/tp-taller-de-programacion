/*
 * Balancin.cpp
 *
 *  Created on: 05/10/2013
 *      Author: joel
 */

#include "Balancin.h"
#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include <iostream>
#include <cmath>
#include "../figura/Registro.h"
#include "../Constantes.h"
#include "Densidades.h"
Balancin::Balancin(): Objeto() {
	alto = 0;
	ancho = 0;

}


Balancin::Balancin(float x, float y, float ancho, float alto): Objeto(x,y) {
	this->ancho = ancho;
	this->alto = alto;
	Enganche* engancheDerecho = new Enganche(this, -0.9* ancho/2.0,0);
	Enganche* engancheIzquierdo = new Enganche(this,0.9*ancho/2.0, 0 );
	enganches.push_back(engancheIzquierdo);
	enganches.push_back(engancheDerecho);
}

Balancin::Balancin(const Balancin& balancin){
	x = balancin.getX();
	y = balancin.getY();
	alto = balancin.getAlto();
	ancho = balancin.getAncho();
	body = balancin.body;
	rotacion  = balancin.getRotacion();
	vista = balancin.vista;
	this->reg = balancin.reg;


	Enganche* engancheDerecho = new Enganche(this,-1* ancho/2,0);
	Enganche* engancheIzquierdo = new Enganche(this, ancho/2, 0 );
	enganches.push_back(engancheIzquierdo);
	enganches.push_back(engancheDerecho);
}

Balancin::~Balancin() {
//	list<Enganche*>::iterator it;
//	for(it = enganches.begin() ; it != enganches.end() ; ++it){
//		delete (*it);
//	}
}

float Balancin::getAlto() const{
	return this->alto;
}

float Balancin::getAncho() const{
	return this->ancho;
}

void Balancin::setAlto(float alto){
	this->alto = alto;
}

void Balancin::setAncho(float ancho){
	this->ancho = ancho;
}

void Balancin::crearFisica(){

	float x = this->getX();
	float y = this->getY();
	b2Vec2 centro(x,y);
	b2PolygonShape * polygon= new b2PolygonShape();

	b2MassData masa;
	polygon->SetAsBox(this->ancho/2,this->alto/2);

	b2FixtureDef fixture;
	fixture.filter.categoryBits = CATEGORIA_FIGURAS;
	fixture.filter.maskBits = CATEGORIA_FIGURAS;
	fixture.density = DENSIDAD_BALANCIN;
	fixture.shape = polygon;
	fixture.friction = 0.01f;
	fixture.restitution = 0.00f;
	b2BodyDef bodyDef;
	bodyDef.type = b2_dynamicBody;
	bodyDef.position.Set(x,y);
	//bodyDef.fixedRotation = true;
	double rotacionRad = this->getRotacion() * -1*b2_pi / 180.0;
	bodyDef.angle = rotacionRad;
	b2Body* body = myWorld->CreateBody(&bodyDef);
	body->CreateFixture(&fixture);
	body->SetUserData(this);
	this->setBody(body);

	b2RevoluteJointDef rjd;
	rjd.Initialize(ground,body,centro);
	rjd.collideConnected = true;
	rjd.maxMotorTorque= 20000;
	if(this->getRotacion() == 0){
		rjd.lowerAngle = -0.25f * b2_pi;
		rjd.upperAngle = 0.25f * b2_pi;
	}else if(this->getRotacion() == 45){
		rjd.lowerAngle = 0.00f;
		rjd.upperAngle = 0.50f * b2_pi;
	}else if(this->getRotacion() == -45){
		rjd.lowerAngle = -0.50f * b2_pi;
		rjd.upperAngle =  0;//0.0f * (-b2_pi);
	}
	rjd.enableLimit = true;
	myWorld->CreateJoint(&rjd);

}

void Balancin::acept(VisitorFigura* visitor){
	visitor->visit(this);
}


void Balancin::crearFisicaEstaticaTemplate(b2World * w, b2Body* ground){
	float x = this->getX();
		float y = this->getY();
		b2Vec2 centro(x, y);
		b2PolygonShape * polygon = new b2PolygonShape();


		polygon->SetAsBox(this->ancho / 2, this->alto / 2);

		b2FixtureDef fixture;
		fixture.shape = polygon;
		fixture.filter.categoryBits = CATEGORIA_FIGURAS;
		b2BodyDef bodyDef;
		bodyDef.type = b2_staticBody;
		bodyDef.position.Set(x, y);
		bodyDef.fixedRotation = true;

		double rotacionRad = this->getRotacion() * -3.14 / 180.0;
		bodyDef.angle = rotacionRad;
		b2Body* body = w->CreateBody(&bodyDef);
		body->CreateFixture(&fixture);
		body->SetUserData(this);
		this->setBody(body);
}
