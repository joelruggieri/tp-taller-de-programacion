/*
 * ControlRemotoView.cpp
 *
 *  Created on: 17/11/2013
 *      Author: ezequiel
 */

#include "ControlRemotoView.h"
#include "../../controller/editor/SimpleEditorAnguloFijo.h"
#include "../../controller/editor/SimpleEditorOrientacionCambiable.h"
#include "../../ConstantesVista.h"
ControlRemotoView::ControlRemotoView(float x, float y, SimpleEditorAnguloFijo* editor) : ObjetoView(x,y,editor, OBJ_SIMPLE_S_CONTROL) {
	// TODO Auto-generated constructor stub

}

ControlRemotoView::~ControlRemotoView() {
	// TODO Auto-generated destructor stub
}

void ControlRemotoView::dropTemplate() {
	((SimpleEditorAnguloFijo * )this->controller)->dropNuevaFigura(this);
}

EditorNivel* ControlRemotoView::getEditor() {
	SimpleEditorAnguloFijo * editor = (SimpleEditorAnguloFijo *)controller;
	editor->setFigura(this);
	return editor;
}

int ControlRemotoView::getLayer() {
	return LAYER_DEFAULT;
}
