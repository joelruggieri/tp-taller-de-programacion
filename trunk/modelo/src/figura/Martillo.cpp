/*
 * Martillo.cpp
 *
 *  Created on: 20/09/2013
 *      Author: joel
 */

#include "Martillo.h"

Martillo::Martillo(): Cuadrado(){

}
Martillo::Martillo(float x, float y,Rotador * rot, float ancho, float alto): Cuadrado(x,y,rot,ancho,alto) {

}

Martillo::~Martillo() {
	// TODO Auto-generated destructor stub
}

Martillo::Martillo(const Martillo& figura){
	this->x = figura.getX();
	this->y = figura.getY();
	this->setRotacion(figura.getRotacion());
	this->rotador = figura.rotador;
	this->alto = figura.getAlto();
	this->ancho = figura.getAncho();

}

void Martillo::acept(VisitorFigura* visitor) {
	visitor->visit(this);
}
