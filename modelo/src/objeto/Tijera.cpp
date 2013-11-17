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
	rotacionAspa1 = -45;
	rotacionAspa2 = 45;

}


Tijera::Tijera(float x, float y, float ancho, float alto): Objeto(x,y) {
	this->ancho = ancho;
	this->alto = alto;
	this->rotacionAspa1 = -45;
	this->rotacionAspa2 = 45;
	b2Rot rot(- b2_pi/4.0);
	b2Rot rot2(b2_pi/4.0);
	b2Vec2 pos(1,0);
	b2Vec2 eng1 = b2Mul(rot,pos);
	b2Vec2 eng2 = b2Mul(rot2,pos);
	Enganche* enganche1 = new Enganche(this, eng1.x* ancho/2.0,(eng1.y)* ancho/2.0);
	Enganche* enganche2 = new Enganche(this, eng2.x* ancho/2.0,(eng2.y)* ancho/2.0);
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
	rotacionAspa1 = tijera.getRotacionAspa1();
	rotacionAspa2 = tijera.getRotacionAspa2();
	vista = tijera.vista;
	this->reg = tijera.reg;


	Enganche* enganche1 = new Enganche(this, (cos(PI/4.0))* ancho/2.0,(sin(PI/4.0))* ancho/2.0);
	Enganche* enganche2 = new Enganche(this, (cos(PI/4.0))* ancho/2.0, -(sin(PI/4.0))* ancho/2.0);
	enganches.push_back(enganche1);
	enganches.push_back(enganche2);
}

Tijera::~Tijera() {

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

	float x = this->getX();
	float y = this->getY();
	b2Vec2 centro(x,y);
	b2PolygonShape * polygon= new b2PolygonShape();
	//b2MassData masa;
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
	rjd.collideConnected = false;
	//aspa1
	if((this->getRotacionAspa1() == 0) || (this->getRotacionAspa1() == -90) || (this->getRotacionAspa1() == -180) || (this->getRotacionAspa1() == -270)){
		rjd.lowerAngle = 0;
		rjd.upperAngle = 0.25f * b2_pi;
	}else if((this->getRotacionAspa1() == -45) || (this->getRotacionAspa1() == -135) || (this->getRotacionAspa1() == -225) || (this->getRotacionAspa1() == -315)  ){
		rjd.lowerAngle = -0.25f * b2_pi;
		rjd.upperAngle = 0;
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
	if((this->getRotacionAspa2() == 0) || (this->getRotacionAspa2() == -90) || (this->getRotacionAspa2() == -180) || (this->getRotacionAspa2() == -270)){
		rjd.lowerAngle = -0.25f * b2_pi;
		rjd.upperAngle = 0;
	}else if((this->getRotacionAspa2() == 45) || (this->getRotacionAspa2() == -45) || (this->getRotacionAspa2() == -135) || (this->getRotacionAspa2() == -225)){
		rjd.lowerAngle = 0;
		rjd.upperAngle =  0.25f * b2_pi;
	}
	rjd.enableLimit = true;
	b2RevoluteJoint* jointAspa2ATierra = (b2RevoluteJoint*) myWorld->CreateJoint(&rjd2);

	//gearJoint entre las aspas
	b2GearJointDef gear_joint;
	gear_joint.bodyA = this->getBody();
	gear_joint.bodyB = this->getbodyAspa2();
	gear_joint.joint1 = jointAspa1ATierra;
	gear_joint.joint2 = jointAspa2ATierra;
	gear_joint.ratio =  -1;
	myWorld->CreateJoint(&gear_joint);

}

void Tijera::acept(VisitorFigura* visitor){
	visitor->visit(this);
}


void Tijera::crearFisicaEstaticaTemplate(b2World * w, b2Body* ground){
	float x = this->getX();
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
	this->setBodyAspa2(body2);
}


double Tijera::getRotacionAspa2() const {
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
}

bool Tijera::crearFisicaEstatica() {
	if (myWorld != NULL) {
		this->crearFisicaEstaticaTemplate(this->myWorld,this->ground);
		bool hayContacto = false;
		for (b2Body* b = myWorld->GetBodyList(); b; b = b->GetNext()) {
			if (b != this->body && b != this->aspa2 && b->GetFixtureList() != NULL && b->GetFixtureList()->GetShape() != NULL) {
				if (validarContacto(this->body, b) || validarContacto(this->aspa2,b)) {
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
	super::removerFisica();
	if (aspa2 != NULL) {
			//notify(FISICA_REMOVIDA);
			myWorld->DestroyBody(this->getbodyAspa2());
		}
		this->setBodyAspa2(NULL);
}

void Tijera::setRotacion(double angulo){
	super::setRotacion(angulo);
	this->setRotacionAspa1(this->rotacion - 45);
	this->setRotacionAspa2(this->rotacion + 45);
}
