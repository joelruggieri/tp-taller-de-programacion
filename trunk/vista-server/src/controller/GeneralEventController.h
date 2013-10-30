/*
 * GeneralEventController.h
 *
 *  Created on: 07/09/2013
 *      Author: jonathan
 */

#ifndef GENERALEVENTCONTROLLER_H_
#define GENERALEVENTCONTROLLER_H_


#include <list>
#include <SDL2/SDL.h>
#include "keyboardEventController/KeyBoardEventController.h"
#include "mouseEventController/MouseEventController.h"
#include "FlujoDeJuegoController.h"
#include "DrawController.h"
class MouseControllerPrioridades;
struct SDL_KeyboardEvent;

using namespace std;



//ENTREGA3 REFACTOR HAY QUE HACER QUE TENGA LOS 4 JUEGOS EVENT CONTROLLERS Y YA OLVIDARSE DE LA GENERALIDAD YA QUE SACAMOS TODA BARRA DE CAMBIAR FONDO Y DEMAS
//SE PUEDE PROGRAMAR OTRO GENERALEVENTCONTROLLER Y NO TOCAR ESTE.
class GeneralEventController {
private:
	list<MouseControllerPrioridades *> mouseControllers;
	list<KeyBoardEventController *> keyControllers;
	FlujoDeJuegoController * flujoController;
	DrawController * drawController;
	float tamAnteriorX, tamAnteriorY;
	void clickUp(float x, float y);
	void clickDown(float x, float y);
	void mouseMotion(float x, float y);
	void mouseWheelMoved(float amountScrolledY);
	void rightClickUp(float x, float y);
	void rightClickDown(float x, float y);
	void keyDown(char key);
	bool verificarCaracteresEspeciales(SDL_KeyboardEvent key);
	void keyUp ();
	void resize (float nuevoX, float nuevoY);
public:
	GeneralEventController();
	virtual ~GeneralEventController();
	void addMouseController(MouseEventController *, int prioridadClick, int prioridadMotion);
	void addKeyboardController(KeyBoardEventController* );
	bool procesarEventos(SDL_Window *);
	void setFlujoController(FlujoDeJuegoController*);
	void setDrawController(DrawController *);
};

#endif /* GENERALEVENTCONTROLLER_H_ */

