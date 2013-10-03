/*
 * Objeto.cpp
 *
 *  Created on: 28/09/2013
 *      Author: jonathan
 */

#include "Objeto.h"

Objeto::Objeto(): Figura(){

}

Objeto::Objeto(float x, float y,Rotador * rot):Figura(x,y,rot){
	body = NULL;
}

Objeto::~Objeto() {
	// TODO Auto-generated destructor stub
}

bool Objeto::contieneCentro(Posicionable*) {
	return false;
}



bool Objeto::contacto(float float1, float float2) {
	return false;
}

