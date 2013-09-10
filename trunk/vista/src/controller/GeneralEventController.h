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
#include "SDL2/SDL.h"
#include <list>
using namespace std;


class GeneralEventController {
private:
	list<MouseControllerPrioridades *> mouseControllers;
public:
	GeneralEventController();
	virtual ~GeneralEventController();
	void addMouseController(MouseEventController *, int prioridadClick, int prioridadMotion);
	void clickUp(int x, int y);
	void clickDown(int x, int y);
	void mouseMotion(int x, int y);
	//TODO POR AHORA INDICA SI SALIR O NO DE LA APLICACION
	bool procesarEventos();
};

#endif /* GENERALEVENTCONTROLLER_H_ */

