/*
 * Union.cpp
 *
 *  Created on: 14/10/2013
 *      Author: jonathan
 */

#include "Union.h"

Union::Union(float x, float y):Objeto(x,y) {
	// TODO Auto-generated constructor stub

}

Union::~Union() {
	// TODO Auto-generated destructor stub
}

void Union::setFin(const b2Vec2& fin) {
	this->fin = fin;
}

void Union::setInicio(const b2Vec2& inicio) {
	this->inicio = inicio;
}

float Union::getXInicial() {
	return inicio.x;
}

float Union::getYInicial() {
	return inicio.y;
}

float Union::getXFinal() {
	return fin.x;
}

float Union::getYFinal() {
	return fin.y;
}

float Union::calcularDistancia(b2Vec2 a, b2Vec2 b) {
	 return (float)sqrt(pow((a.x - b.x),2) + pow((a.y - b.y),2));
}

void Union::calcularCentroCuadrado() {
	this->x= (this->inicio.x + this->fin.x)/2;
	this->y= (this->inicio.y + this->fin.y)/2;
}

void Union::calcularAnguloCuadrado() {
	b2Vec2 dist1, dist2, dist3, dist4;
dist1.x = 0;
dist1.y = this->fin.y;
dist2.x = 0;
dist2.y = this->inicio.y;
dist3.x = this->fin.x;
dist3.y = 0 ;
dist4.x = this->inicio.x;
dist4.y= 0;
this->rotacion = -atan(calcularDistancia(dist1, dist2)/ calcularDistancia(dist3, dist4));
}

void Union::setFiguraInicio(Figura* a) {
	this->figuraInicio = a;
	this->inicio.x = a->getX();
	this->inicio.y = a->getY();
}

void Union::setFiguraFin(Figura* a) {
	this->figuraFin = a;
	this->fin.x = a->getX();
	this->fin.y = a->getY();
}

void Union::setExtremos(Figura* a, Figura* b) {
	this->setFiguraInicio(a);
	this->setFiguraFin(b);
	this->calcularAnchoCuadrado();
	this->calcularAnguloCuadrado();
	this->calcularCentroCuadrado();

}

void Union::calcularAnchoCuadrado() {
	this->w = this->calcularDistancia(this->inicio, this->fin);
}

void Union::crearFisicaEstaticaTemplate(b2World* w, b2Body* ground) {
b2Vec2 centro(x,y);
	b2PolygonShape cuadrado;
	b2BodyDef bodyDef;

//	bodyDef.type = b2_dynamicBody;	//dynamic??
	bodyDef.position = centro;
	bodyDef.angle = this->rotacion;
	bodyDef.fixedRotation = true;
	b2Body* body = w->CreateBody(&bodyDef);
	cuadrado.SetAsBox(this->w,this->h);
	b2FixtureDef bodyCuadrado;
	bodyCuadrado.shape = &cuadrado;
	bodyCuadrado.filter.categoryBits = CATEGORIA_CORREA;	//TODO cambiar categorias
	bodyCuadrado.filter.maskBits = CATEGORIA_CORREA;
	body->CreateFixture(&bodyCuadrado);
	  this->crearFisica(w,ground);

}

void Union::setFin(float x, float y) {
	this->setFin(b2Vec2(x,y));
}
