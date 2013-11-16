/*
 * PoleaView.cpp
 *
 *  Created on: 13/11/2013
 *      Author: Jonathan
 */

#include "PoleaView.h"
#include "../../controller/editor/SimpleEditorAnguloFijo.h"

PoleaView::PoleaView(float x, float y,SimpleEditorAnguloFijo * editor): ObjetoView(x, y, editor, OBJ_SIMPLE_S_POLEA) {

}

PoleaView::~PoleaView() {
	// TODO Auto-generated destructor stub
}

void PoleaView::dropTemplate() {
	((SimpleEditorAnguloFijo * )this->controller)->dropNuevaFigura(this);
}

EditorNivel* PoleaView::getEditor() {
	SimpleEditorAnguloFijo * editor = (SimpleEditorAnguloFijo *)controller;
	editor->setFigura(this);
	return editor;
}

