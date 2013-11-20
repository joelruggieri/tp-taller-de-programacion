/*
 * ViewFiguraFactory.cpp
 *
 *  Created on: 05/09/2013
 *      Author: jonathan
 */

#include "ViewFiguraFactory.h"
#include <src/mensajes/viewMensaje/MensajeCantidadRestante.h>
ViewFiguraFactory::ViewFiguraFactory(DropController * controller, int cantidadDisponible, int id) {
	this->controller = controller;
	this->cantidadDisponible = cantidadDisponible ;
	this->id = id;
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
		figuraRetorno->addObserver(this);
		return figuraRetorno;
	}
	return figuraRetorno;

}

void ViewFiguraFactory::notify(Observable* viewFigura, event_type evento){

	if(evento == DESTRUIR_VISTA){
		this->cantidadDisponible++;
	}

}

ViewMsj* ViewFiguraFactory::dibujarse(int destinatario) {

	return NULL;
}
