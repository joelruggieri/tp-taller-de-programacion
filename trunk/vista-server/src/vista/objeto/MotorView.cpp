/*
 * MotorView.cpp
 *
 *  Created on: 28/09/2013
 *      Author: jonathan
 */

#include "MotorView.h"
#include "../../controller/editor/SimpleEditorAnguloFijo.h"
#include "../../controller/editor/SimpleEditorOrientacionCambiable.h"
#include "../../ConstantesVista.h"

MotorView::MotorView(float x, float y,SimpleEditorOrientacionCambiable * editor): ObjetoView(x, y, editor) {

}

MotorView::~MotorView() {
	// TODO Auto-generated destructor stub
}

void MotorView::dropTemplate() {
	((SimpleEditorOrientacionCambiable * )this->controller)->dropNuevaFigura(this);
}

EditorNivel* MotorView::getEditor() {
	SimpleEditorOrientacionCambiable * editor = (SimpleEditorOrientacionCambiable *)controller;
	editor->setFigura(this);
	return editor;
}

int MotorView::getLayer() {
	return LAYER_ENGRANAJES;
}
