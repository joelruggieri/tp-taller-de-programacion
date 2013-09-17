/*
 * Nivel.cpp
 *
 *  Created on: 15/09/2013
 *      Author: javier
 */

#include "Nivel.h"

Nivel::Nivel(int num) {
	numero = num;
}

Nivel::~Nivel() {
	// TODO Auto-generated destructor stub
}

void Nivel::agregar(Figura* figura) {
	objetos.push_back(figura);
}

int Nivel::cantidadFiguras() const{
	return objetos.size();
}

std::list<Figura*> &Nivel::getFiguras() {
	return objetos;
}


int Nivel::getNumero() const{
	return numero;
}

void Nivel::setNumero(int n) {
	this->numero = n;
}
