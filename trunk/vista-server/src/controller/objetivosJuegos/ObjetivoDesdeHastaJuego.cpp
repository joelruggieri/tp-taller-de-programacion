/*
 * ObjetivoDesdeHasta.cpp
 *
 *  Created on: 21/11/2013
 *      Author: ezequiel
 */

#include "ObjetivoDesdeHastaJuego.h"
#include "src/Constantes.h"
#include "src/objeto/PelotaJuego.h"
#include "src/objeto/Monitor.h"
ObjetivoDesdeHastaJuego::ObjetivoDesdeHastaJuego() : ObjetivoJuego() {
//this->xH = xH;
//this->yH = yH;
estado = NOTERMINADO;
}

ObjetivoDesdeHastaJuego::~ObjetivoDesdeHastaJuego() {
}

void ObjetivoDesdeHastaJuego::crearFiguras(std::list<Figura*>& l) {
	//ACA VA A DEPENDER EL OBJETO DEL NUMERO DE OBJETIVO ??
	PelotaJuego* p = new PelotaJuego(xD,yD,RADIO_PELOTA);
	l.push_back(p);
	Monitor* m = new Monitor(xH,yH,ANCHO_MONITOR,ALTO_MONITOR);
	m->setFiguraEsperada(p);
	m->addObserver(this);
	l.push_back(m);
}

void ObjetivoDesdeHastaJuego::notifyEvent(ObservableModelo* o, Evento_type t) {
	if (t == ACCIONADO)
	{
		estado = GANADO ;
		o->removeObserver(this);
	}
}

void ObjetivoDesdeHastaJuego::setConfig(Objetivo& o) {
	super::setConfig(o);
//	ObjetivoDesdeHasta * obj;

		this->xH = ((ObjetivoDesdeHasta&)o).getXH();
		this->yH = ((ObjetivoDesdeHasta&)o).getYH();
//	this->
}
