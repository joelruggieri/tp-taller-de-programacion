/*
 * FinDeJuegoController.cpp
 *
 *  Created on: 14/11/2013
 *      Author: jonathan
 */

#include "MensajesServerReceptor.h"
#include "src/mensajes/MensajePlano.h"
namespace CLIENTE {

MensajesServerReceptor::MensajesServerReceptor(StatusJuego * status) {

	this->status = status;

}

void MensajesServerReceptor::visit(MensajePlano* m) {
	lock();
	if(m->getMensaje() == TAG_PLANO_MSJ_JUEGOTERMINADOPERDIDO){
		status->perder();
	}

	if(m->getMensaje() == TAG_PLANO_MSJ_JUEGOTERMINADOGANADO){
		status->ganar();
	}

	if(m->getMensaje() == TAG_PLANO_MSJ_JUEGOINICIADO){
		status->arrancar();
	}

	if(m->getMensaje() == TAG_PLANO_MSJ_JUEGOPAUSADO){
		status->parar();
	}

	unlock();
}

MensajesServerReceptor::~MensajesServerReceptor() {
	// TODO Auto-generated destructor stub
}

} /* namespace CLIENTE */
