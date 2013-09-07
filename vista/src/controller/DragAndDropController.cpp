/*
 * DragAndDropController.cpp
 *
 *  Created on: 07/09/2013
 *      Author: jonathan
 */

#include "DragAndDropController.h"

#include "zonaDragAndDrop/ZonaJuego.h"
#include "../vista/figura/FiguraView.h"

DragAndDropController::DragAndDropController() {
	this->zona = new ZonaJuego();
	this->figurasFactory = new FiguraFactory();
	this->figuraDrag = NULL;
}

DragAndDropController::~DragAndDropController() {
}

void DragAndDropController::dropear(FiguraView* view, Figura* figura) {
	view->setModelo(figura);
	if (!zona->drop(view)) {
		delete figura;
		delete view;
	}
}

void DragAndDropController::dropNuevaFigura(CirculoView* view) {
	dropear(view, this->figurasFactory->crearCirculo());
}

void DragAndDropController::dropNuevaFigura(TrianguloView* view) {
	dropear(view, this->figurasFactory->crearTriangulo());
}

void DragAndDropController::dropNuevaFigura(CuadradoView* view) {
	dropear(view, this->figurasFactory->crearCuadrado());
}

void DragAndDropController::dropFigura(FiguraView* view) {
	if(!this->zona->drop(view)){
		delete view->getModelo();
		delete view;
		//TODO FALTA REMOVER EL MODELO
	}
}

bool DragAndDropController::clickDown(float x, float y) {
	this->figuraDrag == NULL ? this->zona->drag(x,y) : NULL;
	return true;
}

bool DragAndDropController::clickUp(float x, float y) {
	if(this->figuraDrag != NULL){
		this->figuraDrag->drop(this);
		this->figuraDrag = NULL;
	}
	return true;
}

bool DragAndDropController::mouseMotion(float corrimientoX, float corrimientoY) {
	if(this->figuraDrag != NULL){
		//TODO MANEJAR EL DRAG;
	}
	// consume el evento
	return false;
}
