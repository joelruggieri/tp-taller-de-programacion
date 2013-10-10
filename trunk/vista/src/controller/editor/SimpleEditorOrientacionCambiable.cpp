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
