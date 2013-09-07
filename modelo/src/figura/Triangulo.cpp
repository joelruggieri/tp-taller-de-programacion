/*
 * Triangulo.cpp
 *
 *  Created on: 06/09/2013
 *      Author: jonathan
 */

#include "Triangulo.h"

Triangulo::Triangulo() {
	// TODO Auto-generated constructor stub

}

Triangulo::Triangulo(float x, float y){
	this->x = x;
	this->y= y;
	this->rotacion = 0;
}

Triangulo::~Triangulo() {
	// TODO Auto-generated destructor stub
}

bool Triangulo::contacto(float float1, float float2) {
	return false;
}

bool Triangulo::contieneCentro(Figura* cuadrado) {
	return false;
}
