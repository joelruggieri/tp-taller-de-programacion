/*
 * BombaView.cpp
 *
 *  Created on: 17/11/2013
 *      Author: ezequiel
 */

#include "BombaView.h"
#include "../../controller/editor/SimpleEditorAnguloFijo.h"
BombaView::BombaView(float x, float y , SimpleEditorAnguloFijo* editor): ObjetoView(x, y, editor, OBJ_SIMPLE_S_BOMBA){

}

BombaView::~BombaView() {
	// TODO Auto-generated destructor stub
}

void BombaView::dropTemplate() {
	((SimpleEditorAnguloFijo * )this->controller)->dropNuevaFigura(this);
}

EditorNivel* BombaView::getEditor() {
	SimpleEditorAnguloFijo * editor = (SimpleEditorAnguloFijo *)controller;
	editor->setFigura(this);
	return editor;
}
