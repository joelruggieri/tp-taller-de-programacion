/*
 * ModeloController.cpp
 *
 *  Created on: 16/09/2013
 *      Author: jonathan
 */

#include "ModeloController.h"

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

list<Figura*>& ModeloController::getFiguras() {
	return mapa->getFiguras();
}
