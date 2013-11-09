/*
 * SimpleEditorOrientacionCambiable.cpp
 *
 *  Created on: 10/10/2013
 *      Author: ezequiel
 */

#include "SimpleEditorOrientacionCambiable.h"

SimpleEditorOrientacionCambiable::SimpleEditorOrientacionCambiable(ModeloController * c, ZonaTablero *t,FiguraFactory* f, float yMaxDrag) : SimpleEditorNivel(c, t, f, yMaxDrag) {

}

SimpleEditorOrientacionCambiable::~SimpleEditorOrientacionCambiable() {
	// TODO Auto-generated destructor stub
}

void SimpleEditorOrientacionCambiable::mouseMotion(float x, float y) {
	if (dragueando)
			super::mouseMotion(x, y);

}

void SimpleEditorOrientacionCambiable::rightClickDown(float x, float y) {

	this->editado->getModelo()->modificarSentido();
	super::rightClickDown(x, y);

}

void SimpleEditorOrientacionCambiable::dropNuevaFigura(MotorView* view) {
	dropear(view, this->figurasFactory->crearMotor(view->getXCentro(), view->getYCentro(),this->numeroJugadorDuenio));
}

EditorNivel* SimpleEditorOrientacionCambiable::clone() {
	return new SimpleEditorOrientacionCambiable(this->modeloController,tablero, figurasFactory,yMaxDrag);
}
