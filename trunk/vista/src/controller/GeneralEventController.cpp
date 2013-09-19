/*
 * GeneralEventController.cpp
 *
 *  Created on: 07/09/2013
 *      Author: jonathan
 */

#include "GeneralEventController.h"
#include "mouseEventController/MouseEventPriorComparator.h"
#include "../controller/UserEventCreator.h"
#include "SDL2/SDL.h"
#include <iostream>
#define ASCII_SHIFT 15
GeneralEventController::GeneralEventController() {
	this->botonAnterior= 0;
	this->canvasController = 0;
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

void GeneralEventController::addKeyboardController(KeyBoardEventController* keyEventController) {
	this->keyControllers.push_back(keyEventController);
}

void GeneralEventController::keyDown(char key) {
	list<KeyBoardEventController*>::iterator it;
	bool continuarEvento = true ;
	for (it = this->keyControllers.begin(); it != this->keyControllers.end() && continuarEvento; ++it)
	{
		continuarEvento = (*it)->keyPressed(key);
	}
}

void GeneralEventController::addCanvasController(CanvasController* canvasController){
	this->canvasController = canvasController;
}

bool GeneralEventController::verificarCaracteresEspeciales(SDL_KeyboardEvent key) {
	if (key.keysym.scancode == SDL_SCANCODE_LSHIFT)
	{
		this->keyDown((char)ASCII_SHIFT);
		return true;
	}
//	if (key.keysym.sym >=)
	return false;
}

void GeneralEventController::keyUp() {
	list<KeyBoardEventController*>::iterator it;
	bool continuarEvento = true ;
	for (it = this->keyControllers.begin(); it != this->keyControllers.end() && continuarEvento; ++it)
	{
		continuarEvento = (*it)->keyReleased();
	}

}

void GeneralEventController::resize(int nuevoX, int nuevoY) {
		Resizer::Instance()->setearResizer(nuevoX,nuevoY);
		Resizer::Instance()->resizearResizeables();
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
	case SDL_KEYDOWN:
		if (!this->verificarCaracteresEspeciales(evento.key))
		this->keyDown((char)(evento.key.keysym.sym));
		break;
	case SDL_KEYUP:
		if (evento.key.keysym.scancode == SDL_SCANCODE_LSHIFT)
		this->keyUp();
		break;
	case SDL_USEREVENT:
		switch (evento.user.code) {
			case USREVENT_CHANGEBACKGROUND:
				if(this->canvasController != NULL){
					this->canvasController->atenderEvento(evento);
				}
				break;
			case USREVENT_SAVEGAME:
				cout << "Evento de salvar partida capturado." <<endl;
				break;
		}
		break;
	case SDL_WINDOWEVENT: {
		switch (evento.window.event) {
//TODO IMPLEMENTAR RESIZE
        		case SDL_WINDOWEVENT_RESIZED:
        			int tamNuevoX, tamNuevoY;
        			SDL_GetWindowSize(ventana,&tamNuevoX,&tamNuevoY);
        			if(tamNuevoX != tamNuevoY)
        				SDL_SetWindowSize(ventana,tamNuevoX,tamNuevoX);
        				this->resize(tamNuevoX, tamNuevoY);
        			//Resizeables tienen que resizear
        			break;
        		}
		break;
	}
	}
	return false;
}
