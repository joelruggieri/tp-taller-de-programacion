/*
 * GloboHelioView.cpp
 *
 *  Created on: 05/10/2013
 *      Author: ezequiel
 */

#include "GloboHelioView.h"
#include "../../controller/editor/SimpleEditorAnguloFijo.h"
GloboHelioView::GloboHelioView(int x, int y, int w, int h, SDL_Texture * textura, SimpleEditorAnguloFijo * editor): ObjetoView(x, y, w, h,textura, editor) {

}

GloboHelioView::~GloboHelioView() {
	// TODO Auto-generated destructor stub
}

void GloboHelioView::dropTemplate() {
	((SimpleEditorAnguloFijo * )this->controller)->dropNuevaFigura(this);
}

EditorNivel* GloboHelioView::getEditor() {
	SimpleEditorAnguloFijo * editor = (SimpleEditorAnguloFijo *)controller;
	editor->setFigura(this);
	return editor;
}
