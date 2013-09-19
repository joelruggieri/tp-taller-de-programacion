/*
 * ModeloController.cpp
 *
 *  Created on: 16/09/2013
 *      Author: jonathan
 */

#include "EventosModeloController.h"

ModeloController::ModeloController() {
	mapa = new Mapa();

}

ModeloController::~ModeloController() {
	delete mapa;
}

bool ModeloController::crearFigura(Figura* figura) {
	this->mapa->addFigura(figura);
	return true;
}

bool ModeloController::removerFigura(Figura* figura) {
	this->mapa->removeFigura(figura);
	return true;
}
