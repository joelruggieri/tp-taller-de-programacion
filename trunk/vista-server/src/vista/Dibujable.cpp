/*
 * Dibujable.cpp
 *
 *  Created on: 04/09/2013
 *      Author: ezequiel
 */

#include "Dibujable.h"
#include "../ConstantesVista.h"

//LOS PRIMEROS 50 RESERVADOS PÁRA LAS VISTAS PROPIAS DEL CLIENTE.
//LOS SIGUIENTES 50 RESERVADOS PARA IDENTIFICAR LAS FACTORIES.
int Dibujable::idSequence = 200;

void Dibujable::incrementarIdSequence(){
	Dibujable::idSequence ++;
}

Dibujable::Dibujable() {
	Dibujable::incrementarIdSequence();
	this->id = Dibujable::idSequence;
}

Dibujable::~Dibujable() {

}

int Dibujable::getLayer() {
	return LAYER_DEFAULT;
}

int Dibujable::getId(){

	return this->id;
}
