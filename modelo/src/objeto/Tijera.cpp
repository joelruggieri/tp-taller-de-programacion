/*
 * Tijera.cpp
 *
 *  Created on: 15/11/2013
 *      Author: joel
 */

#include "Tijera.h"
#include <math.h>
#include "../figura/Registro.h"
#include "../Constantes.h"
#include "../figura/Mapa.h"
#include "../interaccion/ValidadorEnArea.h"
#include <iostream>
using namespace std;

//#include <stdio.h>


#define PI 3.14159265

Tijera::Tijera(): Objeto() {
	alto = 0;
	ancho = 0;
	aspa1 = new Aspa();
	aspa2 = new Aspa();
	accionada = false;
}


Tijera::Tijera(float x, float y, float ancho, float alto): Objeto(x,y, new ValidadorEnArea(this)) {
	this->ancho = ancho;
	this->alto = alto;
	aspa1 = new Aspa(x, y,ancho, alto,-ANGULO_DEFECTO_ASPA,1,this);
	aspa2 = new Aspa(x,y, ancho,alto,ANGULO_DEFECTO_ASPA,2,this);
	accionada = false;

//	b2Rot rot(- b2_pi/4.0);
//	bRot rot2(b2_pi/4.0);
//	b2Vec2 pos(1,0);
//	b2Vec2 eng1 = b2Mul(rot,pos);
//	b2Vec2 eng2 = b2Mul(rot2,pos);
	Enganche* enganche1 = new Enganche(this->aspa1, 0.8 * ancho/2.0,0);
	Enganche* enganche2 = new Enganche(this->aspa2, 0.8 * ancho/2.0,0);
	enganches.push_back(enganche1);
	enganches.push_back(enganche2);
}

Tijera::Tijera(const Tijera& tijera){
	x = tijera.getX();
	y = tijera.getY();
	alto = tijera.getAlto();
	ancho = tijera.getAncho();
	body = tijera.body;
	aspa2 = tijera.aspa2;
	rotacion = tijera.getRotacion();
	//rotacionAspa1 = tijera.getRotacionAspa1();
	//rotacionAspa2 = tijera.getRotacionAspa2();
	vista = tijera.vista;
	this->reg = tijera.reg;
	aspa1 = new Aspa(x,y,ancho,alto,-ANGULO_DEFECTO_ASPA,1,this);
	aspa2 = new Aspa(x,y,ancho,alto,ANGULO_DEFECTO_ASPA,2,this);
	accionada = false;
	/*Enganche* enganche1 = new Enganche(this, (cos(PI/4.0))* ancho/2.0,(sin(PI/4.0))* ancho/2.0);
	Enganche* enganche2 = new Enganche(this, (cos(PI/4.0))* ancho/2.0, -(sin(PI/4.0))* ancho/2.0);
	enganches.push_back(enganche1);
	enganches.push_back(enganche2);*/
}

Tijera::~Tijera() {
	delete aspa1;
	delete aspa2;
}

float Tijera::getAlto() const{
	return this->alto;
}

float Tijera::getAncho() const{
	return this->ancho;
}

void Tijera::setAlto(float alto){
	this->alto = alto;
}

void Tijera::setAncho(float ancho){
	this->ancho = ancho;
}

void Tijera::crearFisica(){
	this->aspa1->crearFisica();
	this->aspa2->crearFisica();
	b2RevoluteJointDef rjd;
	rjd.bodyA = aspa1->getBody();
	rjd.bodyB = aspa2->getBody();
	rjd.collideConnected = false;
	rjd.enableLimit = false;
	rjd.localAnchorA = b2Vec2_zero;
	rjd.localAnchorB = b2Vec2_zero;
	myWorld->CreateJoint(&rjd);
//	//gearJoint entre las aspas
	b2GearJointDef gear_joint;
//	gear_joint.bodyA = this->aspa1->getBody();
//	gear_joint.bodyB = this->aspa2->getBody();
//	gear_joint.joint1 = this->aspa1->getJoint();//jointAspa1ATierra;
//	gear_joint.joint2 = this->aspa1->getJoint();//jointAspa2ATierra;
//	gear_joint.ratio =  -1;
//	myWorld->CreateJoint(&gear_joint);

}

void Tijera::acept(VisitorFigura* visitor){
	visitor->visit(this);
}


void Tijera::crearFisicaEstaticaTemplate(b2World * w, b2Body* ground){
	this->aspa1->crearFisicaEstaticaTemplate(w,ground);
	this->aspa2->crearFisicaEstaticaTemplate(w,ground);
}



bool Tijera::crearFisicaEstatica() {
	if (myWorld != NULL) {
		this->crearFisicaEstaticaTemplate(this->myWorld,this->ground);
		bool hayContacto = false;
		for (b2Body* b = myWorld->GetBodyList(); b; b = b->GetNext()) {
			if (b != this->aspa1->getBody() && b != this->aspa2->getBody() && b->GetFixtureList() != NULL && b->GetFixtureList()->GetShape() != NULL) {
				if (validarContacto(this->aspa1->getBody(), b) || validarContacto(this->aspa1->getBody(), b) || validarContacto(this->aspa2->getBody(),b)) {
					hayContacto = true;
					break;
				}
			}
		}
		if (hayContacto) {
			removerFisica();
		} else {
			notify(FISICA_E_CREADA);
		}
		return !hayContacto;
	} else {
		return false;
	}
}

void Tijera::removerFisica(){
	this->aspa1->removerFisica();
	this->aspa2->removerFisica();
}

void Tijera::setRotacion(double angulo){
	super::setRotacion(angulo);
	this->aspa1->setRotacion(this->rotacion - ANGULO_DEFECTO_ASPA);
	this->aspa2->setRotacion(this->rotacion + ANGULO_DEFECTO_ASPA);
}

void Tijera::updateModelo(){
	this->aspa1->updateModelo();
	this->aspa2->updateModelo();
}

void Tijera::setPosicion(float x, float y) {
	super::setPosicion(x,y);
	aspa1->setPosicion(x,y);
	aspa2->setPosicion(x,y);

}

void Tijera::setWorld(b2World* w, b2Body* ground) {
	super::setWorld(w,ground);
	aspa1->setWorld(w,ground);
	aspa2->setWorld(w,ground);
}

void Tijera::makeBackUp() {
	aspa1->makeBackUp();
	aspa2->makeBackUp();
}

void Tijera::restoreBackUp() {
	aspa1->restoreBackUp();
	aspa2->restoreBackUp();
	accionada = false;
}

void Tijera::setNumeroJugador(int int1) {
	super::setNumeroJugador(int1);
	aspa1->setNumeroJugador(int1);
	aspa2->setNumeroJugador(int1);
}

b2Body* Tijera::getBody() {
	return super::getBody();
}

void Tijera::accionar() {
	Mapa * m = (Mapa*)ground->GetUserData();
	cout<< "accionada la tijera" << endl;

	// creo un body para poder enviar el corte.
	b2PolygonShape * shape= new b2PolygonShape();
//	shape->SetAsBox(this->ancho/4,this->alto/2);
	shape->SetAsBox(this->ancho/2,this->alto/2);
	b2FixtureDef fixture;
	fixture.filter.categoryBits = CATEGORIA_CUERPO_CORTE_TIJERA;
	fixture.filter.maskBits = CATEGORIA_CUERPO_CORTE_TIJERA;
	fixture.density = 2.00f;
	fixture.shape = shape;
	fixture.friction = 0.01f;
	fixture.restitution = 0.00f;
	b2BodyDef bodyDef;
	bodyDef.type = b2_dynamicBody;
//	b2Vec2 posAbsoluta = b2MulT(rotacion, posRelativa);
//	posAbsoluta= b2Vec2(posAbsoluta.x +x, posAbsoluta.y +y);
//	bodyDef.position = posAbsoluta;
	bodyDef.position.Set(this->x,this->y);
	bodyDef.angle = 0;
	//bodyDef.fixedRotation = true;
//	double rotacionRad = this->getRotacion() * -1*b2_pi / 180.0;
//	bodyDef.angle = rotacionRad;
	b2Body* body = myWorld->CreateBody(&bodyDef);
	body->CreateFixture(&fixture);
	body->SetUserData(this);
	m->cortarUniones(body);
	myWorld->DestroyBody(body);

}

float Tijera::getRotacionAspa1() {
	return aspa1->getRotacion();
}

float Tijera::getRotacionAspa2() {
	return aspa2->getRotacion();
}
