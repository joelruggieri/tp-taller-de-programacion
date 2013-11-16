/*
 * CarritoView.cpp
 *
 *  Created on: 14/11/2013
 *      Author: joel
 */

#include "CarritoView.h"
#include "../../controller/editor/SimpleEditorNivel.h"
#include "../../controller/editor/SimpleEditorEstirar.h"

CarritoView::CarritoView(float x, float y,SimpleEditorNivel* editor): ObjetoView(x, y, editor, OBJ_SIMPLE_S_CARRITO) {
	// TODO Auto-generated constructor stub

}

CarritoView::~CarritoView() {
	// TODO Auto-generated destructor stub
}

void CarritoView::dropTemplate(){


	((SimpleEditorNivel* )this->controller)->dropNuevaFigura(this);
}

EditorNivel * CarritoView::getEditor(){
	SimpleEditorNivel * editor = (SimpleEditorNivel*)controller;
	editor->setFigura(this);
	return editor;
}
