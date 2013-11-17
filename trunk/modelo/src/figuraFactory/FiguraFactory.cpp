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
#include "../objeto/Carrito.h"
#include "../objeto/Soga.h"
#include "../objeto/Correa.h"
#include "../objeto/Gancho.h"
#include "../objeto/Yunque.h"
#include "../objeto/Clavo.h"
#include "../objeto/Polea.h"
#include "../Constantes.h"
FiguraFactory::FiguraFactory() {

}

FiguraFactory::~FiguraFactory() {
	// TODO Auto-generated destructor stub
}

Figura* FiguraFactory::crearGancho(float x, float y, int numeroJugador){
	Figura* figura = new Gancho(x,y,RADIO_GANCHO);
	figura->setNumeroJugador(numeroJugador);
	return figura;
}

Figura* FiguraFactory::crearMotor(float x, float y, int numeroJugador){
	Figura* figura = new Motor(x,y,RADIO_MOTOR);
	figura->setNumeroJugador(numeroJugador);
	return figura;
}

Figura* FiguraFactory::crearGloboHelio(float x, float y, int numeroJugador){
	Figura* figura =  new GloboHelio(x,y,RADIO_GLOBO);
	figura->setNumeroJugador(numeroJugador);
	return figura;
}

Figura* FiguraFactory::crearPlataforma(float x, float y, int numeroJugador){
	Figura* figura = new Plataforma(x,y,ANCHO_PLATAFORMA,ALTO_PLATAFORMA);
	figura->setNumeroJugador(numeroJugador);
	return figura;
}

Figura* FiguraFactory::crearBalancin(float x, float y, int numeroJugador){
	Figura* figura = new Balancin(x,y,ANCHO_BALANCIN,ALTO_BALANCIN);
	figura->setNumeroJugador(numeroJugador);
	return figura;
}

Figura* FiguraFactory::crearCarrito(float x, float y, int numeroJugador){
	Figura* figura = new Carrito(x,y,ANCHO_CARRITO,ALTO_CARRITO);
	figura->setNumeroJugador(numeroJugador);
	return figura;
}

Figura* FiguraFactory::crear(Plataforma* c) {
	Plataforma* y = (Plataforma*)this->crearPlataforma(c->getX(), c->getY(),c->getNumeroJugador());
	y->setRotacion(c->getRotacion());
	y->setAncho(c->getAncho());
	y->setReg(c->getReg());
	return y;
}

Figura* FiguraFactory::crear(Balancin* c) {
	Figura* y = this->crearBalancin(c->getX(), c->getY(),c->getNumeroJugador());
	y->setRotacion(c->getRotacion());
	y->setReg(c->getReg());
	return y;
}


Figura* FiguraFactory::crear(Carrito* c) {
	Figura* y = this->crearCarrito(c->getX(), c->getY(),c->getNumeroJugador());
	y->setRotacion(c->getRotacion());
	y->setReg(c->getReg());
	return y;
}


Figura* FiguraFactory::crearCintaTransportadora(float x, float y, int numeroJugador) {
	Figura* figura = new CintaTransportadora(x,y,ANCHO_CINTA,ALTO_CINTA);
	figura->setNumeroJugador(numeroJugador);
	return figura;
}

Figura* FiguraFactory::crear(CintaTransportadora* cinta) {
	CintaTransportadora* t = (CintaTransportadora *)this->crearCintaTransportadora(cinta->getX(), cinta->getY(),cinta->getNumeroJugador());
	t->setRotacion(0);
	t->setAncho(cinta->getAncho());
	t->setReg(cinta->getReg());
	return t;
}
Figura* FiguraFactory::crearBolaBoliche(float x, float y, int numeroJugador) {
	Figura* figura = new BolaBoliche(x,y,RADIO_BOLA);
	figura->setNumeroJugador(numeroJugador);
	return figura;
}



Figura* FiguraFactory::crear(BolaBoliche* c) {
	Figura* t = this->crearBolaBoliche(c->getX(), c->getY(),c->getNumeroJugador());
		t->setRotacion(c->getRotacion());
		t->setReg(c->getReg());
		return t;
}

Figura* FiguraFactory::crearPelotaJuego(float x, float y, int numeroJugador) {
	Figura* figura = new PelotaJuego(x, y, RADIO_PELOTA);
	figura->setNumeroJugador(numeroJugador);
	return figura;
}


Figura* FiguraFactory::crear(PelotaJuego* c) {
	Figura* t = this->crearPelotaJuego(c->getX(), c->getY(),c->getNumeroJugador());
		t->setRotacion(c->getRotacion());
		t->setReg(c->getReg());
		return t;
}

Figura* FiguraFactory::crear(Gancho*c) {
	Figura* t = this->crearGancho(c->getX(), c->getY(),c->getNumeroJugador());
		t->setRotacion(0);
		t->setReg(c->getReg());
	return t;
}

Figura* FiguraFactory::crear(GloboHelio*c) {
	Figura* t = this->crearGloboHelio(c->getX(), c->getY(),c->getNumeroJugador());
		t->setRotacion(0);
		t->setReg(c->getReg());
	return t;
}

Figura* FiguraFactory::crearEngranaje(float x, float y, int numeroJugador) {
	Figura* figura = new Engranaje(x, y, RADIO_ENGRANAJE);
	figura->setNumeroJugador(numeroJugador);
	return figura;
}

Figura* FiguraFactory::crear(Motor* c) {
	Motor * t = (Motor *)this->crearMotor(c->getX(), c->getY(),c->getNumeroJugador());
		t->setRotacion(0);
		t->setDireccion(c->getDireccion());
		t->setReg(c->getReg());
	return t;
}

Figura* FiguraFactory::crear(Engranaje* c) {
	Engranaje* t =(Engranaje*) this->crearEngranaje(c->getX(), c->getY(),c->getNumeroJugador());
		t->setRotacion(0);
		t->setReg(c->getReg());
		t->setRadio(c->getRadio());
	return t;
}

Figura* FiguraFactory::crearSoga(float x, float y, int numeroJugador) {
	Figura * figura = new Soga(x,y);
	figura->setNumeroJugador(numeroJugador);
	return figura;

}

Figura* FiguraFactory::crearCorrea(float x, float y, int numeroJugador) {
	Figura* figura = new Correa(x,y);
	figura->setNumeroJugador(numeroJugador);
	return figura;
}

Figura* FiguraFactory::crear(Correa* c) {
	Correa* t =(Correa*) this->crearCorrea(c->getX(), c->getY(),c->getNumeroJugador());
	t->setXInicial(c->getXInicial());
	t->setYInicial(c->getYInicial());
	t->setXFinal(c->getXFinal());
	t->setYFinal(c->getYFinal());

		t->setReg(c->getReg());
	return t;
}

Figura* FiguraFactory::crear(Soga* c) {
	Soga* t =(Soga*) this->crearSoga(c->getX(), c->getY(),c->getNumeroJugador());
	t->setXInicial(c->getXInicial());
	t->setYInicial(c->getYInicial());
	t->setXFinal(c->getXFinal());
	t->setYFinal(c->getYFinal());
	t->setReg(c->getReg());
	return t;
}

Figura* FiguraFactory::crearYunque(float x, float y, int numeroJugador) {
	Figura* figura = new Yunque(x,y, ANCHO_YUNQUE,ANCHO_YUNQUE);
	figura->setNumeroJugador(numeroJugador);
	return figura;
}

Figura* FiguraFactory::crear(Yunque* c) {
	Yunque* y = (Yunque*)this->crearYunque(c->getX(), c->getY(),c->getNumeroJugador());
		y->setRotacion(c->getRotacion());
		y->setAncho(c->getAncho());
		y->setReg(c->getReg());
		return y;
}

Figura* FiguraFactory::crearClavo(float x, float y, int numeroJugador) {
	Figura* figura = new Clavo(x,y, ANCHO_CLAVO,ALTO_CLAVO);
	figura->setNumeroJugador(numeroJugador);
	return figura;
}

Figura* FiguraFactory::crear(Clavo* c) {
	Clavo* y = (Clavo*)this->crearClavo(c->getX(), c->getY(),c->getNumeroJugador());
		y->setRotacion(c->getRotacion());
		y->setAncho(c->getAncho());
		y->setReg(c->getReg());
		return y;
}

Figura* FiguraFactory::crearPolea(float x, float y, int numeroJugador) {
	Figura* figura = new Polea(x,y, RADIO_POLEA);
	figura->setNumeroJugador(numeroJugador);
	return figura;
}

Figura* FiguraFactory::crear(Polea*c) {
	Polea* y = (Polea*)this->crearPolea(c->getX(), c->getY(),c->getNumeroJugador());
		y->setRotacion(c->getRotacion());
		y->setReg(c->getReg());
		return y;
}
