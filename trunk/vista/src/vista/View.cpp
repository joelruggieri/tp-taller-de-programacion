/*
 * View.cpp
 *
 *  Created on: 05/09/2013
 *      Author: jonathan
 */

#include "View.h"

View::View(int x, int y, int w, int h) {
	this->w = w;
	this->h = h;
	this->xc = x;
	this->yc = y;
	Resizer::Instance()->addResizeable(this);
}

View::~View() {
	// TODO Auto-generated destructor stub
}

int View::getH() const {
	return h;
}

int View::getW() const {
	return w;
}

int View::getX() const {
	return xc - w / 2;
}

int View::getY() const {
	return yc - h / 2;
}

void View::desplazarCentroA(int x, int y) {
	this->xc = x;
	this->yc = y;
}

int View::getXCentro() const {
	return xc;
}

int View::getYCentro() const {
	return yc;
}
