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
#include "../objeto/Engranaje.h"
#include "../Constantes.h"
FiguraFactory::FiguraFactory(Rotador * rotador) {
	this->rotador = rotador;

}

FiguraFactory::~FiguraFactory() {
	// TODO Auto-generated destructor stub
}


Figura* FiguraFactory::crearMotor(float x, float y){
	return new Motor(x,y,5);
}

Figura* FiguraFactory::crearGloboHelio(float x, float y){
	return new GloboHelio(x,y,RADIO_GLOBO);
}

Figura* FiguraFactory::crearPlataforma(float x, float y){
	return new Plataforma(x,y,ANCHO_PLATAFORMA,ALTO_PLATAFORMA);
}

Figura* FiguraFactory::crearBalancin(float x, float y){
	return new Balancin(x,y,ANCHO_BALANCIN,ALTO_BALANCIN);
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




Figura* FiguraFactory::crearCintaTransportadora(float x, float y, int longitud) {
	return new CintaTransportadora(x,y,longitud);
}

Figura* FiguraFactory::crear(CintaTransportadora* cinta) {
	Figura* t = this->crearCintaTransportadora(cinta->getX(), cinta->getY(), cinta->getLongitud());
	t->setRotacion(0);
	t->setReg(cinta->getReg());
	return t;
}
Figura* FiguraFactory::crearBolaBoliche(float x, float y) {
	return new BolaBoliche(x,y,RADIO_BOLA);
}



Figura* FiguraFactory::crear(BolaBoliche* c) {
	Figura* t = this->crearBolaBoliche(c->getX(), c->getY());
		t->setRotacion(c->getRotacion());
		t->setReg(c->getReg());
		return t;
}

Figura* FiguraFactory::crearPelotaJuego(float x, float y) {
	return new PelotaJuego(x, y, RADIO_PELOTA);
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

Figura* FiguraFactory::crearEngranaje(float x, float y) {
	return new Engranaje(x, y, RADIO_ENGRANAJE);
}

Figura* FiguraFactory::crear(Motor* c) {
	Figura* t = this->crearMotor(c->getX(), c->getY());
		t->setRotacion(0);
		t->setReg(c->getReg());
	return t;
}

Figura* FiguraFactory::crear(Engranaje* c) {
	Figura* t = this->crearEngranaje(c->getX(), c->getY());
		t->setRotacion(0);
		t->setReg(c->getReg());
	return t;
}
