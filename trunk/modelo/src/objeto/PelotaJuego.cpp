/*
 * PelotaJuego.cpp
 *
 *  Created on: 28/09/2013
 *      Author: jonathan
 */

#include "PelotaJuego.h"

PelotaJuego::PelotaJuego(float x, float y, float radio):Objeto(x,y) {
	this->radio = radio ;
}

PelotaJuego::~PelotaJuego() {
	// TODO Auto-generated destructor stub
}

void PelotaJuego::crearFisica(b2World* world) {
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
		b2FixtureDef bodyPelota;
		bodyPelota.shape = &shapeCircle;
		bodyPelota.density = 0.8f;
		bodyPelota.friction = 0.2f;
		bodyPelota.restitution	 = 0.85f;	//mucho coeficiente de restitucion
		body->CreateFixture(&bodyPelota);
//		b2MassData masa;
//		masa.mass = 5; //chequear la cantidad de masa
//		masa.I = 0.005; // chequear inercia rotacional
//		body->SetMassData(&masa);	//centro de masa esta en el centro de la esfera por defecto
		body->SetUserData(this);
		this->setBody(body);
}

void PelotaJuego::acept(VisitorFigura* visitor) {
	visitor->visit(this);
}
