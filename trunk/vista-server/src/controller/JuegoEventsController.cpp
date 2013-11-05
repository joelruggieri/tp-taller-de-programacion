/*
 * JuegoEventsController.cpp
 *
 *  Created on: 07/09/2013
 *      Author: jonathan
 */

#include "JuegoEventsController.h"

#include <src/figura/Figura.h>
#include <src/ModeloController.h>
#include <src/Vista.h>

#include "../vista/figura/FiguraView.h"
#include "editor/EditorNivel.h"
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
}

JuegoEventsController::~JuegoEventsController() {
}

bool JuegoEventsController::clickDown(float x, float y) {
	//Si hay un click y no tengo editor, entonces busco una vista y le pido el editor.
	if (editor == NULL) {
		if (tablero != NULL && creacion != NULL && !zplay->click(x, y) &&!iniciado
				//ENTREGA3 DAR VUELTA EL SISTEMA DE COORDENADAS DE LA TOOLBAR DERECHA
				&& !creacion->click(x, y) ) {
			FiguraView * view = NULL;
			Figura * fig = this->modeloController->pickUp(x, y,CATEGORIA_UNION | CATEGORIA_FIGURAS);
			// VOY A BUSCAR TANTO A ZONA DE CREACION COMO A ZONA DE TABLERO EN BUSCA DE UNA VISTA, YA QUE CLICK IZQUIERDO PUEDE CREAR VISTA.
			if (fig != NULL) {
				view = (FiguraView *) fig->getVista();
			} else {
				view = this->creacion->getVista(x, y);
			}

			if (view != NULL) {
				editor = view->getEditor();
				editor->setCtrl(this->control);
				editor->setShift(this->shift);
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
		editor->setCtrl(this->control);
		editor->setShift(this->shift);
		editor->clickDown(x,y);
		if (editor->isEnd()) {
			editor = NULL;
		}
		return false;
	}
	return true;
}

bool JuegoEventsController::clickUp(float x, float y) {
	if (editor != NULL && !iniciado) {
		editor->setCtrl(this->control);
		editor->setShift(this->shift);
		editor->clickUp(x, y);
		editor = editor->isEnd() ? NULL : editor;
	}
	return true;
}

void JuegoEventsController::setZonas(ZonaTablero *tablero,
		ZonaCreacion * creacion) {
	this->tablero = tablero;
	this->creacion = creacion;
}

bool JuegoEventsController::mouseMotion(float corrimientoX, float corrimientoY) {
	if (editor != NULL && !iniciado) {
		editor->setCtrl(this->control);
		editor->setShift(this->shift);
		editor->mouseMotion(corrimientoX, corrimientoY);
		editor = editor->isEnd() ? NULL : editor;
	}
	return true;
}

bool JuegoEventsController::rightClickDown(float x, float y) {
	//Si hay un click y no tengo editor, entonces busco una vista y le pido el editor.
	if(iniciado) {
		return true;
	}
	if (editor == NULL) {
		if (tablero != NULL && creacion != NULL) {
			//ENTREGA3 UNIFICACION DE COORDENADAS EN TOOLBAR Y CREACION.
			Figura * fig = this->modeloController->pickUp(x, y,CATEGORIA_UNION | CATEGORIA_FIGURAS);
			// VOY A BUSCAR SOLO A LA ZONA DE TABLERO
			if (fig != NULL) {
				editor = ((FiguraView *) fig->getVista())->getEditor();
				editor->setCtrl(this->control);
				editor->setShift(this->shift);
				editor->rightClickDown(x, y);
				editor = editor->isEnd() ? NULL : editor;
			}
		}
	} else {
		editor->setCtrl(this->control);
		editor->setShift(this->shift);
		editor->rightClickDown(x,y);
		if (editor->isEnd()) {
			editor = NULL;
		}
		return false;
	}
	return true;
}

bool JuegoEventsController::rightClickUp(float x, float y) {
	if (editor != NULL && !iniciado) {
		editor->setCtrl(this->control);
		editor->setShift(this->shift);
		editor->rightClickUp(x, y);
		editor = editor->isEnd() ? NULL : editor;
	}
	return true;
}
void JuegoEventsController::dibujarse(list<ViewMsj*> & lista){
	tablero->dibujarse(lista);
	creacion->dibujarse(lista);
	zplay->dibujarse(lista);
	if (editor != NULL) {
		editor->setCtrl(this->control);
		editor->setShift(this->shift);
		editor->dibujarEdicion(lista);
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

bool JuegoEventsController::isCtrl() const {
return this->control;
}

bool JuegoEventsController::isShift() const {
	return this->shift;
}

void JuegoEventsController::setControl(bool a) {
this->control = a ;
}

void JuegoEventsController::setShift(bool a) {
	this->shift = a ;
}

int JuegoEventsController::getNumeroJugador() const {
	return numeroJugador;
}

void JuegoEventsController::setNumeroJugador(int numeroJugador) {
	this->numeroJugador = numeroJugador;
}
