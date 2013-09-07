/*
 * MouseControllerPrioridades.cpp
 *
 *  Created on: 07/09/2013
 *      Author: jonathan
 */

#include "MouseControllerPrioridades.h"


MouseControllerPrioridades::~MouseControllerPrioridades() {
	delete this->eventController;
}

int MouseControllerPrioridades::getPrioridadClickUpDown() const {
	return prioridadClickUpDown;
}

MouseControllerPrioridades::MouseControllerPrioridades(MouseEventController* controller,
		int prioridadClick, int prioridadMotion) {
	this->eventController = controller;
	this->prioridadClickUpDown = prioridadClick;
	this->prioridadMotion = prioridadMotion;
}

MouseEventController* MouseControllerPrioridades::getEventController() {
	return eventController;
}

int MouseControllerPrioridades::getPrioridadMotion() const {
	return prioridadMotion;
}
