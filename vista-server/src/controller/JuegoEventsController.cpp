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
#include "zonaDragAndDrop/ZonaTablero.h"
#include "src/Logger.h"
#include "src/Constantes.h"
using namespace std;

JuegoEventsController::JuegoEventsController(ModeloController *modeloController) {
	this->tablero = NULL;
	this->creacion = NULL;
	this->modeloController = modeloController;
	editor = NULL;
	iniciado = false;
}

JuegoEventsController::~JuegoEventsController() {
}

bool JuegoEventsController::clickDown(float x, float y) {
	//ENTREGA3 SI ESTA INICIADO TIENE QUE LLAMAR ALGUN METODO DEL MODELO QUE LE SIRVA PARA INTERACTUAR CON LAS COSAS EN EL ESCENARIO.
	//Si hay un click y no tengo editor, entonces busco una vista y le pido el editor.
	if (editor == NULL) {
		if (!iniciado) {
			//ENTREGA3 DAR VUELTA EL SISTEMA DE COORDENADAS DE LA TOOLBAR DERECHA
			FiguraView * view = NULL;
			Figura * fig = this->modeloController->pickUp(x, y, CATEGORIA_UNION | CATEGORIA_FIGURAS);
			//ENTREGA3, no se va a buscar mas a la zona de creacion, ya que ahora viene por otro lado el evento de creacion
			if (fig != NULL) {
				view = (FiguraView *) fig->getVista();
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
		editor->clickDown(x, y);
		if (editor->isEnd()) {
			editor = NULL;
		}
		return false;
	}
	return true;
}

bool JuegoEventsController::clickUp(float x, float y) {
	if(iniciado){
		return true;
	}
	//SI NO HAY EDITOR NO PUEDO PROCESAR NADA ACA.
	if (editor != NULL) {
		editor->setCtrl(this->control);
		editor->setShift(this->shift);
		editor->clickUp(x, y);
		editor = editor->isEnd() ? NULL : editor;
	}
	return true;
}

void JuegoEventsController::setZonas(ZonaTablero *tablero, ZonaCreacion * creacion) {
	this->tablero = tablero;
	this->creacion = creacion;
}

bool JuegoEventsController::mouseMotion(float corrimientoX, float corrimientoY) {
	if(iniciado){
		return true;
	}
	//si hay editor le digo que se mueva, sino no hago nada
	if (editor != NULL) {
		editor->setCtrl(this->control);
		editor->setShift(this->shift);
		editor->mouseMotion(corrimientoX, corrimientoY);
		editor = editor->isEnd() ? NULL : editor;
	}
	return true;
}

bool JuegoEventsController::rightClickDown(float x, float y) {
	//Si hay un click y no tengo editor, entonces busco una vista y le pido el editor.
	if (iniciado) {
		return true;
	}
	if (editor == NULL) {
		// VOY A BUSCAR SOLO AL MODELO POR ALGO QUE EXISTA AHI.
		Figura * fig = this->modeloController->pickUp(x, y, CATEGORIA_UNION | CATEGORIA_FIGURAS);
		if (fig != NULL) {
			editor = ((FiguraView *) fig->getVista())->getEditor();
			editor->setCtrl(this->control);
			editor->setShift(this->shift);
			editor->rightClickDown(x, y);
			editor = editor->isEnd() ? NULL : editor;
		}
	} else {
		editor->setCtrl(this->control);
		editor->setShift(this->shift);
		editor->rightClickDown(x, y);
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
void JuegoEventsController::dibujarse(list<ViewMsj*> & lista) {
	tablero->dibujarse(lista);
	creacion->dibujarse(lista);
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
	this->control = a;
}

void JuegoEventsController::setShift(bool a) {
	this->shift = a;
}

int JuegoEventsController::getNumeroJugador() const {
	return numeroJugador;
}

void JuegoEventsController::setNumeroJugador(int numeroJugador) {
	this->numeroJugador = numeroJugador;
}

void JuegoEventsController::crearVista(string tag, float x, float y) {
	if (editor == NULL && !iniciado) {
		//si no estoy con un editor activo y no estoy iniciado puedo crear una vista y empezar la edicion (setear el editor de la vista)
		//ENTREGA3 PEDIRLE A LA ZONA DE CREACION CREARVISTA, si retorna distinta de NULL hay que hacer algo parecido a lo que hace el click down,
		FiguraView* view = creacion->crearFigura(tag, x , y);
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
//			return false;
		}

	}
	///ELSE NO HAGO NADA
}
