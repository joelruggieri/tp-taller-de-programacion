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

Resorte::Resorte(const Resorte& figura){
	this->x = figura.getX();
	this->y = figura.getY();
	this->rotacion = figura.getRotacion();
	this->rotador = figura.rotador;
	this->alto = figura.getAlto();
	this->ancho = figura.getAncho();

}

Resorte::~Resorte() {
	// TODO Auto-generated destructor stub
}

void Resorte::acept(VisitorFigura* visitor) {
	visitor->visit(this);
}
