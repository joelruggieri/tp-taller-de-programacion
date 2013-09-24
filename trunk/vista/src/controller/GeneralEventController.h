/*
 * GeneralEventController.h
 *
 *  Created on: 07/09/2013
 *      Author: jonathan
 */

#ifndef GENERALEVENTCONTROLLER_H_
#define GENERALEVENTCONTROLLER_H_


#include <list>

#include "keyboardEventController/KeyBoardEventController.h"
#include "mouseEventController/MouseEventController.h"
#include "CanvasController.h"
#include "PersistenciaEventController.h"
class MouseControllerPrioridades;
struct SDL_KeyboardEvent;

using namespace std;


class GeneralEventController {
private:
	list<MouseControllerPrioridades *> mouseControllers;
	list<KeyBoardEventController *> keyControllers;
	CanvasController* canvasController; //De este siempre tiene que haber uno solo.
	PersistenciaEventController * guardarController;
	void clickUp(int x, int y);
	void clickDown(int x, int y);
	void mouseMotion(int x, int y);
	void mouseWheelMoved(int amountScrolledY);
	void rightClickUp(int x, int y);
	void rightClickDown(int x, int y);
	void keyDown(char key);
	bool verificarCaracteresEspeciales(SDL_KeyboardEvent key);
	void keyUp ();
	void resize (int nuevoX, int nuevoY);
public:
	GeneralEventController();
	virtual ~GeneralEventController();
	void addMouseController(MouseEventController *, int prioridadClick, int prioridadMotion);
	void addKeyboardController(KeyBoardEventController* );
	void setCanvasController(CanvasController* canvasController);
	void setGuardarController(PersistenciaEventController * controller);
	bool procesarEventos(SDL_Window *);

};

#endif /* GENERALEVENTCONTROLLER_H_ */

