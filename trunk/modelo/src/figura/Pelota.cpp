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

Pelota::Pelota(const Pelota& figura){
	this->x = figura.getX();
	this->y = figura.getY();
	this->setRotacion(figura.getRotacion());
	this->rotador = figura.rotador;
	this->radio = figura.getRadio();

}

void Pelota::acept(VisitorFigura* visitor) {
	visitor->visit(this);
}
