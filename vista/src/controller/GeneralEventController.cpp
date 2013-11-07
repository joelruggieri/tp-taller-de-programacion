/*
 * GeneralEventController.cpp
 *
 *  Created on: 07/09/2013
 *      Author: jonathan
 */

#include "GeneralEventController.h"

#include <SDL2/SDL_events.h>
#include <SDL2/SDL_keyboard.h>
#include <SDL2/SDL_mouse.h>
#include <SDL2/SDL_scancode.h>
#include <SDL2/SDL_video.h>
#include <SDL2/SDL.h>
#include <iostream>
#include <list>
#include <string>
#define  MIN_VENTANA_Y 480
#define MIN_VENTANA_X 480
#define MAX_VENTANA 1500
#include "../controller/UserEventCreator.h"
#include "keyboardEventController/KeyBoardEventController.h"
#include "mouseEventController/MouseControllerPrioridades.h"
#include "mouseEventController/MouseEventController.h"
#include "mouseEventController/MouseEventPriorComparator.h"
#include "Resizer.h"
#include "src/Logger.h"

struct SDL_Window;
namespace CLIENTE {
#define ASCII_SHIFT 15
#define ASCII_MAYUS 16
GeneralEventController::GeneralEventController() {
	this->drawController = NULL;
	tamAnteriorX = 600;
	tamAnteriorY = 600;
//	SDL_SetWindowMaximumSize(this->v
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

void GeneralEventController::mouseWheelMoved(int amountScrolledY) {
	this->mouseControllers.sort(comparar_prioridadClick);
	list<MouseControllerPrioridades*>::iterator it;
	//los de mayor prioridad para el evento podrán cortar el evento a los de menor prioridad
	//Agarro la posicion del mouse.
	int posX, posY;
	SDL_GetMouseState(&posX, &posY);
	bool continuarEvento = true;
	for (it = this->mouseControllers.begin();
			it != this->mouseControllers.end() && continuarEvento; ++it) {
		continuarEvento = (*it)->getEventController()->mouseWheelMoved(posX,
				posY, amountScrolledY);
	}
}

void GeneralEventController::addKeyboardController(
		KeyBoardEventController* keyEventController) {
	this->keyControllers.push_back(keyEventController);
}

void GeneralEventController::keyDown(char key) {
	list<KeyBoardEventController*>::iterator it;
	bool continuarEvento = true;
	for (it = this->keyControllers.begin();
			it != this->keyControllers.end() && continuarEvento; ++it) {
		continuarEvento = (*it)->keyPressed(key);
	}
}

bool GeneralEventController::verificarCaracteresEspeciales(
		SDL_KeyboardEvent key) {
	if (key.keysym.scancode == SDL_SCANCODE_LSHIFT
			|| key.keysym.scancode == SDL_SCANCODE_RSHIFT) {
		this->keyDown((char) ASCII_SHIFT);
		return true;
	}
	if (key.keysym.scancode == SDL_SCANCODE_CAPSLOCK) {
		this->keyDown((char) ASCII_MAYUS);
		return true;
	}
//	if (key.keysym.sym >=)
	return false;
}

void GeneralEventController::keyUp() {
	list<KeyBoardEventController*>::iterator it;
	bool continuarEvento = true;
	for (it = this->keyControllers.begin();
			it != this->keyControllers.end() && continuarEvento; ++it) {
		continuarEvento = (*it)->keyReleased();
	}

}

void GeneralEventController::resize(int nuevoX, int nuevoY) {
	//ENTREGA3 USAR TL
	//	Resizer::Instance()->setearResizer(nuevoX, nuevoY);
//	Resizer::Instance()->resizearResizeables();
}


bool GeneralEventController::procesarEventos(SDL_Window * ventana) {
	int nuevaPosX, nuevaPosY;
//	int tamNuevoX, tamNuevoY;
//	SDL_DisplayMode current;
	SDL_Event evento;
	Logger log;
	int tamNuevoX, tamNuevoY;
	while (SDL_PollEvent(&evento)) {
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
		case SDL_MOUSEWHEEL:
			this->mouseWheelMoved(evento.wheel.y);
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
				this->keyDown((char) (evento.key.keysym.sym));
			break;
		case SDL_KEYUP:
			if (evento.key.keysym.scancode == SDL_SCANCODE_LSHIFT
					|| evento.key.keysym.scancode == SDL_SCANCODE_RSHIFT)
				this->keyUp();
			break;
		case SDL_USEREVENT:
			switch (evento.user.code) {
			case USREVENT_DRAW:
				if (this->drawController != NULL) {
					drawController->dibujar();
				}
				break;
			}
			break;
		case SDL_WINDOWEVENT: {
			switch (evento.window.event) {
//TODO IMPLEMENTAR RESIZE
//			case SDL_WINDOWEVENT_MAXIMIZED:
//				cout << "maximizada" << endl;
//				break;
			case SDL_WINDOWEVENT_RESIZED:
				//SDL_GetVideoInfo();
				SDL_GetWindowSize(ventana, &tamNuevoX, &tamNuevoY);
				if (tamNuevoY <= MIN_VENTANA_Y) tamNuevoY = MIN_VENTANA_Y;
				if (tamNuevoY >= MAX_VENTANA) tamNuevoY = MAX_VENTANA;
				tamNuevoX = tamNuevoY;
//				if (tamNuevoY <= MAX_VENTANA && tamNuevoY >= MIN_VENTANA_Y) {
					SDL_SetWindowSize(ventana, tamNuevoX, tamNuevoY);
					this->resize(tamNuevoX, tamNuevoY);
//				}
				break;
//			case SDL_WINDOWEVENT_MINIMIZED:
////				SDL_SetWindowSize(ventana, tamNuevoX, tamNuevoY);
////				this->resize(tamNuevoX, tamNuevoY);
//				cout << "minimizo"<< endl;
//				break;
//			case SDL_WINDOWEVENT_MAXIMIZED:
////				SDL_SetWindowSize(ventana, tamNuevoX, tamNuevoY);
////				this->resize(tamNuevoX, tamNuevoY);
//				cout << "maximizo"<< endl;
//				break;
			}

			break;
		}

		}
	}
	return false;
}

void GeneralEventController::setDrawController(DrawController* c) {
	this->drawController = c;
}

}
