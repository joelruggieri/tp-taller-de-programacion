/*
 * SimpleEditorAnguloFijo.cpp
 *
 *  Created on: 03/10/2013
 *      Author: jonathan
 */

#include "SimpleEditorAnguloFijo.h"
#include "../../vista/CargadorDeTextures.h"
#include "../../vista/ViewConIcono.h"
SimpleEditorAnguloFijo::SimpleEditorAnguloFijo(ModeloController * c, ZonaTablero *t,FiguraFactory* f, int yMaxDrag):SimpleEditorNivel(c,t,f,yMaxDrag) {
	// TODO Auto-generated constructor stub

}

SimpleEditorAnguloFijo::~SimpleEditorAnguloFijo() {
	// TODO Auto-generated destructor stub
}

void SimpleEditorAnguloFijo::rightClickUp(int x, int y) {
	if (rotando) {
		tablero->agregarFigura(this->editado);
		rotando = false;
		delete visor;
		finalizado = true;
	}
}

void SimpleEditorAnguloFijo::rightClickDown(int x, int y) {
	const Uint8 *keyboardState = SDL_GetKeyboardState(NULL);
	if (keyboardState[SDL_SCANCODE_LSHIFT]) {
		this->tablero->removerFigura(this->editado);
		this->modeloController->removerFigura(this->editado->getModelo());
		super::cleanAndDelete();
		return;
	}
	if (!rotando && !finalizado && !dragueando) {
		if (editado->getModelo() != NULL) {
				this->tablero->removerFigura(this->editado);
				rotando = true;
				CargadorDeTextures* l = CargadorDeTextures::Instance();
				this->visor = new ViewConIcono(editado, l->cargarTexture("resource/rotacion.png"), 2);
			}
		}

}

void SimpleEditorAnguloFijo::mouseMotion(int x, int y) {
	if(dragueando){
		super::mouseMotion(x,y) ;
	}
}
