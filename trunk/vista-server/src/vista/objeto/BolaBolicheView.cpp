/*
 * BolaBolicheView.cpp
 *
 *  Created on: 06/10/2013
 *      Author: ezequiel
 */

#include "BolaBolicheView.h"
#include "../../controller/editor/SimpleEditorAnguloFijo.h"
BolaBolicheView::BolaBolicheView(float x, float y,SimpleEditorAnguloFijo * editor): ObjetoView(x, y, editor, OBJ_SIMPLE_S_BOLABOLICHE) {
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
