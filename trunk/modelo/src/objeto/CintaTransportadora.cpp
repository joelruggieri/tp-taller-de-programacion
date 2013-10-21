/*
 * CintaTransportadora.cpp
 *
 *  Created on: 05/10/2013
 *      Author: javier
 */


#include "CintaTransportadora.h"
#include "../Constantes.h"
#include <Box2D/Box2D.h>

#define DEGTORAD 0.0174532925199432957f
#define RADTODEG 57.295779513082320876f


CintaTransportadora::CintaTransportadora(): Engranaje () {
	this->ancho = 0;
	this->alto = 0;
	this->anchoBack = this->ancho;
	this->rotacionEje = 0;
}

CintaTransportadora::~CintaTransportadora() {

}

void CintaTransportadora::crearFisica() {
	float x = this->getX();
	float y = this->getY();


	//CREO EL CUERPO QUE VA A HACER CONTACTO CON EL RESTO
	b2Vec2 centro(x, y);
	b2PolygonShape * polygon = new b2PolygonShape();

	b2MassData masa;
	polygon->SetAsBox(this->ancho / 2, this->alto / 2);
	b2FixtureDef fixture;
	fixture.density = 50.00f;
	fixture.shape = polygon;
	fixture.friction = 0.01f;
	fixture.restitution = 0.00f;
	fixture.filter.categoryBits = CATEGORIA_FIGURAS;
	fixture.filter.maskBits = CATEGORIA_FIGURAS;
	b2BodyDef bodyDef;
	bodyDef.type = b2_staticBody;
	bodyDef.position.Set(x, y);
	bodyDef.fixedRotation = true;

	double rotacionRad = this->getRotacion() * -1 *DEGTORAD;
	bodyDef.angle = rotacionRad;
	b2Body* body = myWorld->CreateBody(&bodyDef);
	body->CreateFixture(&fixture);
	body->SetUserData(this);
	this->setBody(body);

	// CREO EL DISCO QUE VA A GIRAR
	b2CircleShape shapeEngranaje;
	shapeEngranaje.m_radius = this->radio;
	b2FixtureDef fixtureEngranaje;
	fixtureEngranaje.density = 1.00f;
	fixtureEngranaje.shape = &shapeEngranaje;
	fixtureEngranaje.friction = 0.01f;
	fixtureEngranaje.restitution = 0.00f;
	fixtureEngranaje.filter.categoryBits = CATEGORIA_CENTRO_CINTA;
	fixtureEngranaje.filter.maskBits = CATEGORIA_CENTRO_CINTA;
	b2BodyDef bodyDefEngranaje;
	bodyDefEngranaje.type = b2_dynamicBody;
	bodyDefEngranaje.position = centro;
	bodyEngranaje = myWorld->CreateBody(&bodyDefEngranaje);
	bodyEngranaje->CreateFixture(&fixtureEngranaje);
	bodyEngranaje->SetUserData(this);

	//joint engranaje con la tierra;
	b2RevoluteJointDef jointEngranajeTierraDef;
	jointEngranajeTierraDef.Initialize(ground, bodyEngranaje, centro);
	jointEngranajeTierraDef.collideConnected = false;
	jointCuerpoTierra = (b2RevoluteJoint*) myWorld->CreateJoint(&jointEngranajeTierraDef);


 //radio de accion muy chico
	b2CircleShape shapeAccion;
	shapeAccion.m_radius = 0.1;
	b2FixtureDef fixtureAccion;
	fixtureAccion.filter.categoryBits = CATEGORIA_RANGO_ENGRANAJE;
	fixtureAccion.filter.maskBits = CATEGORIA_RANGO_ENGRANAJE;
	fixtureAccion.density = 1.00f;
	fixtureAccion.shape = &shapeAccion;
	fixtureAccion.friction = 0.01f;
	fixtureAccion.restitution = 0.00f;
	b2BodyDef bodyDefAccion;
	bodyDefAccion.type = b2_dynamicBody;
	bodyDefAccion.position = centro;
	radioAccion = myWorld->CreateBody(&bodyDefAccion);
	radioAccion->CreateFixture(&fixtureAccion);
	radioAccion->SetUserData(this);

	//joint radio de accion con la tierra;
	b2RevoluteJointDef rjd2;
	rjd2.Initialize(ground, radioAccion, centro);
	rjd2.collideConnected = false;
	myWorld->CreateJoint(&rjd2);

}

void CintaTransportadora::acept(VisitorFigura* visitor) {
	visitor->visit(this);
}

CintaTransportadora::CintaTransportadora(float x, float y, float ancho, float alto) : Engranaje(x,y,alto/2) {
	this->ancho = ancho;
	this->alto = alto;
	this->anchoBack = ancho;
	this->rotacionEje = 0;
}


CintaTransportadora::CintaTransportadora(const CintaTransportadora& figura):Engranaje(figura) {
	this->ancho = figura.ancho;
	this->anchoBack = ancho;
	this->alto = figura.alto;
	this->reg = figura.reg;
	this->rotacionEje = 0;
}




void CintaTransportadora::updateModelo() {
	Figura::updateModelo();
	this->rotacionEje = -1*radianesAGrados(bodyEngranaje->GetAngle());
}

void CintaTransportadora::setAncho(float ancho) {
	this->ancho = ancho;
}

float CintaTransportadora::getAncho() const {
	return this->ancho;
}

void CintaTransportadora::removerFisica() {
	super::removerFisica();
	myWorld->DestroyBody(this->bodyEngranaje);
	this->bodyEngranaje = NULL;
}

float CintaTransportadora::getAlto() const {
	return alto;
}

double CintaTransportadora::getRotacionEje() const {
	return this->rotacionEje;
}


void CintaTransportadora::estirar(float delta){
	this->ancho = ancho + delta;
	if (ancho < 15) {
		ancho = 15;
	}
	if (ancho > 50) {
		ancho = 50;
	}
}

void CintaTransportadora::setRotacion(double rot) {
}

void CintaTransportadora::makeBackUp() {
	super::makeBackUp();
	anchoBack = this->getAncho();
}

void CintaTransportadora::restoreBackUp() {
	super::restoreBackUp();
	ancho = anchoBack;
	rotacionEje = 0;
}
