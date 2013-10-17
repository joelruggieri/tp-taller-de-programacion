/*
 * BolaBolicheView.cpp
 *
 *  Created on: 06/10/2013
 *      Author: ezequiel
 */

#include "BolaBolicheView.h"
#include "../../controller/editor/SimpleEditorAnguloFijo.h"
BolaBolicheView::BolaBolicheView(int x, int y, int w, int h, SDL_Texture * textura, SimpleEditorAnguloFijo * editor): ObjetoView(x, y, w, h,textura, editor) {
	// TODO Auto-generated constructor stub

}

BolaBolicheView::~BolaBolicheView() {
	// TODO Auto-generated destructor stub
}

void BolaBolicheView::dropTemplate() {
	((SimpleEditorAnguloFijo * )this->controller)->dropNuevaFigura(this);
}

EditorNivel* BolaBolicheView::getEditor() {
	SimpleEditorAnguloFijo * editor = (SimpleEditorAnguloFijo *)controller;
	editor->setFigura(this);
	return editor;
}
