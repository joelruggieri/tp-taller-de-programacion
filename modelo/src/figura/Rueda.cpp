/*
 * Rueda.cpp
 *
 *  Created on: 20/09/2013
 *      Author: joel
 */

#include "Rueda.h"
#include "VisitorFigura.h"
#include "Rotador.h"

Rueda::Rueda() :Circulo() {
	// TODO Auto-generated constructor stub

}

Rueda::Rueda(float x, float y, float radio):Circulo(x,y,radio){

}

Rueda::Rueda(const Rueda& figura){
	this->x = figura.getX();
	this->y = figura.getY();
	this->setRotacion(figura.getRotacion());
	this->radio = figura.getRadio();
}

Rueda::~Rueda() {
	// TODO Auto-generated destructor stub
}

void Rueda::acept(VisitorFigura* visitor) {
	visitor->visit(this);
}
