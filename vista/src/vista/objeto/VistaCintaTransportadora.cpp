/*
 * VistaCintaTransportadora.cpp
 *
 *  Created on: 05/10/2013
 *      Author: javier
 */

#include "VistaCintaTransportadora.h"

#include "../../controller/DropController.h"
#include "../../controller/editor/EditorDeEstiramientoDeCinta.h"
#include "../../controller/editor/EditorNivel.h"
#include "../../controller/editor/SimpleEditorNivel.h"
#include "../figura/FiguraView.h"
#include "ObjetoView.h"

struct SDL_Texture;

VistaCintaTransportadora::VistaCintaTransportadora(int x, int y, int w, int h,
		SDL_Texture* textura, EditorDeEstiramientoDeCinta* editor) : ObjetoView(x,y,w,h,textura, editor){
}

VistaCintaTransportadora::~VistaCintaTransportadora() {
	// TODO Auto-generated destructor stub
}

void VistaCintaTransportadora::dropTemplate() {
	controller->dropNuevaFigura(this);
}


EditorNivel* VistaCintaTransportadora::getEditor() {
	EditorDeEstiramientoDeCinta * editor = (EditorDeEstiramientoDeCinta *)controller;
	editor->setFigura(this);
	return editor;
}
