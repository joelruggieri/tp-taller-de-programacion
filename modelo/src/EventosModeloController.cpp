/*
 * ModeloController.cpp
 *
 *  Created on: 16/09/2013
 *      Author: jonathan
 */

#include "ModeloController.h"

ModeloController::ModeloController() {
	mapa = new Mapa(50,50,100,100);

}

ModeloController::~ModeloController() {
	delete mapa;
}

bool ModeloController::crearFigura(Figura* figura) {
	return this->mapa->add(figura);;
}

bool ModeloController::removerFigura(Figura* figura) {
	return this->mapa->remove(figura);;
}

list<Figura*>& ModeloController::getFiguras() {
	return mapa->getFiguras();
}

Figura* ModeloController::pickUp(float x, float y) {
	return mapa->pickUp(x,y);
}

void ModeloController::step() {
	mapa->step(*tl);
}

void ModeloController::start() {
	mapa->makeBackUp();
	mapa->despertar();
}

void ModeloController::stop() {
	mapa->restoreBackUp(*tl);
}

void ModeloController::setTransformacion(Transformacion * tl) {
	this->tl = tl;
}

bool ModeloController::crearUnion(Union* figura) {

		Figura* fInicial = this->pickUp(figura->getXInicial(),
				figura->getYInicial());
		if(fInicial == NULL) {
			return false;
		}
		Figura* fFinal = this->pickUp(figura->getXFinal(),
				figura->getYFinal());
		if(fFinal == NULL) {
			return false;
		}
		if (fFinal == fInicial)
			return false;

		figura->setExtremos(fInicial,fFinal);
		//recupero los cuerpos que une, se los seteo y verifico.
		return mapa->add(figura);
}
