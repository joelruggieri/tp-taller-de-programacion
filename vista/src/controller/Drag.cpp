
/*
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

int Drag::desplazarCentroA(int &x, int &y) {
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
		Transformacion tl = Resizer::Instance()->getTransformacionToModelo();
		tl.setVector(x,y);
		float xf,yf;
		tl.getResultado(xf,yf);
		view->getModelo()->setPosicion(xf,yf);
	}



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
