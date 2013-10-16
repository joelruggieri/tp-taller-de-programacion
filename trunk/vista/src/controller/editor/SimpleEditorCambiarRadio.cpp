/*
 * SimpleEditorCambiarRadio.cpp
 *
 *  Created on: 16/10/2013
 *      Author: ezequiel
 */

#include "SimpleEditorCambiarRadio.h"

SimpleEditorCambiarRadio::SimpleEditorCambiarRadio(ModeloController * controller , ZonaTablero * zona,FiguraFactory* factory, int yMaxDrag): SimpleEditorEstirar(controller, zona, factory, yMaxDrag) {
	// TODO Auto-generated constructor stub

}

SimpleEditorCambiarRadio::~SimpleEditorCambiarRadio() {
	// TODO Auto-generated destructor stub
}

void SimpleEditorCambiarRadio::mouseMotion(int x, int y) {
	super::mouseMotion(x,y);
	this->finalizado = true;
//	return true;
}

void SimpleEditorCambiarRadio::rightClickDown(int x, int y) {
	super::rightClickDown(x,y);
	this->actualizarRadio();
}


void SimpleEditorCambiarRadio::actualizarRadio() {
	Figura* figura = (this->editado->getModelo());
	figura->updateModelo();
//	this->editado->update()	// La transformacion de donde la saco??
}
