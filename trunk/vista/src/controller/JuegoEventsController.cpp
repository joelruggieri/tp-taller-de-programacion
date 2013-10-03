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

#include "../vista/figura/RuedaView.h"
#include "../vista/figura/CirculoView.h"
#include "../vista/figura/FiguraView.h"
#include "../vista/figura/TrianguloView.h"
#include "../vista/figura/GloboView.h"
#include "../vista/figura/PelotaView.h"

#include "../vista/View.h"
#include "Resizer.h"
#include "zonaDragAndDrop/ZonaDragAndDrop.h"
#include "src/Logger.h"
#include "src/Transformacion.h"
using namespace std;

JuegoEventsController::JuegoEventsController(ModeloController *modeloController, ZonaPlay * zplay,
		FiguraFactory* factory, int yMaxDrag) {
	this->figurasFactory = factory;
	this->elementoDrag = NULL;
	this->tablero = NULL;
	this->creacion = NULL;
	this->figuraRotacion = NULL;
	this->rot = NULL;
	this->posStartDragX = 0;
	this->posStartDragY = 0;
	this->modeloController = modeloController;
	this->yMaxDrag = yMaxDrag;
	this->zplay = zplay;
	iniciado = false;
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
	figura->setVista(view);
	log.info("Finaliza Drag");
	if (this->tablero != NULL && this->creacion != NULL) {
		bool exitoVista = tablero->agregarFigura(view);
		bool exitoModelo = this->modeloController->crearFigura(figura);
		if (!exitoVista || !exitoModelo) {
//si uno de los dos no tuvo exito probamos rollbackeando.
			if (exitoVista) {
				tablero->removerFigura(view);
			}
			if (exitoModelo) {
				modeloController->removerFigura(figura);
			}
			if (!this->elementoDrag->isRolledBack()) {
				log.info(
						"El Drag no pudo completarse, se retorna a la posicion anterior");
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
	float x;
	float y;
	r->adaptarPosicionPixel(view->getXCentro(), view->getYCentro(), x, y);
	dropear(view, this->figurasFactory->crearCirculo(x, y));
}

void JuegoEventsController::dropNuevaFigura(TrianguloView* view) {
	Resizer* r = Resizer::Instance();
	float x;
	float y;
	r->adaptarPosicionPixel(view->getXCentro(), view->getYCentro(), x, y);
	dropear(view, this->figurasFactory->crearTriangulo(x, 100 - y));
}

void JuegoEventsController::dropFigura(FiguraView* view) {
	Figura* modelo = view->getModelo();
	Resizer * r = Resizer::Instance();
	float x;
	float y;
	r->adaptarPosicionPixel(view->getXCentro(), view->getYCentro(), x, y);
	modelo->setX(x);
	modelo->setY(100 - y);
	this->dropear(view, modelo);
}

void JuegoEventsController::dropNuevaFigura(RuedaView* view) {
	Resizer* r = Resizer::Instance();
	float x;
	float y;
	r->adaptarPosicionPixel(view->getXCentro(), view->getYCentro(), x, y);
	dropear(view, this->figurasFactory->crearRueda(x, y));
}

void JuegoEventsController::dropNuevaFigura(GloboView* view) {
	Resizer* r = Resizer::Instance();
	float x;
	float y;
	r->adaptarPosicionPixel(view->getXCentro(), view->getYCentro(), x, y);
	dropear(view, this->figurasFactory->crearGlobo(x, y));
}

void JuegoEventsController::dropNuevaFigura(PelotaView* view) {
	Resizer* r = Resizer::Instance();
	float x;
	float y;
	r->adaptarPosicionPixel(view->getXCentro(), view->getYCentro(), x, y);
	dropear(view, this->figurasFactory->crearPelota(x, y));
}

void JuegoEventsController::dropNuevaFigura(MotorView* view) {

	Resizer* r = Resizer::Instance();
	float x;
	float y;
	r->adaptarPosicionPixel(view->getXCentro(), view->getYCentro(), x, y);
	dropear(view, this->figurasFactory->crearMotor(x, 100 - y));
}

bool JuegoEventsController::clickDown(int x, int y) {
	//prueba de hacer click en la zona
	Resizer* r = Resizer::Instance();
	float lX = r->resizearDistanciaPixelX(x);
	float lY = r->resizearPosicionPixelY(y);
	if (tablero != NULL && creacion != NULL && !creacion->click(lX,lY) && !zplay->click(lX,lY) &&(this->figuraRotacion == NULL)) {
		FiguraView * view = NULL;
		Transformacion trans;
		trans.traslacion(0,100);
		trans.escalar(r->getRelacionX(),r->getRelacionY());
		trans.invertir(false,true);
		trans.setVector(x,y);
		float lX2, lY2;
		trans.getResultado(lX2, lY2);
		Figura * fig = this->modeloController->pickUp(lX2, lY2);

		if(fig != NULL){
			view = (FiguraView * )fig->getVista();
		} else {
			view = this->creacion->getVista(lX,lY);
		}

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
	Resizer * r = Resizer::Instance();
	if (tablero != NULL && creacion != NULL) {
		if (!isDragging()) {
			r->adaptarPosicionLogica(x, y, this->posStartDragX,
					this->posStartDragY);
			this->elementoDrag = new Drag(figura,
					Resizer::Instance()->resizearPosicionLogicaY(yMaxDrag));
			log.info("Comienza Drag");
		}
		tablero->removerFigura(figura);
		if (figura->getModelo() != NULL) {
			this->modeloController->removerFigura(figura->getModelo());
		}
		mouseMotion(posStartDragX, posStartDragY);
	}
}

bool JuegoEventsController::mouseWheelMoved(int x, int y, int amountScrolled) {
	Resizer* r = Resizer::Instance();
	float lX = r->resizearDistanciaPixelX(x);
	float lY = r->resizearPosicionPixelY(y);
	if (creacion != NULL) {
		return creacion->mouseScroll(lX, lY, amountScrolled);
	}
	return true;
}


void JuegoEventsController::setZonas(ZonaTablero *tablero, ZonaCreacion * creacion) {
	this->tablero = tablero;
	this->creacion = creacion;
}

bool JuegoEventsController::mouseMotion(int corrimientoX, int corrimientoY) {
	if (this->elementoDrag != NULL) {
		int yBack = this->elementoDrag->getYCentro();
		int xBack = this->elementoDrag->getXCentro();
		int deltaX = this->elementoDrag->getXCentro() + corrimientoX
				- this->posStartDragX;
		int deltaY = this->elementoDrag->getYCentro() + corrimientoY
				- this->posStartDragY;
		this->elementoDrag->desplazarCentroA(deltaX, deltaY);
		//si no se pudo hacer el desplazamiento no hago el corrimiento;
		this->posStartDragX = deltaX - xBack + this->posStartDragX;
		this->posStartDragY = deltaY - yBack + this->posStartDragY;
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
		log.concatenar(mensaje_info,
				this->figuraRotacion->getModelo()->getRotacion());
		log.debug(mensaje_info);
	}
	// consume el evento
	return false;
}

bool JuegoEventsController::isDragging() {
	return this->elementoDrag != NULL;
}

bool JuegoEventsController::rightClickDown(int x, int y) {
	if (tablero != NULL && creacion != NULL && this->elementoDrag == NULL) {
		Resizer* r = Resizer::Instance();
		float lX;
		float lY;
		r->adaptarPosicionPixel(x, y, lX, lY);
		Figura* fig = modeloController->pickUp(lX, 100 - lY);
//		FiguraView * view = tablero->getVista(lX, lY);
		FiguraView * view = fig != NULL ? (FiguraView *)fig->getVista() : NULL;
		if (view != NULL) {
			if (view->getModelo() != NULL) {
				tablero->removerFigura(view);
				this->modeloController->removerFigura(view->getModelo());
				//Verifico si se apreto el shift tambien.
				const Uint8 *keyboardState = SDL_GetKeyboardState(NULL);
				if (keyboardState[SDL_SCANCODE_LSHIFT])
					return false;
				else {
					this->figuraRotacion = view;
					this->rot = new Rotacion(this->figuraRotacion->getXCentro(),
							r->getAltoPantalla()
									- this->figuraRotacion->getYCentro(), x,
							r->getAltoPantalla() - y, 0);
					return false;
				}
			} else {
				delete view;
			}
		}
	}
	return true;
}

bool JuegoEventsController::rightClickUp(int int1, int int2) {
	if (this->figuraRotacion != NULL) {
		tablero->agregarFigura(this->figuraRotacion);
		this->modeloController->crearFigura(this->figuraRotacion->getModelo());
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
	tablero->dibujarse(renderer);
	creacion->dibujarse(renderer);
	zplay->dibujarse(renderer);
}

void JuegoEventsController::dibujarse(SDL_Renderer*renderer, SDL_Rect& dest) {
	tablero->dibujarse(renderer,dest);
	creacion->dibujarse(renderer,dest);
}

void JuegoEventsController::start() {
	this->iniciado = true;
}

void JuegoEventsController::stop() {
	this->iniciado = false;
}

void JuegoEventsController::paso() {
	Resizer * r = Resizer::Instance();
	Transformacion trans;
	trans.traslacion(0,100);
	trans.escalar(r->getRelacionX(),r->getRelacionY());
	trans.invertir(false,true);

	if(iniciado){
		this->modeloController->step(trans);
	}
}
