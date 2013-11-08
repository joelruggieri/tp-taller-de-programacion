/*
 * ViewFiguraFactory.cpp
 *
 *  Created on: 05/09/2013
 *      Author: jonathan
 */

#include "ViewFiguraFactory.h"
ViewFiguraFactory::ViewFiguraFactory(DropController * controller, int cantidadDisponible) {
	this->controller = controller;
	this->cantidadDisponible = cantidadDisponible ;
}


ViewFiguraFactory::~ViewFiguraFactory() {
	// TODO Auto-generated destructor stub
}

FiguraView* ViewFiguraFactory::crearTemplate(float x, float y) {
	if (cantidadDisponible == 0)
	{
		return NULL;
	}
	FiguraView* figuraRetorno = this->crear(x,y);
	if ( figuraRetorno != NULL){
		cantidadDisponible--;
		return figuraRetorno;
	}
	return figuraRetorno;

}

