/*
 * Motor.cpp
 *
 *  Created on: 28/09/2013
 *      Author: jonathan
 */
#include "Motor.h"
#include <iostream>
using namespace std;
#include "../Constantes.h"
Motor::Motor(float x, float y, float radio):Engranaje(x, y, radio) {
	this->direccion = 1 ; //por defecto gira en sentido horario
	this->traccionable = true;
}

Motor::~Motor() {
	// TODO Auto-generated destructor stub
}

void Motor::crearFisica() {


	//definicion del cuerpo del engranaje.
	b2Vec2 centro(x,y);
	b2CircleShape shapeCuerpo;
	shapeCuerpo.m_radius = this->radio ;
	b2FixtureDef fixture;
	fixture.density = 1.00f;
	fixture.shape = &shapeCuerpo;
	fixture.friction = 0.2f;
	fixture.restitution = 0.00f;
	fixture.filter.categoryBits = CATEGORIA_FIGURAS;
	fixture.filter.maskBits = CATEGORIA_FIGURAS;
	b2BodyDef bodyDefCuerpo;
	bodyDefCuerpo.type = b2_dynamicBody;
	bodyDefCuerpo.position= centro;
	body = myWorld->CreateBody(&bodyDefCuerpo);
	body->CreateFixture(&fixture);
	body->SetUserData(this);

	//joint cuerpo con la tierra;
	b2RevoluteJointDef rjd;
	rjd.Initialize(ground,body,centro);
	rjd.motorSpeed =  this->direccion == 1 ? 3 : -3;
	rjd.maxMotorTorque = 10000.0f;
	rjd.collideConnected = false;
	rjd.enableMotor = true;
	rjd.enableLimit = false;
	this->jointCuerpoTierra =(b2RevoluteJoint *) myWorld->CreateJoint(&rjd);

	//definicion cuerpo radio de accion

	b2CircleShape shapeAccion;
	shapeAccion.m_radius = this->radio +0.3;
	b2FixtureDef fixtureAccion;
	fixtureAccion.filter.categoryBits = 0X0004;
	fixtureAccion.filter.maskBits = 0X0004;
	fixtureAccion.density = 1.00f;
	fixtureAccion.shape = &shapeAccion;
	fixtureAccion.friction = 0.01f;
	fixtureAccion.restitution = 0.00f;
	b2BodyDef bodyDefAccion;
	bodyDefAccion.type = b2_dynamicBody;
	bodyDefAccion.position= centro;
	radioAccion = myWorld->CreateBody(&bodyDefAccion);
	radioAccion->CreateFixture(&fixtureAccion);
	radioAccion->SetUserData(this);

	//joint radio de accion con la tierra;
	b2RevoluteJointDef rjd2;
	rjd2.Initialize(ground,radioAccion,centro);
	rjd2.collideConnected = false;
	myWorld->CreateJoint(&rjd2);

	for (b2Body* b = myWorld->GetBodyList(); b; b = b->GetNext()) {
		if (b != this->body && b!= this->radioAccion && b->GetFixtureList()!= NULL  && b->GetFixtureList()->GetShape() != NULL){
//			//solo da que si cuando golpea con otro radio de accion
			if(validarContacto(this->radioAccion,b)){
				crearLazo((Engranaje *) b->GetUserData(),myWorld);
			}

		}
	}



}

void Motor::acept(VisitorFigura* visitor){
	visitor->visit(this);
}

Motor::Motor(const Motor& figura):Engranaje(figura) {
	this->x = figura.getX();
	this->y = figura.getY();
	this->setRotacion(figura.getRotacion());
	this->reg = figura.reg;
	this->direccion = figura.direccion;
	this->radio = radio;
}

Motor::Motor() {
	this->radio = 0;
}

