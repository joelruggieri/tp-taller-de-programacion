/*
 * StatusJuego.cpp
 *
 *  Created on: 14/11/2013
 *      Author: jonathan
 */

#include "StatusJuego.h"

namespace CLIENTE {

StatusJuego::StatusJuego() {
	corriendo = false;
	terminado = false;
	ganado = false;
}

void StatusJuego::parar() {
	lock();
	if (!terminado) {
		corriendo = false;
	}
	unlock();
}

void StatusJuego::arrancar() {
	lock();
	if (!terminado) {
		corriendo = true;
	}
	unlock();
}

bool StatusJuego::isCorriendo() {
	lock();
	bool result = corriendo;
	unlock();
	return result;
}

bool StatusJuego::isTerminado() {
	lock();
	bool result = terminado;
	unlock();
	return result;
}

bool StatusJuego::isGanado() {
	lock();
	bool result = ganado;
	unlock();
	return result;
}

StatusJuego::~StatusJuego() {
	// TODO Auto-generated destructor stub
}

} /* namespace CLIENTE */

void CLIENTE::StatusJuego::ganar() {
	if(!terminado){
		terminado =true;
		ganado = true;
	}
}

void CLIENTE::StatusJuego::perder() {
	if(!terminado){
		terminado =true;
		ganado = false;
	}

}
