/*
 * ObjetivoDesdeHasta.cpp
 *
 *  Created on: 21/11/2013
 *      Author: ezequiel
 */

#include "ObjetivoDesdeHasta.h"
#include "../Constantes.h"
#include "../objeto/PelotaJuego.h"
#include "../objeto/Monitor.h"
ObjetivoDesdeHasta::ObjetivoDesdeHasta(float xD, float yD, float xH, float yH, float numeroObj) : Objetivo(xD, yD,numeroObj) {
this->xH = xH;
this->yH = yH;
estado = NOTERMINADO;
}

ObjetivoDesdeHasta::~ObjetivoDesdeHasta() {
}

void ObjetivoDesdeHasta::crearFiguras(std::list<Figura*>& l) {
	//ACA VA A DEPENDER EL OBJETO DEL NUMERO DE OBJETIVO ??
	l.push_back(new PelotaJuego(xD,yD,RADIO_PELOTA));
	Monitor* m = new Monitor(xH,yH,ANCHO_MONITOR,ALTO_MONITOR);
	m->addObserver(this);
	l.push_back(m);
}

void ObjetivoDesdeHasta::notifyEvent(ObservableModelo* o, Evento_type t) {
	if (t == ACCIONADO)
	{
		estado = GANADO ;
		o->removeObserver(this);
	}
}
