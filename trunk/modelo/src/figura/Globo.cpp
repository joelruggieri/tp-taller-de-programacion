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

Globo::Globo(float x, float y, float radio): Circulo(x,y,radio){

}

Globo::Globo(const Globo& figura){
	this->x = figura.getX();
	this->y = figura.getY();
	this->setRotacion(figura.getRotacion());
	this->radio = figura.getRadio();
}


void Globo::acept(VisitorFigura* visitor) {
	visitor->visit(this);
}
