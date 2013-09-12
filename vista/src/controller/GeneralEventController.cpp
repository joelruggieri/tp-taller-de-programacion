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
	this->botonAnterior= 0;
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

void GeneralEventController::rightClickUp(int x, int y) {
	this->mouseControllers.sort(comparar_prioridadClick);
	list<MouseControllerPrioridades*>::iterator it;
	//los de mayor prioridad para el evento podrán cortar el evento a los de menor prioridad
	bool continuarEvento = true;
	for (it = this->mouseControllers.begin();
			it != this->mouseControllers.end() && continuarEvento; ++it) {
		continuarEvento = (*it)->getEventController()->rightClickUp(x, y);
	}
}

void GeneralEventController::rightClickDown(int x, int y) {
	this->mouseControllers.sort(comparar_prioridadClick);
	list<MouseControllerPrioridades*>::iterator it;
	//los de mayor prioridad para el evento podrán cortar el evento a los de menor prioridad
	bool continuarEvento = true;
	for (it = this->mouseControllers.begin();
			it != this->mouseControllers.end() && continuarEvento; ++it) {
		continuarEvento = (*it)->getEventController()->rightClickDown(x, y);
	}
}

bool GeneralEventController::procesarEventos(SDL_Window * ventana) {
	int nuevaPosX, nuevaPosY;
//	int tamNuevoX, tamNuevoY;
	SDL_Event evento;
	SDL_PollEvent(&evento);
	switch (evento.type) {
	case SDL_QUIT:
		return true;
		break;
	case SDL_MOUSEBUTTONDOWN:
		switch (evento.button.button) {
			case SDL_BUTTON_RIGHT:
				this->rightClickDown(evento.button.x, evento.button.y);
				break;
			case SDL_BUTTON_LEFT:
				this->clickDown(evento.button.x, evento.button.y);
			break;
		}
		break;
	case SDL_MOUSEBUTTONUP:
		switch (evento.button.button) {
			case SDL_BUTTON_RIGHT:
				this->rightClickUp(evento.button.x, evento.button.y);
				break;
			case SDL_BUTTON_LEFT:
				this->clickUp(evento.button.x, evento.button.y);
			break;
		}
		break;
	case SDL_MOUSEMOTION:
		SDL_GetMouseState(&nuevaPosX, &nuevaPosY);
		this->mouseMotion(nuevaPosX, nuevaPosY);
		break;
	case SDL_WINDOWEVENT: {
//			switch (evento.window.event) {
//TODO IMPLEMENTAR RESIZE
        		case SDL_WINDOWEVENT_RESIZED:
        			int tamNuevoX, tamNuevoY;
        			SDL_GetWindowSize(ventana,&tamNuevoX,&tamNuevoY);
        			if(tamNuevoX != tamNuevoY){
        				SDL_SetWindowSize(ventana,tamNuevoX,tamNuevoX);
        			}
        			//Resizeables tienen que resizear
        			break;
//        		}
		break;
	}
	}
	return false;
}
