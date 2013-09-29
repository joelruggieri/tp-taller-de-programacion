/*
 * Objeto.cpp
 *
 *  Created on: 28/09/2013
 *      Author: jonathan
 */

#include "Objeto.h"

Objeto::Objeto(float x, float y,Rotador * rot):Figura(x,y,rot){
	body = NULL;
}

Objeto::~Objeto() {
	// TODO Auto-generated destructor stub
}

bool Objeto::contieneCentro(Posicionable*) {
	return false;
}

void Objeto::acept(VisitorFigura*) {

}

float Objeto::getAlto() const {
	return 0;
}

float Objeto::getAncho() const {
	return 0;
}

bool Objeto::contacto(float float1, float float2) {
	return false;
}

