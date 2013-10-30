/*
 * EslabonCreacion.cpp
 *
 *  Created on: 29/08/2013
 *      Author: jonathan
 */

#include "EslabonCreacion.h"
#include <iostream>
#include "src/Logger.h"
using namespace std;

EslabonCreacion::EslabonCreacion(ViewFiguraFactory * factory, Cuadrado * cuerpo, int maxItems) {
	this->factory = factory;
	this->siguiente = NULL;
	this->cuerpo = cuerpo;
	this->itemsDisponibles = maxItems;
}
//
EslabonCreacion::~EslabonCreacion() {
	if (this->siguiente != NULL)
		delete this->siguiente;
	delete factory;
	delete this->cuerpo;
}
//
void EslabonCreacion::setSiguiente(EslabonCreacion* sig) {
	this->siguiente = sig;
}
//
FiguraView * EslabonCreacion::atender(float posX, float posY, float corrimientoScroll) {

	if (this->cuerpo->contacto(posX, posY)) {
//		if(this->itemsDisponibles >0){
		Logger log;
		log.debug("Se llama a factory de vista");
		this->itemsDisponibles--;
		FiguraView * view = this->factory->crear(posX, posY - corrimientoScroll, this->cuerpo->getAncho(),
				this->cuerpo->getAlto());
		return view;
//		} else {
//			return NULL;
//		}
	}
	if (this->siguiente != NULL) {
		return this->siguiente->atender(posX, posY, corrimientoScroll);
	}
	return NULL;
}

View * EslabonCreacion::getFactoryView() {
	return this->factory->crearVistaPropia(cuerpo->getX(),
			cuerpo->getY(), this->cuerpo->getAncho(),this->cuerpo->getAlto());
}
