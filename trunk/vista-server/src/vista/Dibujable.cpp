/*
 * Dibujable.cpp
 *
 *  Created on: 04/09/2013
 *      Author: ezequiel
 */

#include "Dibujable.h"
#include "../ConstantesVista.h"

Dibujable::Dibujable() {

}

Dibujable::~Dibujable() {

}

int Dibujable::getLayer() {
	return LAYER_DEFAULT;
}