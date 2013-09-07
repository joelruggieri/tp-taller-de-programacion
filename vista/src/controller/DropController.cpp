/*
 * DropController.cpp
 *
 *  Created on: 30/08/2013
 *      Author: jonathan
 */

#include "DropController.h"
#include "zonaDragAndDrop/ZonaJuego.h"
#include "../vista/figura/FiguraView.h"

DropController::DropController() {
	this->zona = new ZonaJuego();
	this->figurasFactory = new FiguraFactory();
	this->figuraDrag = NULL;
}

DropController::~DropController() {
}

void DropController::dropear(FiguraView* view, Figura* figura) {
	view->setModelo(figura);
	if (!zona->drop(view)) {
		delete figura;
		delete view;
	}
}

void DropController::dropNuevaFigura(CirculoView* view) {
	dropear(view, this->figurasFactory->crearCirculo());
}

void DropController::dropNuevaFigura(TrianguloView* view) {
	dropear(view, this->figurasFactory->crearTriangulo());
}

void DropController::dropNuevaFigura(CuadradoView* view) {
	dropear(view, this->figurasFactory->crearCuadrado());
}

void DropController::dropFigura(FiguraView* view) {
	if(!this->zona->drop(view)){
		delete view->getModelo();
		delete view;
		//TODO FALTA REMOVER EL MODELO
	}
}

bool DropController::clickDown(float x, float y) {
	this->figuraDrag == NULL ? this->zona->drag(x,y) : NULL;
	return true;
}

bool DropController::clickUp(float x, float y) {
	if(this->figuraDrag != NULL){
		this->figuraDrag->drop(this);
		this->figuraDrag = NULL;
	}
	return true;
}

bool DropController::mouseMotion(float corrimientoX, float corrimientoY) {
	if(this->figuraDrag != NULL){
		//TODO MANEJAR EL DRAG;
	}
	// consume el evento
	return false;
}
