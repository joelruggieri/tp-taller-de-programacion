/*
 * Mapa.cpp
 *
 *  Created on: 04/09/2013
 *      Author: jonathan
 */

#include "Mapa.h"

Mapa::Mapa():Cuadrado(50,50,100,100) {

}

Mapa::~Mapa() {
	// TODO Auto-generated destructor stub
}

void Mapa::removeFigura(Figura* figura) {
	this->figuras.remove(figura);
}

void Mapa::addFigura(Figura* figura) {
	this->figuras.push_back(figura);
}

list<Figura*>& Mapa::getFiguras() {
	return this->figuras;
}
