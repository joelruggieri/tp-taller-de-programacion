/*
 * View.cpp
 *
 *  Created on: 05/09/2013
 *      Author: jonathan
 */

#include "View.h"

View::View(float x, float y): Dibujable() {
	this->xc = x;
	this->yc = y;
}

View::~View() {
}


void View::desplazarCentroA(float x, float y) {
	this->xc = x;
	this->yc = y;
}

float View::getXCentro() {
	return xc;
}

float View::getYCentro() {
	return yc;
}
