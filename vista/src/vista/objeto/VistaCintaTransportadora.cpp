/*
 * VistaCintaTransportadora.cpp
 *
 *  Created on: 05/10/2013
 *      Author: javier
 */

#include "VistaCintaTransportadora.h"
#include "../../controller/DropController.h"
#include "../../controller/editor/SimpleEditorNivel.h"

VistaCintaTransportadora::VistaCintaTransportadora(int x, int y, int w, int h,
		SDL_Texture* textura, SimpleEditorNivel* editor) : ObjetoView(x,y,w,h,textura, editor){
}

VistaCintaTransportadora::~VistaCintaTransportadora() {
	// TODO Auto-generated destructor stub
}

void VistaCintaTransportadora::dropTemplate() {
	controller->dropNuevaFigura(this);
}


EditorNivel* VistaCintaTransportadora::getEditor() {
	SimpleEditorNivel * editor = (SimpleEditorNivel *)controller;
	editor->setFigura(this);
	return editor;
}
