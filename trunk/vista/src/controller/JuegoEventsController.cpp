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

JuegoEventsController::JuegoEventsController(ZonaPlay * zplay,ZonaTablero *tablero, ZonaCreacion * creacion, Transformacion * tl) {
	this->zplay = zplay;
	this->tablero = tablero;
	this->creacion = creacion;
	this->tl = tl;
}

JuegoEventsController::~JuegoEventsController() {
}

bool JuegoEventsController::clickDown(int x, int y) {
	tl->setVector(x,y);
	float xf,yf;
	tl->getResultado(xf,yf);
	if(!tablero->click(xf,yf)){
		if(!zplay->click(xf,yf)){
			return creacion->click(xf,yf);
		}
	}

	return true;
}

bool JuegoEventsController::clickUp(int x, int y) {
	tl->setVector(x,y);
	float xf,yf;
	tl->getResultado(xf,yf);
	if(!tablero->clickUp(xf,yf)){
//		if(!zplay->clickUp(xf,yf)){
			return creacion->clickUp(xf,yf);
//		}
	}

	return true;
}

bool JuegoEventsController::mouseWheelMoved(int x, int y, int amountScrolled) {
	//ENTREGA3 USAR TL
	tl->setVector(x,y);
	float xf,yf;
	tl->getResultado(xf,yf);
	creacion->mouseScroll(xf,yf,amountScrolled);
	return true;
}


bool JuegoEventsController::mouseMotion(int corrimientoX, int corrimientoY) {
//	if (editor != NULL && !iniciado) {
//		editor->mouseMotion(corrimientoX, corrimientoY);
//		editor = editor->isEnd() ? NULL : editor;
//	}
	tl->setVector(corrimientoX, corrimientoY );
		float xf,yf;
		tl->getResultado(xf,yf);
		tablero->mouseMotion(xf, yf);
	return true;
}

bool JuegoEventsController::rightClickDown(int x, int y) {
	tl->setVector(x,y);
		float xf,yf;
		tl->getResultado(xf,yf);
		if(!tablero->rightClick(xf,yf)){
			//ENTREGA3 con zonas donde el click derecho no influye qe hacemos ?
//			if(!zplay->rightClick(xf,yf)){
//				return creacion->rightClick(xf,yf);
//			}
		}

		return true;

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
}
bool JuegoEventsController::rightClickUp(int x, int y) {
//	if (editor != NULL && !iniciado) {
//		editor->rightClickUp(x, y);
//		editor = editor->isEnd() ? NULL : editor;
//	}
	tl->setVector(x,y);
			float xf,yf;
			tl->getResultado(xf,yf);
	tablero->rightClickUp(xf,yf);
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

void JuegoEventsController::resize(Transformacion* tl) {
	if(this->tl != NULL){
		delete this->tl;
	}
	this->tl = tl;
}

}

