/*
 * Objeto.cpp
 *
 *  Created on: 28/09/2013
 *      Author: jonathan
 */

#include "Objeto.h"

Objeto::Objeto(): Figura(){

}

Objeto::Objeto(float x, float y):Figura(x,y){
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

void Objeto::modificarSentido() {
}
