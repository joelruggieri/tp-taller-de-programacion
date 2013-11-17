/*
 * Aspa.cpp
 *
 *  Created on: 17/11/2013
 *      Author: joel
 */

#include "Aspa.h"
#include <math.h>
#include "../Constantes.h"
Aspa::Aspa(): Objeto() {
	alto = 0;
	ancho = 0;
	numeroAspa = 0;
	tijera = NULL;

}


Aspa::Aspa(float x, float y, float ancho, float alto, double rotacion,int numero,Tijera* tijera): Objeto(x,y) {
	this->ancho = ancho;
	this->alto = alto;
	this->rotacion = rotacion;
	this->numeroAspa = numero;
	this->tijera = tijera;
	this->numeroJugadorDuenio = tijera->getNumeroJugador();
	float rotacionEnRadianes = this->gradosARadianes(rotacion);
	//Enganche* enganche= new Enganche(this,cos(rotacionEnRadianes)*ancho/2.0,sin(rotacionEnRadianes)*ancho/2.0);
	//enganches.push_back(enganche);
}


Aspa::~Aspa() {

}

float Aspa::getAlto() const{
	return this->alto;
}

float Aspa::getAncho() const{
	return this->ancho;
}

void Aspa::setAlto(float alto){
	this->alto = alto;
}

void Aspa::setAncho(float ancho){
	this->ancho = ancho;
}

void Aspa::crearFisica(){
	float x = this->getX();
	float y = this->getY();
	b2Vec2 centro(x,y);
	b2PolygonShape * polygon= new b2PolygonShape();
	polygon->SetAsBox(this->ancho/2,this->alto/2);
	b2FixtureDef fixture;
	fixture.filter.categoryBits = CATEGORIA_FIGURAS;
	fixture.filter.maskBits = CATEGORIA_FIGURAS;
	fixture.density = 2.00f;
	fixture.shape = polygon;
	fixture.friction = 0.01f;
	fixture.restitution = 0.00f;
	b2BodyDef bodyDef;
	bodyDef.type = b2_dynamicBody;
	bodyDef.position.Set(x,y);
	//bodyDef.fixedRotation = true;
	double rotacionRad = this->getRotacion() * -1*b2_pi / 180.0;
	bodyDef.angle = rotacionRad;
	b2Body* bodyAspa = myWorld->CreateBody(&bodyDef);
	bodyAspa->CreateFixture(&fixture);
	bodyAspa->SetUserData(this->tijera);
	this->setBody(bodyAspa);

	b2RevoluteJointDef rjd;
	double anguloAspa = this->getRotacion();
	if (numeroAspa == 1){
		if((anguloAspa == 0) || (anguloAspa == -90) || (anguloAspa == -180) || (anguloAspa == -270)){
			rjd.lowerAngle = 0;
			rjd.upperAngle= 0.25f * b2_pi;
		}else if((anguloAspa == -45) || (anguloAspa == -135) || (anguloAspa == -225) || (anguloAspa == -315)  ){
			rjd.lowerAngle = -0.25f * b2_pi;
			rjd.upperAngle = 0;
		}
	}else if(numeroAspa == 2){
		if((anguloAspa == 0) || (anguloAspa == -90) || (anguloAspa == -180) || (anguloAspa == -270)){
			rjd.lowerAngle = -0.25f * b2_pi;
			rjd.upperAngle = 0;
		}else if((anguloAspa == 45) || (anguloAspa == -45) || (anguloAspa == -135) || (anguloAspa == -225)){
			rjd.lowerAngle = 0;
			rjd.upperAngle =  0.25f * b2_pi;
		}
	}
	rjd.Initialize(ground,bodyAspa,centro);
	rjd.collideConnected = false;
	rjd.enableLimit = true;
	this->jointCuerpoTierra = (b2RevoluteJoint*) myWorld->CreateJoint(&rjd);
}

b2RevoluteJoint* Aspa::getJoint(){
	return this->jointCuerpoTierra;

}

void Aspa::crearFisicaEstaticaTemplate(b2World * w, b2Body* ground){
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

	double rotacionRad = this->getRotacion()* -3.14 / 180.0;
	bodyDef.angle = rotacionRad;
	b2Body* body = w->CreateBody(&bodyDef);
	body->CreateFixture(&fixture);
	body->SetUserData(this->tijera);
	this->setBody(body);

}

void Aspa::acept(VisitorFigura*){

}

