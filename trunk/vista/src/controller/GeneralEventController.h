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

#include <list>
using namespace std;


class GeneralEventController {
private:

	list<MouseControllerPrioridades *> mouseControllers;

public:
	GeneralEventController();
	virtual ~GeneralEventController();
	void addMouseController(MouseEventController *, int prioridadClick, int prioridadMotion);
	void clickUp(float x, float y);
	void clickDown(float x, float y);
	void mouseMotion(float x, float y);
};

#endif /* GENERALEVENTCONTROLLER_H_ */

