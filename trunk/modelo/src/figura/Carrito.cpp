/*
 * Carrito.cpp
 *
 *  Created on: 21/09/2013
 *      Author: joel
 */

#include "Carrito.h"

Carrito::Carrito():Cuadrado() {

}

Carrito::Carrito(float x, float y,Rotador* rotador, float ancho, float alto): Cuadrado(x,y,rotador,ancho,alto){

}

Carrito::Carrito(const Carrito& figura){
	this->x = figura.getX();
	this->y = figura.getY();
	this->rotacion = figura.getRotacion();
	this->rotador = figura.rotador;
	this->alto = figura.getAlto();
	this->ancho = figura.getAncho();

}

Carrito::~Carrito() {
	// TODO Auto-generated destructor stub
}

void Carrito::acept(VisitorFigura* visitor) {
	visitor->visit(this);
}
