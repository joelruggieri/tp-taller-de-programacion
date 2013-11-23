/*
 * ObjetivoJuego.cpp
 *
 *  Created on: 21/11/2013
 *      Author: ezequiel
 */

#include "ObjetivoJuego.h"

ObjetivoJuego::ObjetivoJuego() {
	cumplido = false;
	xD=0;
	yD=0;

}

ObjetivoJuego::~ObjetivoJuego() {
	// TODO Auto-generated destructor stub
}

bool ObjetivoJuego::isCumplido() {
	lock();
	bool c = cumplido;
	unlock();
	return c;
}

void ObjetivoJuego::cumplir() {
	lock();
	cumplido=true;
	unlock();
}

void ObjetivoJuego::setConfig(Objetivo& o) {
	this->xD = o.getXD();
	this->yD = o.getYD();
}

