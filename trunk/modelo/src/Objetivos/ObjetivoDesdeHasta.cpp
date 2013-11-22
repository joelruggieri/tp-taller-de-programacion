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
}

ObjetivoDesdeHasta::~ObjetivoDesdeHasta() {
	// TODO Auto-generated destructor stub
}

void ObjetivoDesdeHasta::crearFiguras(std::list<Figura*>& l) {
	//ACA VA A DEPENDER EL OBJETO DEL NUMERO DE OBJETIVO ??
	l.push_back(new PelotaJuego(xD,yD,RADIO_PELOTA));
	l.push_back(new Monitor(xH,yH,ANCHO_MONITOR,ALTO_MONITOR));
}
