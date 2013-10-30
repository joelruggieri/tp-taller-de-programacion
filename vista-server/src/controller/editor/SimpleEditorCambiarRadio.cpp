/*
 * SimpleEditorCambiarRadio.cpp
 *
 *  Created on: 16/10/2013
 *      Author: ezequiel
 */

#include "SimpleEditorCambiarRadio.h"
#include "src/objeto/Estirable.h"
SimpleEditorCambiarRadio::SimpleEditorCambiarRadio(ModeloController * controller, ZonaTablero * zona,
		FiguraFactory* factory, float) :
		SimpleEditorEstirar(controller, zona, factory, yMaxDrag) {
	// TODO Auto-generated constructor stub

}

SimpleEditorCambiarRadio::~SimpleEditorCambiarRadio() {
	// TODO Auto-generated destructor stub
}

void SimpleEditorCambiarRadio::mouseMotion(float x, float y) {
	super::mouseMotion(x, y);
	if(estirando){
		this->rightClickUp(x,y);
		this->finalizado = true;
	}
//	return true;
}

