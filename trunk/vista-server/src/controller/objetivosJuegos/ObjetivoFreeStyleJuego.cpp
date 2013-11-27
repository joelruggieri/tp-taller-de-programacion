/*
 * ObjetivoFreeStyleJuego.cpp
 *
 *  Created on: 26/11/2013
 *      Author: ezequiel
 */

#include "ObjetivoFreeStyleJuego.h"

ObjetivoFreeStyleJuego::ObjetivoFreeStyleJuego() {
	// TODO Auto-generated constructor stub

}

ObjetivoFreeStyleJuego::~ObjetivoFreeStyleJuego() {
	// TODO Auto-generated destructor stub
}

string ObjetivoFreeStyleJuego::getDescripcion() {
	return "FreeStyle !!";
}

void ObjetivoFreeStyleJuego::crearFiguras(std::list<Figura*>& allocator) {
}

void ObjetivoFreeStyleJuego::notifyEvent(ObservableModelo* o, Evento_type t) {
}
