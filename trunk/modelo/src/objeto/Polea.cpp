/*
 * Polea.cpp
 *
 *  Created on: 28/09/2013
 *      Author: jonathan
 */

#include "Polea.h"
#include "../Constantes.h"
#include <iostream>
using namespace std;

Polea::Polea(float x, float y, float radio) :
		Objeto(x, y) {
	this->radio = radio;
	radioAccion = NULL;
	crearEnganches();
	joint = NULL;
}

Polea::~Polea() {
}

void Polea::crearFisica() {
	float x = this->getX();
	float y = this->getY();
	b2Vec2 centro(x, y);
	b2CircleShape shapeCircle;
	b2BodyDef bodyDef;
	bodyDef.type = b2_staticBody;
	bodyDef.position.Set(centro.x, centro.y);
	bodyDef.angle = 0;
	bodyDef.fixedRotation = true;
	b2Body* body = myWorld->CreateBody(&bodyDef);
	shapeCircle.m_radius = this->radio;
	b2FixtureDef bodyGancho;
	bodyGancho.shape = &shapeCircle;
	bodyGancho.filter.categoryBits = CATEGORIA_FIGURAS;
	bodyGancho.filter.maskBits = CATEGORIA_FIGURAS;
	body->CreateFixture(&bodyGancho)->SetUserData(this);
	body->SetUserData(this);
	this->setBody(body);

	//definicion cuerpo radio de accion, ES ESTATICO.

	b2CircleShape shapeAccion;
	shapeAccion.m_radius = this->radio;
	b2FixtureDef fixtureAccion;
	fixtureAccion.filter.categoryBits = CATEGORIA_LIMITE_POLEA;
	fixtureAccion.filter.maskBits = CATEGORIA_LIMITE_POLEA;
	fixtureAccion.density = 1.00f;
	fixtureAccion.shape = &shapeAccion;
	fixtureAccion.friction = 0.01f;
	fixtureAccion.restitution = 0.00f;
	b2BodyDef bodyDefAccion;
	bodyDefAccion.position = centro;
	radioAccion = myWorld->CreateBody(&bodyDefAccion);
	radioAccion->CreateFixture(&fixtureAccion);
	radioAccion->SetUserData(this);
}

void Polea::acept(VisitorFigura* visitor) {
	visitor->visit(this);
}

Polea::Polea(const Polea& figura) {
	this->x = figura.getX();
	this->y = figura.getY();
	this->setRotacion(figura.getRotacion());
	this->setRadio(figura.getRadio());
	this->reg = figura.reg;
	radio = figura.radio;
	radioAccion = NULL;
	crearEnganches();
	joint = NULL;
}

float Polea::getRadio() {
	return this->radio;
}

Polea::Polea() :
		Objeto() {
	this->radio = 0;
	radioAccion = NULL;
	crearEnganches();
	joint = NULL;
}

float Polea::getRadio() const {
	return radio;
}

void Polea::setRadio(float radio) {
	this->radio = radio;
}

void Polea::removerFisica() {
	super::removerFisica();
	if(radioAccion){
		myWorld->DestroyBody(this->radioAccion);
		radioAccion = NULL;
	}
	if(joint){
		myWorld->DestroyJoint(joint);
		joint = NULL;
	}
}

void Polea::accionesPostFisica() {
	b2Body * eslabonIzq = izq->getEslabon();
	b2Body * eslabonDer = der->getEslabon();
	if(eslabonIzq && eslabonDer){
		b2Vec2 anchor1 = eslabonIzq->GetWorldCenter();
		b2Vec2 anchor2 = eslabonDer->GetWorldCenter();
		izq->desprender();
		der->desprender();
		b2Vec2 groundAnchor1(izq->getWorldPos());
		b2Vec2 groundAnchor2(der->getWorldPos());
		float32 ratio = 1.0f;
		b2PulleyJointDef jointDef;
		jointDef.Initialize(eslabonIzq, eslabonDer, groundAnchor1, groundAnchor2, anchor1,
		anchor2, ratio);
		joint = myWorld->CreateJoint(&jointDef);
	}
}

void Polea::crearEnganches() {
	izq= new Enganche(this,-radio,0);
	izq->setRequiereEslabon(true);
	this->enganches.push_back(izq);
	der = new Enganche(this,radio,0);
	der->setRequiereEslabon(true);
	this->enganches.push_back(der);
}

void Polea::limpiarReferenciasB2D() {
	joint = NULL;
}
