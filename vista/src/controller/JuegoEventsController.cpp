/*
 * JuegoEventsController.cpp
 *
 *  Created on: 07/09/2013
 *      Author: jonathan
 */

#include "JuegoEventsController.h"


#include "../vista/figura/FiguraView.h"
#include "Resizer.h"
#include "zonaDragAndDrop/ZonaCreacion.h"
#include "zonaDragAndDrop/ZonaPlay.h"
#include "zonaDragAndDrop/ZonaTablero.h"
#include "GeneralEventController.h"
#include "src/Logger.h"
using namespace std;
namespace CLIENTE {

JuegoEventsController::JuegoEventsController(ZonaPlay * zplay) {
	this->tablero = NULL;
	this->creacion = NULL;
	this->zplay = zplay;
}

JuegoEventsController::~JuegoEventsController() {
}

bool JuegoEventsController::clickDown(int x, int y) {
	creacion->click(10,10);
	tablero->click(10,10);
	zplay->click(10,10);
	return true;
}

bool JuegoEventsController::clickUp(int x, int y) {
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
//	if (editor != NULL && !iniciado) {
//		editor->mouseMotion(corrimientoX, corrimientoY);
//		editor = editor->isEnd() ? NULL : editor;
//	}
	return true;
}

bool JuegoEventsController::rightClickDown(int x, int y) {
	//Si hay un click y no tengo editor, entonces busco una vista y le pido el editor.
//	if(iniciado) {
//		return true;
//	}
//	if (editor == NULL) {
//		if (tablero != NULL && creacion != NULL) {
//			Transformacion & trans = Resizer::Instance()->getTransformacionToModelo();
//			trans.setVector(x, y);
//			float lX2, lY2;
//			trans.getResultado(lX2, lY2);
//			Figura * fig = this->modeloController->pickUp(lX2, lY2,CATEGORIA_UNION | CATEGORIA_FIGURAS);
//			// VOY A BUSCAR SOLO A LA ZONA DE TABLERO
//			if (fig != NULL) {
//				editor = ((FiguraView *) fig->getVista())->getEditor();
//				editor->rightClickDown(x, y);
//				editor = editor->isEnd() ? NULL : editor;
//			}
//		}
//	} else {
//		editor->rightClickDown(x,y);
//		if (editor->isEnd()) {
//			editor = NULL;
//		}
//		return false;
//	}
	return true;
}

bool JuegoEventsController::rightClickUp(int x, int y) {
//	if (editor != NULL && !iniciado) {
//		editor->rightClickUp(x, y);
//		editor = editor->isEnd() ? NULL : editor;
//	}
	return true;
}
void JuegoEventsController::dibujarse(SDL_Renderer* renderer) {
//	tablero->dibujarse(renderer);
//	creacion->dibujarse(renderer);
//	zplay->dibujarse(renderer);
//	if (editor != NULL) {
//		editor->dibujarEdicion(renderer);
//	}
}

void JuegoEventsController::dibujarse(SDL_Renderer*renderer, SDL_Rect& dest) {
//	tablero->dibujarse(renderer, dest);
//	creacion->dibujarse(renderer, dest);
//	zplay->dibujarse(renderer);
//	if (editor != NULL) {
//		editor->dibujarEdicion(renderer);
//	}

}
}

