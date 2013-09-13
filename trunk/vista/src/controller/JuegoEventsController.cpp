/*
 * JuegoEventsController.cpp
 *
 *  Created on: 07/09/2013
 *      Author: jonathan
 */

#include "JuegoEventsController.h"

#include <src/figura/Figura.h>
#include <src/figuraFactory/FiguraFactory.h>
#include <iostream>
#include <new>
#include <string>

#include "../vista/figura/CirculoView.h"
#include "../vista/figura/CuadradoView.h"
#include "../vista/figura/FiguraView.h"
#include "../vista/figura/TrianguloView.h"
#include "../vista/View.h"
#include "Resizer.h"
#include "zonaDragAndDrop/ZonaDragAndDrop.h"

class RomboView;

using namespace std;

JuegoEventsController::JuegoEventsController() {
	this->figurasFactory = new FiguraFactory();
	this->figuraDrag = NULL;
	this->zona = NULL;
}

JuegoEventsController::~JuegoEventsController() {
	delete this->figurasFactory;
	if (this->figuraDrag != NULL) {
		delete this->figuraDrag;
	}
}

void JuegoEventsController::dropear(FiguraView* view, Figura* figura) {
	cout << "dropea figura controller" << endl;
	view->setModelo(figura);
	if (this->zona != NULL && !zona->agregarFigura(view)) {
		delete figura;
		delete view;
	}
}

void JuegoEventsController::dropNuevaFigura(CirculoView* view) {
	Resizer* r = Resizer::Instance();
	dropear(view,
			this->figurasFactory->crearCirculo(
					r->resizearDistanciaPixelX(view->getXCentro()),
					r->resizearDistanciaPixelX(view->getYCentro())));
}

void JuegoEventsController::dropNuevaFigura(TrianguloView* view) {
	Resizer* r = Resizer::Instance();
	dropear(view,
			this->figurasFactory->crearTriangulo(
					r->resizearDistanciaPixelX(view->getXCentro()),
					r->resizearDistanciaPixelY(view->getYCentro())));
}

void JuegoEventsController::dropNuevaFigura(CuadradoView* view) {
	Resizer* r = Resizer::Instance();
	dropear(view,
			this->figurasFactory->crearCuadrado(
					r->resizearDistanciaPixelX(view->getXCentro()),
					r->resizearDistanciaPixelY(view->getYCentro())));
}

void JuegoEventsController::dropFigura(FiguraView* view) {
	Figura* modelo = view->getModelo();
	Resizer * r = Resizer::Instance();
	modelo->setX(r->resizearDistanciaPixelX(view->getXCentro()));
	modelo->setY(r->resizearDistanciaPixelY(view->getYCentro()));
	this->dropear(view, modelo);
}

bool JuegoEventsController::clickDown(int x, int y) {
	//prueba de hacer click en la zona
	Resizer* r = Resizer::Instance();
	float lX = r->resizearDistanciaPixelX(x);
	float lY = r->resizearDistanciaPixelY(y);
	if (zona != NULL && !zona->click(lX, lY) && this->figuraRotacion == NULL) {
		FiguraView * view = this->zona->getVista(lX, lY);
		if (view != NULL) {
			view->click(lX, lY);
			return false;
		}
	}
	return true;
}

bool JuegoEventsController::clickUp(int x, int y) {
	if (this->figuraDrag != NULL) {
		//TODO ESTO DEBERÍA ACTUALIZAR LA POSICION DE LA IMAGEN, EN EL DROP SE DEBERÍA IMPACTAR TAMBIEN EN EL MODELO
		this->figuraDrag->drop();
		this->figuraDrag = NULL;
	}
//	if(this->figuraRotacion != NULL){
//		this->rightClickUp(x,y);
//	}
	return true;
}

void JuegoEventsController::drag(FiguraView* figura, float x, float y) {
	//TENGO QUE AVISAR AL JUEGO QUE SUSPENDA VISTA.
	cout << "draguea figura controller" << endl;
	if (zona != NULL) {
		this->zona->removerFigura(figura);
		this->figuraDrag = figura;

		mouseMotion(Resizer::Instance()->resizearDistanciaLogicaX(x),
				Resizer::Instance()->resizearDistanciaLogicaY(y));
	}
}

void JuegoEventsController::dropNuevaFigura(RomboView* figura) {
}

Zona* JuegoEventsController::getZona() {
	return zona;
}

void JuegoEventsController::setZona(Zona* zona) {
	this->zona = zona;
}

bool JuegoEventsController::mouseMotion(int corrimientoX, int corrimientoY) {
	if (this->figuraDrag != NULL) {
		this->figuraDrag->desplazarCentroA(corrimientoX, corrimientoY);
	}
	Resizer* r = Resizer::Instance();
	if (this->figuraRotacion != NULL) {
		this->rot->rotar(corrimientoX, r->getAltoPantalla() - corrimientoY);
		this->figuraRotacion->getModelo()->setRotacion(
				this->figuraRotacion->getModelo()->getRotacion()
						+ this->rot->getAngulo());
		cout << "rotacion total "
				<< this->figuraRotacion->getModelo()->getRotacion() << endl;
		;
	}
	// consume el evento
	return false;
}

bool JuegoEventsController::isDragging() {
	return this->figuraDrag != NULL;
}

bool JuegoEventsController::rightClickDown(int x, int y) {
	if (zona != NULL) {
		Resizer* r = Resizer::Instance();
		float lX = r->resizearDistanciaPixelX(x);
		float lY = r->resizearDistanciaPixelY(y);
		FiguraView * view = this->zona->getVista(lX, lY);
		if (view != NULL) {
			if (view->getModelo() != NULL) {
				this->zona->removerFigura(view);
				this->figuraRotacion = view;
				Resizer* r = Resizer::Instance();
				this->rot = new Rotacion(this->figuraRotacion->getXCentro(),
						r->getAltoPantalla()
								- this->figuraRotacion->getYCentro(), x,
						r->getAltoPantalla() - y, 0);
				return false;
			} else {
				delete view;
			}
		}
	}
	return true;
}

bool JuegoEventsController::rightClickUp(int int1, int int2) {
	if (this->figuraRotacion != NULL) {
		//TODO ESTO DEBERÍA ACTUALIZAR LA POSICION DE LA IMAGEN, EN EL DROP SE DEBERÍA IMPACTAR TAMBIEN EN EL MODELO
		this->zona->agregarFigura(this->figuraRotacion);
		this->figuraRotacion = NULL;
		delete this->rot;
	}
	return true;
}

View* JuegoEventsController::getDragueado() {
	return this->figuraDrag;
}

bool JuegoEventsController::isRotando() {
	return this->figuraRotacion != NULL;
}

View* JuegoEventsController::getRotado() {
	return this->figuraRotacion;
}
