/*
 * MouseEvent.cpp
 *
 *  Created on: 04/11/2013
 *      Author: jonathan
 */

#include "MouseEvent.h"

MouseEvent::MouseEvent(float x, float y, bool i, bool a, bool c, bool s) {
	this->x = x;
	this->y = y;
	this->izquierdo = i;
	this->apretado = a;
	this->ctrl = c;
	this->shift = s;
}

bool MouseEvent::isApretado() const {
	return apretado;
}

bool MouseEvent::isIzquierdo() const {
	return izquierdo;
}

float MouseEvent::getX() const {
	return x;
}

bool MouseEvent::isCtrl() const {
	return ctrl;
}

bool MouseEvent::isShift() const {
	return shift;
}

float MouseEvent::getY() const {
	return y;
}

MouseEvent::~MouseEvent() {
	// TODO Auto-generated destructor stub
}

void MouseEvent::mouseMotion(JuegoEventsController* jugador) {
	jugador->setControl(this->ctrl);
	jugador->setShift(this->shift);
	jugador->mouseMotion(this->x, this->y);
}

void MouseEvent::mouseClick(JuegoEventsController* jugador) {
	jugador->setControl(this->ctrl);
	jugador->setShift(this->shift);
	/// chequeo de bools ///
	if ((this->apretado) && (this->izquierdo)) {
		jugador->clickDown(this->x, this->y);
	} else if ((this->apretado) && !(this->izquierdo)) {
		jugador->rightClickDown(this->x, this->y);
	} else if ((!this->apretado) && (this->izquierdo)) {
		jugador->clickUp(this->x, this->y);
	} else if ((!this->apretado) && !(this->izquierdo)) {
		jugador->rightClickUp(this->x, this->y);
	}
}
