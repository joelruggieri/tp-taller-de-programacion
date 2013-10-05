/*
 * FiguraFactory.cpp
 *
 *  Created on: 04/09/2013
 *      Author: jonathan
 */

#include "FiguraFactory.h"
#include "../figura/Circulo.h"
#include "../figura/Rueda.h"
#include "../figura/Globo.h"
#include "../figura/Pelota.h"
#include "../objeto/Motor.h"
#include "../objeto/Plataforma.h"
#include "../objeto/Balancin.h"

FiguraFactory::FiguraFactory(Rotador * rotador) {
	this->rotador = rotador;

}

FiguraFactory::~FiguraFactory() {
	// TODO Auto-generated destructor stub
}

Figura* FiguraFactory::crearCirculo(float x, float y) {
	return new Circulo(x,y,4.3);
}

Figura* FiguraFactory::crearRueda(float x, float y) {
	return new Rueda(x,y,5);
}

Figura* FiguraFactory::crearGlobo(float x, float y){
	return new Globo(x,y,5);
}

Figura* FiguraFactory::crearPelota(float x, float y){
	return new Pelota(x,y,5);
}


Figura* FiguraFactory::crearMotor(float x, float y){
	return new Motor(x,y,10,5);
}

Figura* FiguraFactory::crearPlataforma(float x, float y){
	return new Plataforma(x,y,10,5);
}

Figura* FiguraFactory::crearBalancin(float x, float y){
	return new Balancin(x,y,10,5);
}

Figura* FiguraFactory::crear(Plataforma* c) {
	Figura* y = this->crearPlataforma(c->getX(), c->getY());
	y->setRotacion(c->getRotacion());
	return y;
}

Figura* FiguraFactory::crear(Balancin* c) {
	Figura* y = this->crearPlataforma(c->getX(), c->getY());
	y->setRotacion(c->getRotacion());
	return y;
}


Figura* FiguraFactory::crear(Rueda* c) {
	Figura* t = this->crearRueda(c->getX(), c->getY());
	t->setRotacion(c->getRotacion());
	return t;
}

Figura* FiguraFactory::crear(Globo* c) {
	Figura* t = this->crearGlobo(c->getX(), c->getY());
	t->setRotacion(c->getRotacion());
	return t;
}

Figura* FiguraFactory::crear(Pelota* c) {
	Figura* t = this->crearPelota(c->getX(), c->getY());
	t->setRotacion(c->getRotacion());
	return t;
}

Figura* FiguraFactory::crear(Circulo* c) {
	Figura* t = this->crearCirculo(c->getX(), c->getY());
	t->setRotacion(c->getRotacion());
	return t;
}

