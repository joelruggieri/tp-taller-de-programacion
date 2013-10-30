/*
 * MouseControllerPrioridades.h
 *
 *  Created on: 07/09/2013
 *      Author: jonathan
 */

#ifndef MOUSECONTROLLERPRIORIDADES_H_
#define MOUSECONTROLLERPRIORIDADES_H_
#include "MouseEventController.h"

class MouseControllerPrioridades {
private:
	int prioridadClickUpDown,prioridadMotion;
	MouseEventController * eventController;
public:
	MouseControllerPrioridades(MouseEventController*, int prioridadClick, int prioridadMotion);
	~MouseControllerPrioridades();
	int getPrioridadClickUpDown() const;
	int getPrioridadMotion() const;
	MouseEventController* getEventController();
};

#endif /* MOUSECONTROLLERPRIORIDADES_H_ */
