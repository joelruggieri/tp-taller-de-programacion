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

Bloque::Bloque(const Bloque& figura){
	this->x = figura.getX();
	this->y = figura.getY();
	this->rotacion = figura.getRotacion();
	this->rotador = figura.rotador;
	this->alto = figura.getAlto();
	this->ancho = figura.getAncho();

}

Bloque::~Bloque() {
	// TODO Auto-generated destructor stub
}

void Bloque::acept(VisitorFigura* visitor) {
	visitor->visit(this);
}
