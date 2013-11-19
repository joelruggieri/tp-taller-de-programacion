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
	aspa1 = new Aspa(x, y,ancho, alto,-35,1,this);
	aspa2 = new Aspa(x,y, ancho,alto,35,2,this);
	accionada = false;

//	b2Rot rot(- b2_pi/4.0);
//	bRot rot2(b2_pi/4.0);
//	b2Vec2 pos(1,0);
//	b2Vec2 eng1 = b2Mul(rot,pos);
//	b2Vec2 eng2 = b2Mul(rot2,pos);
	Enganche* enganche1 = new Enganche(this->aspa1, 0.9 * ancho/2.0,0.1*alto/2.0);
	Enganche* enganche2 = new Enganche(this->aspa2, 0.9 * ancho/2.0,0.1*alto/2.0);
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
	aspa1 = new Aspa(x,y,ancho,alto,-45,1,this);
	aspa2 = new Aspa(x,y,ancho,alto,45,2,this);
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
	//rjd.enableLimit = true;
	//b2RevoluteJoint* jointAspa2ATierra = (b2RevoluteJoint*) myWorld->CreateJoint(&rjd2);*/

//	//gearJoint entre las aspas
//	b2GearJointDef gear_joint;
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
	/*float x = this->getX();
	float y = this->getY();
	b2Vec2 centro(x, y);

	//ASPA1
	b2PolygonShape * polygon = new b2PolygonShape();


	polygon->SetAsBox(this->ancho / 2, this->alto / 2);
	b2FixtureDef fixture;
	fixture.shape = polygon;
	fixture.filter.categoryBits = CATEGORIA_FIGURAS;
	b2BodyDef bodyDef;
	bodyDef.type = b2_staticBody;
	bodyDef.position.Set(x, y);
	bodyDef.fixedRotation = true;

	double rotacionRad = -45 * -3.14 / 180.0;
	bodyDef.angle = rotacionRad;
	b2Body* body = w->CreateBody(&bodyDef);
	body->CreateFixture(&fixture);
	body->SetUserData(this);
	this->setBody(body);

	//ASPA 2
	b2PolygonShape * polygon2 = new b2PolygonShape();
	polygon2->SetAsBox(this->ancho / 2, this->alto / 2);
	b2FixtureDef fixture2;
	fixture2.shape = polygon2;
	fixture2.filter.categoryBits = CATEGORIA_FIGURAS;
	b2BodyDef bodyDef2;
	bodyDef2.type = b2_staticBody;
	bodyDef2.position.Set(x, y);
	bodyDef2.fixedRotation = true;

	double rotacionRad2 = 45 * -3.14 / 180.0;
	bodyDef2.angle = rotacionRad2;
	b2Body* body2 = w->CreateBody(&bodyDef2);
	body2->CreateFixture(&fixture2);
	body2->SetUserData(this);
	this->setBodyAspa2(body2);*/
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
	this->aspa1->setRotacion(this->rotacion - 45);
	this->aspa2->setRotacion(this->rotacion + 45);
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
//	b2Vec2 posRelativa(- ancho/4.0,0 );
//	b2Rot rotacion(this->getRotacion() * -1*b2_pi / 180.0);
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
