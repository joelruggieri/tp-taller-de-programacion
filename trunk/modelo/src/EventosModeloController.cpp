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
	return this->mapa->addFigura(figura);;
}

bool ModeloController::removerFigura(Figura* figura) {
	return this->mapa->removeFigura(figura);;
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
}

void ModeloController::stop() {
	mapa->restoreBackUp(*tl);
}

void ModeloController::setTransformacion(Transformacion * tl) {
	this->tl = tl;
}
