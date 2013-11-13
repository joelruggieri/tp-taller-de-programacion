/*
 * GanchoView.cpp
 *
 *  Created on: 13/11/2013
 *      Author: joel
 */

#include "GanchoView.h"
#include "../../controller/editor/SimpleEditorAnguloFijo.h"

GanchoView::GanchoView(float x, float y,SimpleEditorAnguloFijo * editor): ObjetoView(x, y, editor, OBJ_SIMPLE_S_GANCHO) {

}

GanchoView::~GanchoView() {
	// TODO Auto-generated destructor stub
}

void GanchoView::dropTemplate() {
	((SimpleEditorAnguloFijo * )this->controller)->dropNuevaFigura(this);
}

EditorNivel* GanchoView::getEditor() {
	SimpleEditorAnguloFijo * editor = (SimpleEditorAnguloFijo *)controller;
	editor->setFigura(this);
	return editor;
}

