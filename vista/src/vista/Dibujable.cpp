/*
 * Dibujable.cpp
 *
 *  Created on: 04/09/2013
 *      Author: ezequiel
 */

#include "Dibujable.h"
#include "../ConstantesVista.h"
#include <iostream>
using namespace std;


namespace CLIENTE {

Dibujable::Dibujable(int l) {
	layer =l;
	highlight = false;
}

Dibujable::~Dibujable() {

}

int Dibujable::getLayer() {
	if(highlight){
		return LAYER_HIGHLIGHT;
	}
	return layer;
}


void CLIENTE::Dibujable::higlight(bool h) {
	highlight = h;
}
}
