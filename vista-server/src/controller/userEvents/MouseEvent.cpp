/*
 * MouseEvent.cpp
 *
 *  Created on: 04/11/2013
 *      Author: jonathan
 */

#include "MouseEvent.h"

MouseEvent::MouseEvent(float x, float y, bool i, bool a,bool c, bool s) {
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

