/*
 * SimpleEditorCambiarRadio.cpp
 *
 *  Created on: 16/10/2013
 *      Author: ezequiel
 */

#include "SimpleEditorCambiarRadio.h"
#include "src/objeto/Estirable.h"
SimpleEditorCambiarRadio::SimpleEditorCambiarRadio(ModeloController * controller, ZonaTablero * zona,
		FiguraFactory* factory, float yMaxDrag) :
		SimpleEditorEstirar(controller, zona, factory, yMaxDrag) {

}

SimpleEditorCambiarRadio::~SimpleEditorCambiarRadio() {
}

void SimpleEditorCambiarRadio::mouseMotion(float x, float y) {
	super::mouseMotion(x, y);
	if(estirando){
		this->rightClickUp(x,y);
		this->finalizado = true;
	}
//	return true;
}


EditorNivel* SimpleEditorCambiarRadio::clone() {
	return new SimpleEditorCambiarRadio(modeloController,tablero,figurasFactory,yMaxDrag);
}
