
/*
 *
 *  Created on: 19/09/2013
 *      Author: jonathan
 */
#include "Drag.h"

Drag::~Drag() {
	// TODO Auto-generated destructor stub
}

Drag::Drag(FiguraView* view, float yMax) {
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

float Drag::desplazarCentroA(float &x, float &y) {
	if(y> yMax){
		y = yMax;
	}
	if(y < 0){
		y = 0;
	}
	if(x < 0){
		x = 0;
	}
	view->desplazarCentroA(x,y);
	if(view->getModelo()){
		view->getModelo()->setPosicion(x,y);
	}



	return y;
}

float Drag::getXCentro() const {
	return view->getXCentro();
}

void Drag::rollBack() {
	view->desplazarCentroA(xStart,yStart);
}

bool Drag::isRolledBack() const {
	return this->xStart == view->getXCentro() && this->yStart == this->getYCentro();

}

float Drag::getYCentro() const {
	return view->getYCentro();
}
