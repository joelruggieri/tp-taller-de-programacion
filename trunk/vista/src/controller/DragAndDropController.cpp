/*
 * DragAndDropController.cpp
 *
 *  Created on: 07/09/2013
 *      Author: jonathan
 */

#include "DragAndDropController.h"

#include "../vista/figura/FiguraView.h"

DragAndDropController::DragAndDropController(Zona *zonaJuego) {
	this->zona = zonaJuego;
	this->figurasFactory = new FiguraFactory();
	this->figuraDrag = NULL;
}

DragAndDropController::~DragAndDropController() {
}

void DragAndDropController::dropear(FiguraView* view, Figura* figura) {
	view->setModelo(figura);
	if (!zona->agregarFigura(view)) {
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
	if(!this->zona->agregarFigura(view)){
		delete view->getModelo();
		delete view;
		//TODO FALTA REMOVER EL MODELO
	}
}

bool DragAndDropController::clickDown(float x, float y) {
	this->zona->click(x,y);
	return false;
}

bool DragAndDropController::clickUp(float x, float y) {
	if(this->figuraDrag != NULL){
		//TODO ESTO DEBERÍA ACTUALIZAR LA POSICION DE LA IMAGEN, EN EL DROP SE DEBERÍA IMPACTAR TAMBIEN EN EL MODELO
		this->figuraDrag->drop();
		this->figuraDrag = NULL;
	}
	return true;
}

void DragAndDropController::drag(FiguraView* figura, float x, float y) {
	//TENGO QUE AVISAR AL JUEGO QUE SUSPENDA LA SIGUIENTE VISTA.
	this->zona->removerFigura(figura);
}

void DragAndDropController::dropNuevaFigura(RomboView* figura) {
}

bool DragAndDropController::mouseMotion(float corrimientoX, float corrimientoY) {
	if(this->figuraDrag != NULL){
		//TODO MANEJAR EL DRAG;
	}
	// consume el evento
	return false;
}
