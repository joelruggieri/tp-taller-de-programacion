/*
 * Nivel.cpp
 *
 *  Created on: 15/09/2013
 *      Author: javier
 */

#include "Nivel.h"

Nivel::Nivel(std::string nombre) {
	this->nombre = nombre;
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

const std::string& Nivel::getNombre() const {
	return nombre;
}

void Nivel::setNombre(const std::string& nombre) {
	this->nombre = nombre;
}
