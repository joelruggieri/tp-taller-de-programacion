/*
 * Engranaje.cpp
 *
 *  Created on: 11/10/2013
 *      Author: javier
 */

#include "Engranaje.h"
#include "../Constantes.h"

Engranaje::Engranaje(int x, int y, int radio): Objeto(x,y) {
	this->radio = radio;
	this->radioAccion = NULL;
	this->direccion = 0;

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
	b2RevoluteJointDef rjd;
	rjd.Initialize(ground,body,centro);
	rjd.collideConnected = false;
	w->CreateJoint(&rjd);




	//definicion cuerpo radio de accion

	//definicion del cuerpo del engranaje.
	b2CircleShape shapeAccion;
	shapeAccion.m_radius = this->radio + 10 ;
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
//	radioAccion = NULL;
}

void Engranaje::crearLazo(b2Body* b, b2World* w) {
	b2GearJointDef gearJoint;
	gearJoint.bodyA = this->body;
	gearJoint.bodyB = b;
	gearJoint.joint1 = this->body->GetJointList()->joint;
	gearJoint.joint2 = b->GetJointList()->joint;
	gearJoint.ratio = 1; //chequear despues
	(b2GearJoint*)w->CreateJoint(&gearJoint);	//TODO ver si hay que retornar este gearJoint
//	theGearJoint->m_type =

}
//
//bool Engranaje::crearFisicaEstatica(b2World* w, b2Body* ground) {
//
//	bool hayContacto = false;
//	for (b2Body* b = w->GetBodyList(); b; b = b->GetNext()) {
//		if (b != body && b->GetFixtureList()!= NULL  && b->GetFixtureList()->GetShape() != NULL){
//
//
//			uint16 catA = body->GetFixtureList()->GetFilterData().categoryBits;
//			uint16 maskA = body->GetFixtureList()->GetFilterData().maskBits;
//			uint16 catB = b->GetFixtureList()->GetFilterData().categoryBits;
//			uint16 maskB = b->GetFixtureList()->GetFilterData().maskBits;
//
//			bool overlap = b2TestOverlap(body->GetFixtureList()->GetShape(), 0,
//					b->GetFixtureList()->GetShape(), 0, body->GetTransform(),
//					b->GetTransform()) && (catA & maskB) != 0 && (catB & maskA) != 0;
//			if(overlap ){
//				hayContacto = true;
//				break;
//			}
//		}
//	}
//	if (hayContacto) {
//		this->removerFisica(w);
//		return false;
//	}
//
//
//
//	return true;
//}
