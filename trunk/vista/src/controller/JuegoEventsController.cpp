/*
 * JuegoEventsController.cpp
 *
 *  Created on: 07/09/2013
 *      Author: jonathan
 */

#include "JuegoEventsController.h"

#include <src/figura/Figura.h>
#include <src/ModeloController.h>
#include <src/Transformacion.h>
#include <src/Vista.h>

#include "../vista/figura/FiguraView.h"
#include "editor/EditorNivel.h"
#include "Resizer.h"
#include "zonaDragAndDrop/ZonaCreacion.h"
#include "zonaDragAndDrop/ZonaDragAndDrop.h"
#include "zonaDragAndDrop/ZonaPlay.h"
#include "zonaDragAndDrop/ZonaTablero.h"
#include "src/Logger.h"
#include "src/Constantes.h"
using namespace std;

JuegoEventsController::JuegoEventsController(ModeloController *modeloController,
		ZonaPlay * zplay) {
	this->tablero = NULL;
	this->creacion = NULL;
	this->modeloController = modeloController;
	this->zplay = zplay;
	editor = NULL;
	iniciado = false;
	Resizer*r = Resizer::Instance();
	r->addResizeable(this);
	trans = new Transformacion();
	trans->traslacion(0, 100);
	trans->escalar(r->getRelacionX(), r->getRelacionY());
	trans->invertir(false, true);
	this->modeloController->setTransformacion(trans);

}

JuegoEventsController::~JuegoEventsController() {
	delete trans;
}

bool JuegoEventsController::clickDown(int x, int y) {
	//Si hay un click y no tengo editor, entonces busco una vista y le pido el editor.
	if (editor == NULL) {
		Resizer* r = Resizer::Instance();
		float lX = r->resizearDistanciaPixelX(x);
		float lY = r->resizearPosicionPixelY(y);
		if (tablero != NULL && creacion != NULL && !zplay->click(lX, lY) &&!iniciado
				&& !creacion->click(lX, lY) ) {
			Transformacion trans;
			trans.traslacion(0, 100);
			trans.escalar(r->getRelacionX(), r->getRelacionY());
			trans.invertir(false, true);
			trans.setVector(x, y);
			float lX2, lY2;
			trans.getResultado(lX2, lY2);
			FiguraView * view = NULL;
			Figura * fig = this->modeloController->pickUp(lX2, lY2,CATEGORIA_UNION | CATEGORIA_FIGURAS);
			// VOY A BUSCAR TANTO A ZONA DE CREACION COMO A ZONA DE TABLERO EN BUSCA DE UNA VISTA, YA QUE CLICK IZQUIERDO PUEDE CREAR VISTA.
			if (fig != NULL) {
				view = (FiguraView *) fig->getVista();
			} else {
				view = this->creacion->getVista(lX, lY);
			}

			if (view != NULL) {
				editor = view->getEditor();
				if (editor == NULL) {
					Logger log;
					log.fatal("La Vista no tiene un editor");
					throw "La Vista no tiene un editor";
				}
				editor->clickDown(x, y);
				if (editor->isEnd()) {
					editor = NULL;
				}
				return false;
			}
		}
	} else {
		editor->clickDown(x,y);
		if (editor->isEnd()) {
			editor = NULL;
		}
		return false;
	}
	return true;
}

bool JuegoEventsController::clickUp(int x, int y) {
	if (editor != NULL && !iniciado) {
		editor->clickUp(x, y);
		editor = editor->isEnd() ? NULL : editor;
	}
	return true;
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

void JuegoEventsController::setZonas(ZonaTablero *tablero,
		ZonaCreacion * creacion) {
	this->tablero = tablero;
	this->creacion = creacion;
}

bool JuegoEventsController::mouseMotion(int corrimientoX, int corrimientoY) {
	if (editor != NULL && !iniciado) {
		editor->mouseMotion(corrimientoX, corrimientoY);
		editor = editor->isEnd() ? NULL : editor;
	}
	return true;
}

bool JuegoEventsController::rightClickDown(int x, int y) {
	//Si hay un click y no tengo editor, entonces busco una vista y le pido el editor.
	if(iniciado) {
		return true;
	}
	if (editor == NULL) {
		if (tablero != NULL && creacion != NULL) {
			Resizer* r = Resizer::Instance();
			Transformacion trans;
			trans.traslacion(0, 100);
			trans.escalar(r->getRelacionX(), r->getRelacionY());
			trans.invertir(false, true);
			trans.setVector(x, y);
			float lX2, lY2;
			trans.getResultado(lX2, lY2);
			Figura * fig = this->modeloController->pickUp(lX2, lY2,CATEGORIA_UNION | CATEGORIA_FIGURAS);
			// VOY A BUSCAR SOLO A LA ZONA DE TABLERO
			if (fig != NULL) {
				editor = ((FiguraView *) fig->getVista())->getEditor();
				editor->rightClickDown(x, y);
				editor = editor->isEnd() ? NULL : editor;
			}
		}
	} else {
		editor->rightClickDown(x,y);
		if (editor->isEnd()) {
			editor = NULL;
		}
		return false;
	}
	return true;
}

bool JuegoEventsController::rightClickUp(int x, int y) {
	if (editor != NULL && !iniciado) {
		editor->rightClickUp(x, y);
		editor = editor->isEnd() ? NULL : editor;
	}
	return true;
}
void JuegoEventsController::dibujarse(SDL_Renderer* renderer) {
	tablero->dibujarse(renderer);
	creacion->dibujarse(renderer);
	zplay->dibujarse(renderer);
	if (editor != NULL) {
		editor->dibujarEdicion(renderer);
	}
}

void JuegoEventsController::dibujarse(SDL_Renderer*renderer, SDL_Rect& dest) {
	tablero->dibujarse(renderer, dest);
	creacion->dibujarse(renderer, dest);
	zplay->dibujarse(renderer);
	if (editor != NULL) {
		editor->dibujarEdicion(renderer);
	}

}

void JuegoEventsController::start() {
	this->modeloController->start();
	this->iniciado = true;
}

void JuegoEventsController::stop() {
	modeloController->stop();
	this->iniciado = false;
}

void JuegoEventsController::paso() {
	if (iniciado) {

		this->modeloController->step();
	}
}

bool JuegoEventsController::corriendo() {
	return iniciado;
}

void JuegoEventsController::resizear() {
	Resizer * r = Resizer::Instance();
	trans->traslacion(0, 100);
	trans->escalar(r->getRelacionX(), r->getRelacionY());
	trans->invertir(false, true);
	this->modeloController->setTransformacion(trans);
}
