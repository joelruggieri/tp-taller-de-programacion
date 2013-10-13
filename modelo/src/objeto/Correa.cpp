/*
 * Correa.cpp
 *
 *  Created on: 28/09/2013
 *      Author: jonathan
 */

#include "Correa.h"

Correa::Correa(float x, float y):Objeto(x,y){

}

Correa::~Correa() {
	// TODO Auto-generated destructor stub
}


void Correa::crearFisica(b2World* w, b2Body* ground) {
		b2Vec2 centro(x,y);

}

void Correa::crearLazo(Engranaje * a, Engranaje* b, b2World* w) {

	//    b2RevoluteJointDef the_rev_joint = new b2RevoluteJointDef();

	//	the_rev_joint.Initialize(ground, body, body->GetPosition());
	//	b2RevoluteJoint first_joint = (b2RevoluteJoint) w->CreateJoint(the_rev_joint);
	//    the_rev_joint.Initialize(wground.GetGroundBody(), gear2, new b2Vec2(11,6.5));
	//    var second_joint:b2RevoluteJoint=m_world.CreateJoint(the_rev_joint) as b2RevoluteJoint;
	    // gear joint
	    b2GearJointDef  gear_joint;
	    gear_joint.bodyA=a->getDiscoGiro();
	    gear_joint.bodyB= b->getDiscoGiro();
	    gear_joint.joint1= a->getJointATierra();
	    gear_joint.joint2= b->getJointATierra();
	    gear_joint.ratio=-1;
	    w->CreateJoint(&gear_joint);



}

void Correa::setInicio(b2Vec2 b2Vec2) {
	this->inicio = b2Vec2;
}

void Correa::setFin(b2Vec2 b2Vec2) {
	this->fin = b2Vec2;
}


