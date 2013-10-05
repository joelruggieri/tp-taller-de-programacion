/*
 * GloboHelio.cpp
 *
 *  Created on: 02/10/2013
 *      Author: ezequiel
 */

#include "GloboHelio.h"

GloboHelio::GloboHelio(float x, float y, float radio) : Objeto(x,y){
	this->radio = radio ;

}

GloboHelio::~GloboHelio() {
	// TODO Auto-generated destructor stub
}

void GloboHelio::crearFisica(b2World* world) {
	float x = this->getX();
		float y = this->getY();
		b2Vec2 centro(x,y);
		b2CircleShape shapeCircle;


			b2BodyDef bodyDef;
			bodyDef.type = b2_dynamicBody;
			bodyDef.position.Set(centro.x, centro.y);
			bodyDef.angle = this->getRotacion() * -3.14 / 180.0;
			b2Body* body = world->CreateBody(&bodyDef);
			shapeCircle.m_radius = this->radio ;
			b2FixtureDef bodyBolaBoliche;
			bodyBolaBoliche.shape = &shapeCircle;
			bodyBolaBoliche.density = 0.5f;	//poca densidad, la densidad del aire cual es ?
			bodyBolaBoliche.friction = 0.2f;
			bodyBolaBoliche.restitution	 = 0.3f;
			body->CreateFixture(&bodyBolaBoliche);
			body->SetGravityScale(-1);//por ahora lo resuelvo asi
//			b2MassData masa;
//			masa.mass = 4; //chequear la cantidad de masa
//			masa.I = 0.005; // chequear inercia rotacional
//			body->SetMassData(&masa);	//centro de masa esta en el centro de la esfera por defecto
			body->SetUserData(this);
			this->setBody(body);

}

void GloboHelio::acept(VisitorFigura*) {
}


