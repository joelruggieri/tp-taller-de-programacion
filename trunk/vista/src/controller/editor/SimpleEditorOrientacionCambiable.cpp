/*
 * SimpleEditorOrientacionCambiable.cpp
 *
 *  Created on: 10/10/2013
 *      Author: ezequiel
 */

#include "SimpleEditorOrientacionCambiable.h"

SimpleEditorOrientacionCambiable::SimpleEditorOrientacionCambiable(ModeloController * c, ZonaTablero *t,FiguraFactory* f, int yMaxDrag) : SimpleEditorNivel(c, t, f, yMaxDrag) {

}

SimpleEditorOrientacionCambiable::~SimpleEditorOrientacionCambiable() {
	// TODO Auto-generated destructor stub
}

void SimpleEditorOrientacionCambiable::mouseMotion(int x, int y) {
	if (dragueando)
			super::mouseMotion(x, y);

}

void SimpleEditorOrientacionCambiable::rightClickDown(int x, int y) {

	this->editado->getModelo()->modificarSentido();
	super::rightClickDown(x, y);

}

void SimpleEditorOrientacionCambiable::dropNuevaFigura(MotorView* view) {
	Resizer* r = Resizer::Instance();
	float x;
	float y;
	r->adaptarPosicionPixel(view->getXCentro(), view->getYCentro(), x, y);
	dropear(view, this->figurasFactory->crearMotor(x, 100 - y));
}
