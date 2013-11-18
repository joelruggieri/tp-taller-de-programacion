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
//#include <stdio.h>


#define PI 3.14159265

Tijera::Tijera(): Objeto() {
	alto = 0;
	ancho = 0;
	aspa1 = new Aspa();
	aspa2 = new Aspa();
}


Tijera::Tijera(float x, float y, float ancho, float alto): Objeto(x,y) {
	this->ancho = ancho;
	this->alto = alto;
	aspa1 = new Aspa(x, y,ancho, alto,-45,1,this);
	aspa2 = new Aspa(x,y, ancho,alto,45,2,this);

//	b2Rot rot(- b2_pi/4.0);
//	bRot rot2(b2_pi/4.0);
//	b2Vec2 pos(1,0);
//	b2Vec2 eng1 = b2Mul(rot,pos);
//	b2Vec2 eng2 = b2Mul(rot2,pos);
	Enganche* enganche1 = new Enganche(this->aspa1, ancho/2.0,0);
	Enganche* enganche2 = new Enganche(this->aspa2, ancho/2.0,0);
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
	/*float x = this->getX();
	float y = this->getY();
	b2Vec2 centro(x,y);
	b2PolygonShape * polygon= new b2PolygonShape();

	polygon->SetAsBox(this->ancho/2,this->alto/2);

	b2FixtureDef fixture;
	fixture.filter.categoryBits = CATEGORIA_FIGURAS;
	fixture.filter.maskBits = CATEGORIA_FIGURAS;
	fixture.density = 50.00f;
	fixture.shape = polygon;
	fixture.friction = 0.01f;
	fixture.restitution = 0.00f;
	b2BodyDef bodyDef;
	bodyDef.type = b2_dynamicBody;
	bodyDef.position.Set(x,y);
	//bodyDef.fixedRotation = true;
	double rotacionRad = this->getRotacionAspa1() * -1*b2_pi / 180.0;
	bodyDef.angle = rotacionRad;
	b2Body* bodyAspa1 = myWorld->CreateBody(&bodyDef);
	bodyAspa1->CreateFixture(&fixture);
	bodyAspa1->SetUserData(this);
	this->setBody(bodyAspa1);

	b2RevoluteJointDef rjd;
	rjd.Initialize(ground,bodyAspa1,centro);
//	rjd.motorSpeed = 1.0f * b2_pi;
//	rjd.maxMotorTorque = 10000.0f;
	//rjd.collideConnected = false;
	//aspa1
	double anguloAspa1 = this->aspa1->getRotacion();
	b2RevoluteJoint* revoluteJoint1 = (b2RevoluteJoint*)(this->aspa1->getJoint());
	if((anguloAspa1 == 0) || (anguloAspa1 == -90) || (anguloAspa1 == -180) || (anguloAspa1 == -270)){
		revoluteJoint1->m_lowerAngle = 0;
		(b2RevoluteJoint*)(this->aspa1->getJoint())->m_upperAngle= 0.25f * b2_pi;
	}else if((anguloAspa1 == -45) || (anguloAspa1 == -135) || (anguloAspa1 == -225) || (anguloAspa1 == -315)  ){
		(b2RevoluteJoint*)(this->aspa1->getJoint())->m_lowerAngle = -0.25f * b2_pi;
		(b2RevoluteJoint*)(this->aspa1->getJoint())->m_upperAngle = 0;
	}
	rjd.enableLimit = true;
	b2RevoluteJoint* jointAspa1ATierra = (b2RevoluteJoint*) myWorld->CreateJoint(&rjd);

	// aspa2
	b2PolygonShape * polygon2= new b2PolygonShape();
	polygon2->SetAsBox(this->ancho/2,this->alto/2);
	b2FixtureDef fixture2;
	fixture2.filter.categoryBits = CATEGORIA_FIGURAS;
	fixture2.filter.maskBits = CATEGORIA_FIGURAS;
	fixture2.density = 50.00f;
	fixture2.shape = polygon2;
	fixture2.friction = 0.01f;
	fixture2.restitution = 0.00f;
	b2BodyDef bodyDef2;
	bodyDef2.type = b2_dynamicBody;
	bodyDef2.position.Set(x,y);
	double rotacionRad2 = this->getRotacionAspa2() * -1*b2_pi / 180.0;
	bodyDef2.angle = rotacionRad2;
	b2Body* bodyAspa2 = myWorld->CreateBody(&bodyDef2);
	bodyAspa2->CreateFixture(&fixture2);
	bodyAspa2->SetUserData(this);
	this->setBodyAspa2(bodyAspa2);
	b2RevoluteJointDef rjd2;
	rjd2.Initialize(ground,bodyAspa2,centro);
	rjd2.collideConnected = false;
	double anguloAspa2 = this->aspa2->getRotacion();
	if((anguloAspa2 == 0) || (anguloAspa2 == -90) || (anguloAspa2 == -180) || (anguloAspa2 == -270)){
		(b2RevoluteJoint*)(this->aspa2->getJoint())->m_lowerAngle = -0.25f * b2_pi;
		(b2RevoluteJoint*)(this->aspa2->getJoint())->m_upperAngle = 0;
	}else if((anguloAspa2 == 45) || (anguloAspa2 == -45) || (anguloAspa2 == -135) || (anguloAspa2 == -225)){
		(b2RevoluteJoint*)(this->aspa2->getJoint())->m_lowerAngle = 0;
		(b2RevoluteJoint*)(this->aspa2->getJoint())->m_upperAngle =  0.25f * b2_pi;
	}
	//rjd.enableLimit = true;
	//b2RevoluteJoint* jointAspa2ATierra = (b2RevoluteJoint*) myWorld->CreateJoint(&rjd2);*/

	//gearJoint entre las aspas
	b2GearJointDef gear_joint;
	gear_joint.bodyA = this->aspa1->getBody();
	gear_joint.bodyB = this->aspa2->getBody();
	gear_joint.joint1 = this->aspa1->getJoint();//jointAspa1ATierra;
	gear_joint.joint2 = this->aspa1->getJoint();//jointAspa2ATierra;
	gear_joint.ratio =  -1;
	myWorld->CreateJoint(&gear_joint);

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


/*double Tijera::getRotacionAspa2() const {
	return rotacionAspa2;
}

double Tijera::getRotacionAspa1() const {
	return rotacionAspa1;
}

void Tijera::setBodyAspa2(b2Body* body){
	this->aspa2 = body;
}

void Tijera::setRotacionAspa2(double rotation) {
	this->rotacionAspa2 = rotation;
	//notify(CAMBIO_ESPACIAL_FORZADO);
}

void Tijera::setRotacionAspa1(double rotation) {
	this->rotacionAspa2 = rotation;
	//notify(CAMBIO_ESPACIAL_FORZADO);
}

b2Body* Tijera::getbodyAspa2(){
	return this->aspa2;
}*/

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
}

void Tijera::setNumeroJugador(int int1) {
	super::setNumeroJugador(int1);
	aspa1->setNumeroJugador(int1);
	aspa2->setNumeroJugador(int1);
}

b2Body* Tijera::getBody() {
	return super::getBody();
}
