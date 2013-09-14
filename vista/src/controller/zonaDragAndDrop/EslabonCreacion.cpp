/*
 * EslabonCreacion.cpp
 *
 *  Created on: 29/08/2013
 *      Author: jonathan
 */

#include "EslabonCreacion.h"
#include <iostream>
#include "../Resizer.h"
using namespace std;

EslabonCreacion::EslabonCreacion(ViewFiguraFactory * factory, Cuadrado * cuerpo,
		int maxItems) {
	this->factory = factory;
	this->siguiente = NULL;
	this->cuerpo = cuerpo;
	this->itemsDisponibles = maxItems;
	//TODO: Adaptar posicion con resizer.
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
FiguraView * EslabonCreacion::atender(float posX, float posY) {

	if (this->cuerpo->contacto(posX, posY)) {
//		if(this->itemsDisponibles >0){
		this->itemsDisponibles--;
		Resizer * res = Resizer::Instance();
		FiguraView * view = this->factory->crear(
				res->resizearDistanciaLogicaX(posX),
				res->resizearDistanciaLogicaY(posY),
				res->resizearDistanciaLogicaX(this->cuerpo->getAncho()),
				res->resizearDistanciaLogicaY(this->cuerpo->getAlto()));
		return view;
//		} else {
//			return NULL;
//		}
	}
	if (this->siguiente != NULL) {
		return this->siguiente->atender(posX, posY);
	}
	return NULL;
}

Dibujable * EslabonCreacion::getFactoryView() {
	Resizer * res = Resizer::Instance();
	return this->factory->crearVistaPropia(
			res->resizearDistanciaLogicaX(cuerpo->getX()),
			res->resizearDistanciaLogicaY(cuerpo->getY()),
			res->resizearDistanciaLogicaX(this->cuerpo->getAncho()),
			res->resizearDistanciaLogicaY(this->cuerpo->getAlto()));
}
