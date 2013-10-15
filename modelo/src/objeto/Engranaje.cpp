/*
 * Engranaje.cpp
 *
 *  Created on: 11/10/2013
 *      Author: javier
 */

#include "Engranaje.h"
#include "../Constantes.h"
#include <iostream>
using namespace std;

//TODO DELETEAR EL GEAR JOINT ANTES DE SACAR CADA ENGRANAJE.
Engranaje::Engranaje(float x, float y, float radio): Objeto(x,y) {
	this->radio = radio;
	this->radioAccion = NULL;
	this->direccion = 0;
	this->jointCuerpoTierra = NULL;
	this->traccionable = true;
}

Engranaje::~Engranaje() {
	// TODO Auto-generated destructor stub
}

void Engranaje::crearFisica(b2World* w, b2Body* ground) {



	//definicion del cuerpo del engranaje.
	b2Vec2 centro(x,y);
	b2CircleShape shapeCuerpo;
	shapeCuerpo.m_radius = this->radio ;
	b2FixtureDef fixture;
	fixture.density = 1.00f;
	fixture.shape = &shapeCuerpo;
	fixture.friction = 0.01f;
	fixture.restitution = 0.00f;
	fixture.filter.categoryBits = CATEGORIA_FIGURAS;
	fixture.filter.maskBits = CATEGORIA_FIGURAS;
	b2BodyDef bodyDefCuerpo;
	bodyDefCuerpo.type = b2_dynamicBody;
	bodyDefCuerpo.position= centro;
	body = w->CreateBody(&bodyDefCuerpo);
	body->CreateFixture(&fixture);
	body->SetUserData(this);

	//joint cuerpo con la tierra;
	b2RevoluteJointDef jointCuerpoTierraDef;
	jointCuerpoTierraDef.Initialize(ground,body,centro);
//	jointCuerpoTierraDef.collideConnected = false;
	jointCuerpoTierra = (b2RevoluteJoint*)w->CreateJoint(&jointCuerpoTierraDef);

	//definicion cuerpo radio de accion

	b2CircleShape shapeAccion;
	shapeAccion.m_radius = this->radio + 0.3;
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
	radioAccion = w->CreateBody(&bodyDefAccion);
	radioAccion->CreateFixture(&fixtureAccion);
	radioAccion->SetUserData(this);

	//joint radio de accion con la tierra;
	b2RevoluteJointDef rjd2;
	rjd2.Initialize(ground,radioAccion,centro);
	rjd2.collideConnected = false;
	w->CreateJoint(&rjd2);

	for (b2Body* b = w->GetBodyList(); b; b = b->GetNext()) {
		if (b != this->body && b!= this->radioAccion && b->GetFixtureList()!= NULL  && b->GetFixtureList()->GetShape() != NULL){
//			//solo da que si cuando golpea con otro radio de accion
			if(validarContacto(w,this->radioAccion,b)){
				crearLazo((Engranaje *) b->GetUserData(),w);
			}

		}
	}
}

void Engranaje::acept(VisitorFigura* visitor) {
	visitor->visit(this);
}

void Engranaje::crearFisicaEstaticaTemplate(b2World* m, b2Body* ground) {
	this->crearFisica(m,ground);

}

void Engranaje::removerFisica(b2World* w) {
	w->DestroyBody(this->body);
	w->DestroyBody(this->radioAccion);

	this->body = NULL;
	radioAccion = NULL;
}

void Engranaje::crearLazo(Engranaje * b, b2World* w) {
//    b2RevoluteJointDef the_rev_joint = new b2RevoluteJointDef();

//	the_rev_joint.Initialize(ground, body, body->GetPosition());
//	b2RevoluteJoint first_joint = (b2RevoluteJoint) w->CreateJoint(the_rev_joint);
//    the_rev_joint.Initialize(wground.GetGroundBody(), gear2, new b2Vec2(11,6.5));
//    var second_joint:b2RevoluteJoint=m_world.CreateJoint(the_rev_joint) as b2RevoluteJoint;
    // gear joint
    b2GearJointDef  gear_joint;
    gear_joint.bodyA=this->getDiscoGiro();
    gear_joint.bodyB= b->getDiscoGiro();
    gear_joint.joint1= this->getJointATierra();
    gear_joint.joint2= b->getJointATierra();
    gear_joint.ratio= 1.0f;
    w->CreateJoint(&gear_joint);


}


bool Engranaje::crearFisicaEstatica(b2World* w, b2Body* ground) {
	this->crearFisicaEstaticaTemplate(w,ground);
	bool hayContacto = false;
//	list<Engranaje *> maquinas;
	for (b2Body* b = w->GetBodyList(); b && !hayContacto; b = b->GetNext()) {
		if (b != this->body && b!= this->radioAccion && b->GetFixtureList()!= NULL  && b->GetFixtureList()->GetShape() != NULL){
			if(validarContacto(w,body,b)){
				hayContacto = true;
				break;
			}
//			//solo da que si cuando golpea con otro radio de accion
//			if(validarContacto(w,this->radioAccion,b)){
//				maquinas.push_back((Engranaje*)b->GetUserData());
//			}

		}
	}
	if(hayContacto) {
		removerFisica(w);
//	} else {
//		if(maquinas.size() > 0){
//			list<Engranaje*>::iterator it;
//			for(it=maquinas.begin(); it != maquinas.end(); ++it){
//				crearLazo(*it,w);
//			}
//		}
	}


	return !hayContacto;

}

b2RevoluteJoint* & Engranaje::getJointATierra() {
	return this->jointCuerpoTierra;
}

b2Body* Engranaje::getDiscoGiro() {
	return this->body;
}

void Engranaje::modificarSentido() {
	if(direccion == 1){
		direccion = -1;
	} else{
		direccion =  direccion == -1 ? 1 : 0;
	}
}

Engranaje::Engranaje(const Engranaje& engranaje):Objeto(engranaje) {
	this->direccion = engranaje.direccion;
	traccionable = true;
}

Engranaje::Engranaje() {
}

int Engranaje::getDireccion() const {
	return this->direccion;
}

void Engranaje::setDireccion(int dir) {
	this->direccion = dir;
}
