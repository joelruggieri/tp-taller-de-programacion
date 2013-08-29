/*
 * EslabonCreacion.cpp
 *
 *  Created on: 29/08/2013
 *      Author: jonathan
 */

#include "EslabonCreacion.h"
#include <iostream>
using namespace std;

EslabonCreacion::EslabonCreacion(DropeableFactory * factory, Cuerpo cuerpo) {
	this->factory = factory;
	this->siguiente = NULL;
	this->cuerpo = cuerpo;
}

EslabonCreacion::~EslabonCreacion() {
	if(this->siguiente != NULL)
	delete this->siguiente;
	delete factory;
}

void EslabonCreacion::setSiguiente(EslabonCreacion* sig) {
	this->siguiente = sig;
}

Dropeable * EslabonCreacion::antender(float posX, float posY) {
	if(this->cuerpo.isAdentro(posX, posY)){
		return this->factory->crear();
	}
	if(this->siguiente != NULL){
		return this->siguiente->antender(posX, posY);
	}
	return NULL;
}


