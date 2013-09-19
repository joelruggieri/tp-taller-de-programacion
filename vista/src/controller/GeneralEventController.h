/*
 * GeneralEventController.h
 *
 *  Created on: 07/09/2013
 *      Author: jonathan
 */

#ifndef GENERALEVENTCONTROLLER_H_
#define GENERALEVENTCONTROLLER_H_
#include "mouseEventController/MouseEventController.h"
#include "mouseEventController/MouseControllerPrioridades.h"
#include "keyboardEventController/KeyBoardEventController.h"
#include "CanvasController.h"

#include "SDL2/SDL.h"
#include <list>
using namespace std;


class GeneralEventController {
private:
	list<MouseControllerPrioridades *> mouseControllers;
	list<KeyBoardEventController *> keyControllers;
	CanvasController* canvasController; //De este siempre tiene que haber uno solo.

	void clickUp(int x, int y);
	void clickDown(int x, int y);
	void mouseMotion(int x, int y);
	void rightClickUp(int x, int y);
	void rightClickDown(int x, int y);
	void keyDown(char key);
	int botonAnterior;
	bool verificarCaracteresEspeciales(SDL_KeyboardEvent key);
	void keyUp ();
	void resize (int x , int y);
public:
	GeneralEventController();
	virtual ~GeneralEventController();
	void addMouseController(MouseEventController *, int prioridadClick, int prioridadMotion);
	void addKeyboardController(KeyBoardEventController* );
	void addCanvasController(CanvasController* canvasController);
	//TODO POR AHORA INDICA SI SALIR O NO DE LA APLICACION
	bool procesarEventos(SDL_Window *);

};

#endif /* GENERALEVENTCONTROLLER_H_ */

