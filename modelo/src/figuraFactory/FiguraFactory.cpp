/*
 * FiguraFactory.cpp
 *
 *  Created on: 04/09/2013
 *      Author: jonathan
 */

#include "FiguraFactory.h"
#include "../objeto/Motor.h"
#include "../objeto/Plataforma.h"
#include "../objeto/GloboHelio.h"
#include "../objeto/CintaTransportadora.h"
#include "../objeto/BolaBoliche.h"
#include "../objeto/PelotaJuego.h"
#include "../objeto/Balancin.h"

FiguraFactory::FiguraFactory(Rotador * rotador) {
	this->rotador = rotador;

}

FiguraFactory::~FiguraFactory() {
	// TODO Auto-generated destructor stub
}


Figura* FiguraFactory::crearMotor(float x, float y){
	return new Motor(x,y,10,5);
}

Figura* FiguraFactory::crearGloboHelio(float x, float y){
	return new GloboHelio(x,y,5);
}

Figura* FiguraFactory::crearPlataforma(float x, float y){
	return new Plataforma(x,y,10,5);
}

Figura* FiguraFactory::crearBalancin(float x, float y){
	return new Balancin(x,y,34,5);
}

Figura* FiguraFactory::crear(Plataforma* c) {
	Plataforma* y = (Plataforma*)this->crearPlataforma(c->getX(), c->getY());
	y->setRotacion(c->getRotacion());
	y->setAncho(c->getAncho());
	y->setReg(c->getReg());
	return y;
}

Figura* FiguraFactory::crear(Balancin* c) {
	Figura* y = this->crearBalancin(c->getX(), c->getY());
	y->setRotacion(c->getRotacion());
	y->setReg(c->getReg());
	return y;
}




Figura* FiguraFactory::crearCintaTransportadora(float x, float y) {
	return new CintaTransportadora(x,y,100);
}

Figura* FiguraFactory::crear(CintaTransportadora* cinta) {
	Figura* t = this->crearCintaTransportadora(cinta->getX(), cinta->getY());
	t->setRotacion(0);
	t->setReg(cinta->getReg());
	return t;
}
Figura* FiguraFactory::crearBolaBoliche(float x, float y) {
	return new BolaBoliche(x,y,5);
}



Figura* FiguraFactory::crear(BolaBoliche* c) {
	Figura* t = this->crearBolaBoliche(c->getX(), c->getY());
		t->setRotacion(c->getRotacion());
		t->setReg(c->getReg());
		return t;
}

Figura* FiguraFactory::crearPelotaJuego(float x, float y) {
	return new PelotaJuego(x, y, 4.9);
}


Figura* FiguraFactory::crear(PelotaJuego* c) {
	Figura* t = this->crearPelotaJuego(c->getX(), c->getY());
		t->setRotacion(c->getRotacion());
		t->setReg(c->getReg());
		return t;
}

Figura* FiguraFactory::crear(GloboHelio*c) {
	Figura* t = this->crearGloboHelio(c->getX(), c->getY());
		t->setRotacion(0);
		t->setReg(c->getReg());
	return t;
}
