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
#include <sstream>

#include "../vista/figura/CirculoView.h"
#include "../vista/figura/CuadradoView.h"
#include "../vista/figura/FiguraView.h"
#include "../vista/figura/TrianguloView.h"
#include "../vista/View.h"
#include "Resizer.h"
#include "zonaDragAndDrop/ZonaDragAndDrop.h"

#include "src/Logger.h"


using namespace std;

JuegoEventsController::JuegoEventsController(ModeloController *modeloController, int yMaxDrag) {
	this->figurasFactory = new FiguraFactory();
	this->elementoDrag = NULL;
	this->zona = NULL;
	this->figuraRotacion = NULL;
	this->rot = NULL;
	this->posStartDragX = 0;
	this->posStartDragY = 0;
	this->modeloController = modeloController;
	this->yMaxDrag = yMaxDrag;
}

JuegoEventsController::~JuegoEventsController() {
	delete this->figurasFactory;
	if (this->elementoDrag != NULL) {
		delete this->elementoDrag;
	}
	if (this->figuraRotacion != NULL) {
		delete this->figuraRotacion;
	}
}

void JuegoEventsController::dropear(FiguraView* view, Figura* figura) {
	Logger log;
	view->setModelo(figura);
	log.info("Finaliza Drag");
	if (this->zona != NULL){
		bool exitoVista = zona->agregarFigura(view);
		bool exitoModelo =this->modeloController->crearFigura(figura);
		if(!exitoVista || !exitoModelo){
//si uno de los dos no tuvo exito probamos rollbackeando.
			if(exitoVista){
				zona->removerFigura(view);
			}
			if(exitoModelo){
				modeloController->removerFigura(figura);
			}
			if(!this->elementoDrag->isRolledBack()){
				log.info("El Drag no pudo completarse, se retorna a la posicion anterior");
				this->elementoDrag->rollBack();
				this->elementoDrag->drop();
			} else {
				delete figura;
				delete view;
				delete elementoDrag;
				elementoDrag = NULL;
			}
		} else {
			delete elementoDrag;
			elementoDrag = NULL;
		}
	}
}

void JuegoEventsController::dropNuevaFigura(CirculoView* view) {
	Resizer* r = Resizer::Instance();
	dropear(view,
			this->figurasFactory->crearCirculo(
					r->resizearDistanciaPixelX(view->getXCentro()),
					r->resizearDistanciaPixelY(view->getYCentro())));
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
	if (this->elementoDrag != NULL) {
		this->elementoDrag->drop();
		this->elementoDrag = NULL;
	}
	return true;
}

void JuegoEventsController::drag(FiguraView* figura, float x, float y) {
	//TENGO QUE AVISAR AL JUEGO QUE SUSPENDA VISTA.
	Logger log;
	//cout << "draguea figura controller" << endl;
	if (zona != NULL) {
		if (!isDragging()){
			this->posStartDragX = Resizer::Instance()->resizearDistanciaLogicaX(x);
			this->posStartDragY = Resizer::Instance()->resizearDistanciaLogicaY(y);
			this->elementoDrag = new Drag(figura, Resizer::Instance()->resizearDistanciaLogicaY(yMaxDrag));
			log.info("Comienza Drag");
		}
		this->zona->removerFigura(figura);
		if(figura->getModelo() != NULL){
			this->modeloController->removerFigura(figura->getModelo());
		}
		mouseMotion(posStartDragX, posStartDragY);
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
	if (this->elementoDrag != NULL ) {
		int yBack = this->elementoDrag->getYCentro();
		float deltaX = this->elementoDrag->getXCentro() + corrimientoX - this->posStartDragX;
		float deltaY = this->elementoDrag->getYCentro() + corrimientoY - this->posStartDragY;
		int posYAlcanzada = this->elementoDrag->desplazarCentroA(deltaX , deltaY);
		//si no se pudo hacer el desplazamiento no hago el corrimiento;
			this->posStartDragX = corrimientoX;
			this->posStartDragY = posYAlcanzada - yBack +this->posStartDragY;
		//cout << "X: " << this->elementoDrag->getXCentro() << " Y : " << this->elementoDrag->getXCentro() <<endl;
		//cout << "CX: " << corrimientoX << " CY: " << corrimientoY <<endl;
	}
	Resizer* r = Resizer::Instance();
	if (this->figuraRotacion != NULL) {
		this->rot->rotar(corrimientoX, r->getAltoPantalla() - corrimientoY);
		this->figuraRotacion->getModelo()->setRotacion(
				this->figuraRotacion->getModelo()->getRotacion()
						+ this->rot->getAngulo());
		Logger log;
		std::string mensaje_info = "Rotacion total ";
		log.concatenar(mensaje_info,this->figuraRotacion->getModelo()->getRotacion());
		log.debug(mensaje_info);
	}
	// consume el evento
	return false;
}

bool JuegoEventsController::isDragging() {
	return this->elementoDrag != NULL;
}

bool JuegoEventsController::rightClickDown(int x, int y) {
	if (zona != NULL  && this->elementoDrag == NULL) {
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
		this->zona->agregarFigura(this->figuraRotacion);
		this->figuraRotacion = NULL;
		delete this->rot;
	}
	return true;
}

View* JuegoEventsController::getDragueado() {
	return this->elementoDrag->getView();
}

bool JuegoEventsController::isRotando() {
	return this->figuraRotacion != NULL;
}

View* JuegoEventsController::getRotado() {
	return this->figuraRotacion;
}

void JuegoEventsController::dibujarse(SDL_Renderer* renderer) {
	this->zona->dibujarse(renderer);
}

