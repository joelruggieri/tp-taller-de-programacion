/*
 * GloboHelio.cpp
 *
 *  Created on: 02/10/2013
 *      Author: ezequiel
 */

#include "GloboHelio.h"

GloboHelio::GloboHelio(float x, float y, float radio) : Objeto(x,y){
	this->radio = radio ;
	this->engancheBajo = new Enganche((int)x, (int)y - (int)radio);
	this->setRotacion(0);
}

GloboHelio::~GloboHelio() {
//	this->engancheBajo->~Enganche();
	if(this->engancheBajo != NULL)
	delete this->engancheBajo;

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
			bodyDef.fixedRotation = true;
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

			this->enganches.push_back((this->engancheBajo));
}

void GloboHelio::acept(VisitorFigura* visitor) {
	visitor->visit(this);
}

GloboHelio::GloboHelio(const GloboHelio&  figura) {
	this->x = figura.getX();
	this->y = figura.getY();
	this->setRotacion(figura.getRotacion());
	this->setRadio(figura.getRadio());
}

GloboHelio::GloboHelio():  Objeto() {
	this->radio = 0 ;
	this->engancheBajo = NULL;
}

float GloboHelio::getRadio() const{
	return radio;
}

void GloboHelio::setRadio(float radio) {
	this->radio = radio ;
}
