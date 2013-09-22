/*
 * Pelota.cpp
 *
 *  Created on: 20/09/2013
 *      Author: joel
 */

#include "Pelota.h"

Pelota::Pelota():Circulo() {


}

Pelota::~Pelota() {
	// TODO Auto-generated destructor stub
}

Pelota::Pelota(float x, float y, Rotador* rotador,float radio): Circulo(x,y,rotador,radio){

}

void Pelota::acept(VisitorFigura* visitor) {
	visitor->visit(this);
}
