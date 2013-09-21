/*
 * Bloque.cpp
 *
 *  Created on: 21/09/2013
 *      Author: joel
 */

#include "Bloque.h"

Bloque::Bloque(): Cuadrado(){


}

Bloque::Bloque(float x, float y,Rotador* rotador, float ancho, float alto): Cuadrado(x,y,rotador,ancho,alto){

}

Bloque::~Bloque() {
	// TODO Auto-generated destructor stub
}

