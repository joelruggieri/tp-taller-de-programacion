/*
 * BalancinView.cpp
 *
 *  Created on: 05/10/2013
 *      Author: joel
 */

#include "BalancinView.h"
#include "../../controller/editor/SimpleEditorNivel.h"
#include "src/objeto/Balancin.h"

BalancinView::BalancinView(int x, int y, int w, int h, SDL_Texture * textura,SimpleEditorNivel * editor): ObjetoView(x, y, w, h,textura, editor) {

}

void BalancinView::dropTemplate(){
	this->controller->dropNuevaFigura(this);
}

EditorNivel * BalancinView::getEditor(){
	SimpleEditorNivel * editor = (SimpleEditorNivel*)controller;
	editor->setFigura(this);
	return editor;
}

BalancinView::~BalancinView() {
	// TODO Auto-generated destructor stub
}

