/*
 * Union.cpp
 *
 *  Created on: 14/10/2013
 *      Author: jonathan
 */

#include "Union.h"

Union::Union(float x, float y) :
		Objeto(x, y) {
	// TODO Auto-generated constructor stub

}

Union::Union() :
		Objeto() {

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

float Union::getXInicial() const {
	return inicio.x;
}

float Union::getYInicial() const {
	return inicio.y;
}

float Union::getXFinal() const {
	return fin.x;
}

float Union::getYFinal() const {
	return fin.y;
}

void Union::setXInicial(float xInicial) {
	this->inicio.x = xInicial;
}

void Union::setYInicial(float yInicial) {
	inicio.y = yInicial;
}

void Union::setXFinal(float xFinal) {
	fin.x = xFinal;
}

void Union::setYFinal(float yFinal) {
	fin.y = yFinal;
}

float Union::calcularDistancia(b2Vec2 a, b2Vec2 b) {
	return (float) sqrt(pow((a.x - b.x), 2) + pow((a.y - b.y), 2));
}

void Union::calcularCentroCuadrado() {
	this->x = (this->inicio.x + this->fin.x) / 2;
	this->y = (this->inicio.y + this->fin.y) / 2;
}

void Union::calcularAnguloCuadrado() {
	b2Vec2 dist1, dist2, dist3, dist4;
	dist1.x = 0;
	dist1.y = this->fin.y;
	dist2.x = 0;
	dist2.y = this->inicio.y;
	dist3.x = this->fin.x;
	dist3.y = 0;
	dist4.x = this->inicio.x;
	dist4.y = 0;
	float distanciaA = calcularDistancia(dist1, dist2);
	float distanciaB = calcularDistancia(dist3, dist4);
	if (distanciaB == 0)
	{
		this->rotacion = 0;
	}
	else
	this->rotacion = -atan(distanciaA/distanciaB);
}

//void Union::setFiguraInicio(Figura* a) {
//	this->figuraInicio = a;
//	this->inicio.x = a->getX();
//	this->inicio.y = a->getY();
//}
//
//void Union::setFiguraFin(Figura* a) {
//	this->figuraFin = a;
//	this->fin.x = a->getX();
//	this->fin.y = a->getY();
//}

void Union::calcularAnchoCuadrado() {
	this->w = this->calcularDistancia(this->inicio, this->fin);
}

void Union::crearFisicaEstaticaTemplate(b2World* w, b2Body* ground) {
	b2Vec2 centro(x, y);
	b2PolygonShape cuadrado;
	b2BodyDef bodyDef;

//	bodyDef.type = b2_dynamicBody;	//dynamic??
	bodyDef.position = centro;
	bodyDef.angle = this->rotacion;
	bodyDef.fixedRotation = true;
	body = w->CreateBody(&bodyDef);
	cuadrado.SetAsBox(this->w, this->h);
	b2FixtureDef bodyCuadrado;
	bodyCuadrado.shape = &cuadrado;
	bodyCuadrado.filter.categoryBits = CATEGORIA_CORREA;//TODO cambiar categorias
	bodyCuadrado.filter.maskBits = 0X0008;
	body->CreateFixture(&bodyCuadrado);

//	this->crearFisica(w, ground);

}

void Union::setExtremos(Figura* f1, Figura* f2) {
	setearPuntoInicial(f1);
	setearPuntoFinal(f2);
	updateCaracteristicas();
}

void Union::updateCaracteristicas() {

	this->calcularAnchoCuadrado();
	this->calcularAnguloCuadrado();
	this->calcularCentroCuadrado();
}

void Union::updateModelo() {
	this->updateCaracteristicas();
}
