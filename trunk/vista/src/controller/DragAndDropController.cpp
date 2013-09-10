/*
 * DragAndDropController.cpp
 *
 *  Created on: 07/09/2013
 *      Author: jonathan
 */

#include "DragAndDropController.h"

#include "../vista/figura/FiguraView.h"
#include "Resizer.h"
#include <iostream>
using namespace std;

DragAndDropController::DragAndDropController() {
	this->figurasFactory = new FiguraFactory();
	this->figuraDrag = NULL;
	this->zona = NULL;
}

DragAndDropController::~DragAndDropController() {
	delete this->figurasFactory;
	if (this->figuraDrag != NULL) {
		delete this->figuraDrag;
	}
}

void DragAndDropController::dropear(FiguraView* view, Figura* figura) {
	cout<<"dropea figura controller"<<endl;
	view->setModelo(figura);
	if (this->zona != NULL && !zona->agregarFigura(view)) {
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
	Resizer* r = Resizer::Instance();
	dropear(view,
			this->figurasFactory->crearCuadrado(
					r->resizearDistanciaPixelX(view->getXCentro()),
					r->resizearDistanciaPixelY(view->getYCentro())));
}

void DragAndDropController::dropFigura(FiguraView* view) {
	Figura* modelo = view->getModelo();
	Resizer * r =Resizer::Instance();
	modelo->setX(r->resizearDistanciaPixelX(view->getXCentro()));
	modelo->setY(r->resizearDistanciaPixelY(view->getYCentro()));
	this->dropear(view, modelo);
}

bool DragAndDropController::clickDown(float x, float y) {
	if (zona != NULL) {
		this->zona->click(x, y);
		return false;
	}
	return true;
}

bool DragAndDropController::clickUp(float x, float y) {
	if (this->figuraDrag != NULL) {
		//TODO ESTO DEBERÍA ACTUALIZAR LA POSICION DE LA IMAGEN, EN EL DROP SE DEBERÍA IMPACTAR TAMBIEN EN EL MODELO
		this->figuraDrag->drop();
		this->figuraDrag = NULL;
	}
	return true;
}

void DragAndDropController::drag(FiguraView* figura, float x, float y) {
	//TENGO QUE AVISAR AL JUEGO QUE SUSPENDA VISTA.
	cout<<"draguea figura controller"<<endl;
	if (zona != NULL) {
		this->zona->removerFigura(figura);
		this->figuraDrag = figura;
	}
}

void DragAndDropController::dropNuevaFigura(RomboView* figura) {
}

Zona* DragAndDropController::getZona() {
	return zona;
}

void DragAndDropController::setZona(Zona* zona) {
	this->zona = zona;
}

bool DragAndDropController::mouseMotion(float corrimientoX,
		float corrimientoY) {
	if (this->figuraDrag != NULL) {
		this->figuraDrag->desplazarCentroA(corrimientoX, corrimientoY);
	}
	// consume el evento
	return false;
}

bool DragAndDropController::isDragging() {
	return this->figuraDrag != NULL;
}

View* DragAndDropController::getDragueado() {
	return this->figuraDrag;
}
