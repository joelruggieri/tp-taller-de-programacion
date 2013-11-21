/*
 * Yunque.cpp
 *
 *  Created on: 13/11/2013
 *      Author: ezequiel
 */

#include "Yunque.h"
#include <iostream>
#include "../Constantes.h"
Yunque::Yunque() : Objeto() {
	this->ancho = 0;
	this->alto = 0;
}

Yunque::Yunque(float x, float y, float w, float h) : Objeto(x,y){
	this->ancho = w;
	this->alto = h;
	this->enganches.push_back(new Enganche(this,0,this->alto * 0.45));
}

Yunque::~Yunque() {
	// TODO Auto-generated destructor stub
}

Yunque::Yunque(const Yunque& figura):Objeto(figura) {
	this->x = figura.getX();
	this->y = figura.getY();
	this->enganches.push_back(new Enganche(this,0,this->alto * 0.45));
//	alto = figura.alto;

	this->ancho = (figura.getAncho());
	this->alto = (figura.getAlto());
//	ancho = figura.ancho;
	this->reg = figura.reg;
}

void Yunque::crearFisica() {
	float x = this->getX();
		float y = this->getY();
		b2Vec2 centro(x, y);
		b2PolygonShape shape;
		b2Vec2 vertices[4];
		vertices[0].Set(-ancho/2,-alto/2);
		vertices[1].Set(ancho/2,-alto/2);
		vertices[2].Set(ancho*0.4,alto/2);
		vertices[3].Set(-ancho*0.4,alto/2);
		shape.Set(vertices, 4);
		b2BodyDef bodyDef;
		bodyDef.type = b2_dynamicBody;
		bodyDef.position.Set(centro.x, centro.y);
		bodyDef.angle = this->getRotacion() * -b2_pi / 180.0;
		b2Body* body = myWorld->CreateBody(&bodyDef);
		b2FixtureDef bodyPelota;
		bodyPelota.filter.categoryBits = CATEGORIA_FIGURAS;
		bodyPelota.filter.maskBits = CATEGORIA_FIGURAS;
		bodyPelota.shape = &shape;
		bodyPelota.density = 18.0f;
		bodyPelota.friction = 0.4f;
		bodyPelota.restitution = 0.0f;	//mucho coeficiente de restitucion
		body->CreateFixture(&bodyPelota)->SetUserData(this);
		body->SetUserData(this);
		this->setBody(body);

}

void Yunque::acept(VisitorFigura* v) {
	v->visit(this);
}

float Yunque::getAlto() const {
	return alto;
}

void Yunque::setAlto(float alto) {
	this->alto = alto;
}

float Yunque::getAncho() const {
	return ancho;
}

void Yunque::setAncho(float ancho) {
	this->ancho = ancho;
}
void Yunque::recibirImpacto(b2Vec2 direccion) {
	this->realizarImpacto(direccion);
}
