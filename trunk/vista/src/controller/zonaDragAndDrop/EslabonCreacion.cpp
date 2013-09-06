/*
 * EslabonCreacion.cpp
 *
 *  Created on: 29/08/2013
 *      Author: jonathan
 */

#include "EslabonCreacion.h"
#include <iostream>
using namespace std;

EslabonCreacion::EslabonCreacion(ViewFiguraFactory * factory, Figura * cuerpo, int maxItems){
	this->factory = factory;
	this->siguiente = NULL;
	this->cuerpo = cuerpo;
	this->itemsDisponibles  = maxItems;
}
//
EslabonCreacion::~EslabonCreacion() {
	if(this->siguiente != NULL)
	delete this->siguiente;
	delete factory;
	delete this->cuerpo;
}
//
void EslabonCreacion::setSiguiente(EslabonCreacion* sig) {
	this->siguiente = sig;
}
//
FiguraView * EslabonCreacion::antender(float posX, float posY) {
	if(this->cuerpo->contacto(posX, posY)){
//		if(this->itemsDisponibles >0){
			this->itemsDisponibles--;
			return this->factory->crear(posX, posY);
//		} else {
//			return NULL;
//		}
	}
	if(this->siguiente != NULL){
		return this->siguiente->antender(posX, posY);
	}
	return NULL;
}

//void EslabonCreacion::invalidar(Dropeable* drop) {
//	this->itemsDisponibles++;
//	delete drop;
//}
