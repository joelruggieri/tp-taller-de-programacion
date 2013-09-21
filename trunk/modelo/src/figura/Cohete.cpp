/*
 * Cohete.cpp
 *
 *  Created on: 21/09/2013
 *      Author: joel
 */

#include "Cohete.h"

Cohete::Cohete(): Cuadrado() {

}

Cohete::Cohete(float x, float y,Rotador* rotador, float ancho, float alto): Cuadrado(x,y,rotador,ancho,alto){

}

Cohete::~Cohete() {
	// TODO Auto-generated destructor stub
}

