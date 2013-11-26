/*
 * ObjetivoAccionar.cpp
 *
 *  Created on: 21/11/2013
 *      Author: ezequiel
 */

#include "ObjetivoAccionarJuego.h"
#include "src/Constantes.h"
#include "src/objeto/GloboHelio.h"
#include "src/objeto/Monitor.h"
#include "src/objeto/Bomba.h"
#include <iostream>
ObjetivoAccionarJuego::ObjetivoAccionarJuego(bool e) : ObjetivoJuego() {
this->esBomba = e ;
}

ObjetivoAccionarJuego::~ObjetivoAccionarJuego() {
	// TODO Auto-generated destructor stub
}

void ObjetivoAccionarJuego::crearFiguras(std::list<Figura*>& allocator) {
	if (!esBomba){
	GloboHelio* g = new GloboHelio(this->xD, this->yD,RADIO_GLOBO);
	g->addObserver(this);
	allocator.push_back(g);}
	else
	{
		Bomba* b = new Bomba(this->xD, this->yD, RADIO_PELOTA);
		b->addObserver(this);
		allocator.push_back(b);
	}
}

void ObjetivoAccionarJuego::notifyEvent(ObservableModelo* o, Evento_type t) {
	if (t == DESACTIVADO) {
		this->cumplir();
	}
}

void ObjetivoAccionarJuego::setConfig(Objetivo& o) {
super::setConfig(o);
}

string ObjetivoAccionarJuego::getDescripcion() {
	if (!esBomba)
	{
		string ret = "PINCHA EL GLOBO";
		return ret;
	}
	else
	{
		string ret = "Explotar la bomba que viene en al mapa";
		return ret;
	}
}
