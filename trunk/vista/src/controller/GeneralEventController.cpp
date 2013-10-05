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
#include <iostream>
#include <list>
#include <string>
#define  MIN_VENTANA_Y 400
#define MIN_VENTANA_X 400
#define MAX_VENTANA 900
#include "../controller/UserEventCreator.h"
#include "CanvasController.h"
#include "keyboardEventController/KeyBoardEventController.h"
#include "mouseEventController/MouseControllerPrioridades.h"
#include "mouseEventController/MouseEventController.h"
#include "mouseEventController/MouseEventPriorComparator.h"
#include "Resizer.h"
#include "src/Logger.h"

struct SDL_Window;

#define ASCII_SHIFT 15
#define ASCII_MAYUS 16
GeneralEventController::GeneralEventController() {
	this->canvasController = 0;
	this->guardarController = NULL;
	this->flujoController = NULL;
	this->drawController = NULL;
	tamAnteriorX = 600;
	tamAnteriorY = 600;

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

void GeneralEventController::setCanvasController(
		CanvasController* canvasController) {
	this->canvasController = canvasController;
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
	Resizer::Instance()->setearResizer(nuevoX, nuevoY);
	Resizer::Instance()->resizearResizeables();
}

void GeneralEventController::setGuardarController(
		PersistenciaEventController* controller) {
	this->guardarController = controller;
}

bool GeneralEventController::procesarEventos(SDL_Window * ventana) {
	int nuevaPosX, nuevaPosY;
//	int tamNuevoX, tamNuevoY;
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
			case USREVENT_CHANGEBACKGROUND:
				if (this->canvasController != NULL
						&& (flujoController == NULL
								|| !flujoController->corriendo())) {
					this->canvasController->atenderEvento(evento);
				}
				break;
			case USREVENT_SAVEGAME:
				if (this->guardarController != NULL
						&& (flujoController == NULL
								|| !flujoController->corriendo())) {
					this->guardarController->persistir();
				}
				break;
			case USREVENT_STOP:
				if (this->flujoController != NULL) {
					log.info("Finaliza Juego");
					flujoController->stop();
				}
				break;
			case USREVENT_START:
				if (this->flujoController != NULL) {
					log.info("Inicia Juego");
					flujoController->start();
				}
				break;
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
			case SDL_WINDOWEVENT_RESIZED:
				cout << "resize" << endl;
				SDL_GetWindowSize(ventana, &tamNuevoX, &tamNuevoY);

				if (tamNuevoX != this->tamAnteriorX
						&& tamNuevoY == this->tamAnteriorY)
					tamNuevoY = tamNuevoX;
				else if (tamNuevoX == this->tamAnteriorX
						&& tamNuevoY != this->tamAnteriorY)
					tamNuevoX = tamNuevoY;
				else
					tamNuevoY = tamNuevoX;
				if ((tamNuevoX >= MAX_VENTANA) || (tamNuevoY >= MAX_VENTANA)) {
					tamNuevoX = MAX_VENTANA;
					tamNuevoY = MAX_VENTANA;
				}

				if (tamNuevoX <= MIN_VENTANA_X) {
					tamNuevoX = MIN_VENTANA_X;
					tamNuevoY = MIN_VENTANA_Y;
				}
				if (tamNuevoY <= MIN_VENTANA_Y) {
					tamNuevoY = MIN_VENTANA_Y;
					tamNuevoX = MIN_VENTANA_Y;
				}
				this->tamAnteriorX = tamNuevoX;
				this->tamAnteriorY = tamNuevoY;
//        			tamNuevoX = tamNuevoY;
				cout << tamNuevoX << " " << tamNuevoY << " " << tamAnteriorX
						<< " " << tamAnteriorY << endl;
				if ((tamNuevoX == tamNuevoY) && tamNuevoY <= MAX_VENTANA) {
					cout << "se metio aca" << endl;
					SDL_SetWindowSize(ventana, tamNuevoX, tamNuevoY);
					this->resize(tamNuevoX, tamNuevoY);
				}
//        			if (tamNuevoY >= MAX_VENTANA){
//        				cout << "paso de largo" << endl ;
//        				SDL_SetWindowSize(ventana,MAX_VENTANA,MAX_VENTANA);
//        				 this->resize(MAX_VENTANA, MAX_VENTANA);
//        			}
				break;
//

			}

			break;
		}

		}
	}
	return false;
}

void GeneralEventController::setFlujoController(FlujoDeJuegoController* c) {
	this->flujoController = c;
}

void GeneralEventController::setDrawController(DrawController* c) {
	this->drawController = c;
}
