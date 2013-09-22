/*
 * Resorte.cpp
 *
 *  Created on: 20/09/2013
 *      Author: joel
 */

#include "Resorte.h"

Resorte::Resorte(): Cuadrado() {

}

Resorte::Resorte(float x,float y, Rotador* rotador, float ancho, float alto): Cuadrado(x,y,rotador,ancho,alto){

}

Resorte::~Resorte() {
	// TODO Auto-generated destructor stub
}

void Resorte::acept(VisitorFigura* visitor) {
	visitor->visit(this);
}
