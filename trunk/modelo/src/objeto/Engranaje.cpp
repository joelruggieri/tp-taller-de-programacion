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
}

Engranaje::~Engranaje() {
	// TODO Auto-generated destructor stub
}

void Engranaje::crearFisica(b2World* m_world, b2Body* ground) {

	b2CircleShape eje;
	eje.m_radius = 0.5f;

	b2CircleShape circle;
	circle.m_radius = RADIO_ENGRANAJE;

	b2BodyDef bd;
	bd.type = b2_staticBody;
	bd.position.Set(getX(), getY());
	cuerpoEje = m_world->CreateBody(&bd);
	cuerpoEje->CreateFixture(&eje, 1.0f);

	b2FixtureDef fd;
	fd.shape = &circle;
	fd.density = 1.0f;
	fd.friction = 1.0f;

	bd.position.Set(getX(), getY());
	bd.type = b2_dynamicBody;
	cuerpoRueda = m_world->CreateBody(&bd);
	cuerpoRueda->CreateFixture(&fd);


	b2RevoluteJointDef jd1;
	jd1.Initialize(cuerpoEje, cuerpoRueda, bd.position);
	m_world->CreateJoint(&jd1);
	setBody(cuerpoRueda);
	cuerpoRueda->SetUserData(this);
}

void Engranaje::acept(VisitorFigura* visitor) {
	visitor->visit(this);
}

void Engranaje::crearFisicaEstaticaTemplate(b2World* m_world, b2Body* ground) {

	b2CircleShape circle;
	circle.m_radius = RADIO_ENGRANAJE+0.5f;

	b2BodyDef bd;

	b2FixtureDef fd;
	fd.shape = &circle;

	bd.position.Set(getX(), getY());
	b2Body* aux = m_world->CreateBody(&bd);
	aux->CreateFixture(&fd);
	setBody(aux);
	aux->SetUserData(this);
}

void Engranaje::crearLazo(b2Body* b, b2World* w) {
	b2GearJointDef gearJoint;
	gearJoint.bodyA = this->body;
	gearJoint.bodyB = b;
	gearJoint.joint1 = this->body->GetJointList()->joint;
	gearJoint.joint2 = b->GetJointList()->joint;
	gearJoint.ratio = 1; //chequear despues
	b2GearJoint* theGearJoint = (b2GearJoint*)w->CreateJoint(&gearJoint);	//TODO ver si hay que retornar este gearJoint
//	theGearJoint->m_type =

}
