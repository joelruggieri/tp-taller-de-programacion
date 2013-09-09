/*
 * View.cpp
 *
 *  Created on: 05/09/2013
 *      Author: jonathan
 */

#include "View.h"

View::View(int x, int y, int w, int h ) {
	//TODO RECIBE EN EL CENTRO, PERO HAY QUE CORRER EL X Y AL MARGEN SUPERIOR IZQ.
	this->x= x - w/2;
	this->y= y - h/2;
	this->w= w;
	this->h= h;
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
	return x;
}

int View::getY() const {
	return y;
}

