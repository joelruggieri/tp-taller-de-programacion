/*
 * Dropeable.cpp
 *
 *  Created on: 29/08/2013
 *      Author: jonathan
 */

#include "Dropeable.h"

Dropeable::Dropeable(string modelo) {
	this->modelo = modelo;
	Cuerpo c(0,0,0,0);
	this->cuerpo = c;
}

Dropeable::Dropeable(string modelo, Cuerpo cuerpo) {
	this->modelo = modelo;
	this->cuerpo = cuerpo;
}

Dropeable::~Dropeable() {
	// TODO Auto-generated destructor stub
}


const string Dropeable::getModelo() {
	return this->modelo;
}

const Cuerpo Dropeable::getCuerpo(){
	return this->cuerpo;
}
