/*
 * Drag.cpp
 *
 *  Created on: 19/09/2013
 *      Author: jonathan
 */

#include "Drag.h"

Drag::~Drag() {
	// TODO Auto-generated destructor stub
}

Drag::Drag(FiguraView* view, int yMax) {
	this->view = view;
	xStart = view->getXCentro();
	yStart = view->getYCentro();
	this->yMax = yMax;
}

void Drag::drop() {
	view->drop();
}

FiguraView* Drag::getView() {
	return view;
}

int Drag::desplazarCentroA(int x, int y) {
	if(y> yMax){
		y = yMax;
	}
	view->desplazarCentroA(x,y);
	return y;
}

int Drag::getXCentro() const {
	return view->getXCentro();
}

void Drag::rollBack() {
	view->desplazarCentroA(xStart,yStart);
}

bool Drag::isRolledBack() const {
	return this->xStart == view->getXCentro() && this->yStart == this->getYCentro();

}

int Drag::getYCentro() const {
	return view->getYCentro();
}
