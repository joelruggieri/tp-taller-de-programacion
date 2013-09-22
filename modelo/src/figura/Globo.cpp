/*
 * Globo.cpp
 *
 *  Created on: 20/09/2013
 *      Author: joel
 */

#include "Globo.h"

Globo::Globo(): Circulo() {
	// TODO Auto-generated constructor stub

}

Globo::~Globo() {
	// TODO Auto-generated destructor stub
}

Globo::Globo(float x, float y, Rotador* rotador, float radio): Circulo(x,y,rotador,radio){

}

void Globo::acept(VisitorFigura* visitor) {
	visitor->visit(this);
}
