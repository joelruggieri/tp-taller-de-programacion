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

Cohete::Cohete(const Cohete& figura){
	this->x = figura.getX();
	this->y = figura.getY();
	this->rotacion = figura.getRotacion();
	this->rotador = figura.rotador;
	this->alto = figura.getAlto();
	this->ancho = figura.getAncho();

}

Cohete::~Cohete() {
	// TODO Auto-generated destructor stub
}

void Cohete::acept(VisitorFigura* visitor) {
	visitor->visit(this);
}
