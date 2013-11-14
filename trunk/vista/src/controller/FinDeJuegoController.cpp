/*
 * FinDeJuegoController.cpp
 *
 *  Created on: 14/11/2013
 *      Author: jonathan
 */

#include "FinDeJuegoController.h"
#include "src/mensajes/MensajePlano.h"
namespace CLIENTE {

FinDeJuegoController::FinDeJuegoController() {
	terminado = false;
	ganado = false;

}

void FinDeJuegoController::visit(MensajePlano* m) {
	lock();
	if(m->getMensaje() == TAG_PLANO_MSJ_JUEGOTERMINADOPERDIDO){
		terminado =true;
		ganado = false;
	}

	if(m->getMensaje() == TAG_PLANO_MSJ_JUEGOTERMINADOGANADO){
		terminado =true;
		ganado = true;
	}
	unlock();
}

FinDeJuegoController::~FinDeJuegoController() {
	// TODO Auto-generated destructor stub
}

bool FinDeJuegoController::isTerminado() {
	bool result;
	lock();
	result = terminado;
	unlock();
	return result;
}

bool FinDeJuegoController::isGanado() {
	bool result;
	lock();
	result = ganado;
	unlock();
	return result;
}

} /* namespace CLIENTE */
