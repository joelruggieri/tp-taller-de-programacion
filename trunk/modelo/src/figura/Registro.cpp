/*
 * Registro.cpp
 *
 *  Created on: 07/10/2013
 *      Author: jonathan
 */

#include "Registro.h"

Registro::Registro() {
	etiqueta="";
	linea =0;

}

const string& Registro::getEtiqueta() {
	return etiqueta;
}

void Registro::setEtiqueta(string etiqueta) {
	this->etiqueta = etiqueta;
}

int Registro::getLinea() {
	return linea;
}

void Registro::setLinea(int linea) {
	this->linea = linea;
}

Registro::~Registro() {
	// TODO Auto-generated destructor stub
}

