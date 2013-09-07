/*
 * DropManager.cpp
 *
 *  Created on: 30/08/2013
 *      Author: jonathan
 */

#include "DropManager.h"
#include "zonaDragAndDrop/ZonaJuego.h"
#include "../vista/figura/FiguraView.h"

DropManager::DropManager() {
	this->zona = new ZonaJuego();
	this->figurasFactory = new FiguraFactory();
	this->figuraDrag = NULL;
}

DropManager::~DropManager() {
}

void DropManager::dropear(FiguraView* view, Figura* figura) {
	view->setModelo(figura);
	if (!zona->drop(view)) {
		delete figura;
		delete view;
	}
}

void DropManager::dropNuevaFigura(CirculoView* view) {
	dropear(view, this->figurasFactory->crearCirculo());
}

void DropManager::dropNuevaFigura(TrianguloView* view) {
	dropear(view, this->figurasFactory->crearTriangulo());
}

void DropManager::dropNuevaFigura(CuadradoView* view) {
	dropear(view, this->figurasFactory->crearCuadrado());
}

void DropManager::dropFigura(FiguraView* view) {
	if(!this->zona->drop(view)){
		delete view->getModelo();
		delete view;
		//TODO FALTA REMOVER EL MODELO
	}
}

//FiguraView* DropManager::drag(float x, float y) {
//	return ;
//}

bool DropManager::clickDown(float x, float y) {
	this->figuraDrag == NULL ? this->zona->drag(x,y) : NULL;
	return true;
}

bool DropManager::clickUp(float x, float y) {
	if(this->figuraDrag != NULL){
		this->figuraDrag->drop(this);
		this->figuraDrag = NULL;
	}
	return true;
}

bool DropManager::mouseMotion(float corrimientoX, float corrimientoY) {
	if(this->figuraDrag != NULL){
		//TODO MANEJAR EL DRAG;
	}
	// consume el evento
	return false;
}
