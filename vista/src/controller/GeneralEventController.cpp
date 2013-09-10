/*
 * GeneralEventController.cpp
 *
 *  Created on: 07/09/2013
 *      Author: jonathan
 */

#include "GeneralEventController.h"
#include "mouseEventController/MouseEventPriorComparator.h"
#include "SDL2/SDL.h"

GeneralEventController::GeneralEventController() {
}

GeneralEventController::~GeneralEventController() {
	list<MouseControllerPrioridades*>::iterator it;
	for (it = this->mouseControllers.begin();
			it != this->mouseControllers.end(); ++it) {
		delete *it;
	}
}

void GeneralEventController::addMouseController(
		MouseEventController* controller, int prioridadClick,
		int prioridadMotion) {
	this->mouseControllers.push_back(
			new MouseControllerPrioridades(controller, prioridadClick,
					prioridadMotion));
}

void GeneralEventController::clickUp(int x, int y) {
	this->mouseControllers.sort(comparar_prioridadClick);
	list<MouseControllerPrioridades*>::iterator it;
	//los de mayor prioridad para el evento podrán cortar el evento a los de menor prioridad
	bool continuarEvento = true;
	for (it = this->mouseControllers.begin();
			it != this->mouseControllers.end() && continuarEvento; ++it) {
		continuarEvento = (*it)->getEventController()->clickUp(x, y);
	}
}

void GeneralEventController::clickDown(int x, int y) {
	this->mouseControllers.sort(comparar_prioridadClick);
	list<MouseControllerPrioridades*>::iterator it;
	//los de mayor prioridad para el evento podrán cortar el evento a los de menor prioridad
	bool continuarEvento = true;
	for (it = this->mouseControllers.begin();
			it != this->mouseControllers.end() && continuarEvento; ++it) {
		continuarEvento = (*it)->getEventController()->clickDown(x, y);
	}

}

void GeneralEventController::mouseMotion(int x, int y) {
	this->mouseControllers.sort(comparar_prioridadMotion);
	list<MouseControllerPrioridades*>::iterator it;
	//los de mayor prioridad para el evento podrán cortar el evento a los de menor prioridad
	bool continuarEvento = true;
	for (it = this->mouseControllers.begin();
			it != this->mouseControllers.end() && continuarEvento; ++it) {
		continuarEvento = (*it)->getEventController()->mouseMotion(x, y);
	}

}

bool GeneralEventController::procesarEventos() {
	int x, y;
	int nuevaPosX, nuevaPosY;
//	int tamNuevoX, tamNuevoY;
	SDL_Event evento;
	x = y = 0;
	SDL_PollEvent(&evento);
	switch (evento.type) {
	case SDL_QUIT:
		return true;
		break;
	case SDL_MOUSEBUTTONDOWN:

		if (SDL_GetMouseState(&x, &y) & SDL_BUTTON(1)) {
			this->clickDown(x, y);
		}
		break;
	case SDL_MOUSEBUTTONUP:
		SDL_GetMouseState(&x, &y);
		this->clickUp(x, y);
		break;
	case SDL_MOUSEMOTION:
		SDL_GetMouseState(&nuevaPosX, &nuevaPosY);
		this->mouseMotion(nuevaPosX, nuevaPosY);
		break;
	case SDL_WINDOWEVENT: {
//			switch (evento.window.event) {
//TODO IMPLEMENTAR RESIZE
//        		case SDL_WINDOWEVENT_RESIZED:
//        			cout << "Hubo un resize" << endl;
//        			SDL_GetWindowSize(ventana,&tamNuevoX,&tamNuevoY);
//
//        			canvas->Resizear(tamNuevoX,  tamNuevoY);
//        			canvas->Resizear(tamNuevoX - tamVentanaX, tamNuevoY - tamVentanaY);
//        			boton->Resizear(tamNuevoX - tamVentanaX, tamNuevoY - tamVentanaY);
//        			textBox->Resizear(tamNuevoX - tamVentanaX, tamNuevoY - tamVentanaY);
//        			tamVentanaX = tamNuevoX ;
//        			tamVentanaY = tamNuevoY;
//        			//Resizeables tienen que resizear
//        			break;
//        		}
		break;
	}
	}
	return false;
}
