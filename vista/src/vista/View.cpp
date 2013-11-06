/*
 * View.cpp
 *
 *  Created on: 05/09/2013
 *      Author: jonathan
 */

#include "View.h"
namespace CLIENTE {
View::View(int x, int y, int w, int h) {
	this->w = w;
	this->h = h;
	this->xc = x;
	this->yc = y;
	Resizer::Instance()->addResizeable(this);
}

View::~View() {
	Resizer::Instance()->quitarResizeable(this);
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

void View::resizear() {
	this->setW(Resizer::Instance()->resizearDistanciaX(this->getW()));
	this->setXc((Resizer::Instance()->resizearDistanciaX(this->getXCentro())));
	this->setH(Resizer::Instance()->resizearDistanciaY(this->getH()));
	this->setYc((Resizer::Instance()->resizearDistanciaY(this->getYCentro())));

}
}
