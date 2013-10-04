/*
 * MotorView.cpp
 *
 *  Created on: 28/09/2013
 *      Author: jonathan
 */

#include "MotorView.h"
#include "../../controller/editor/SimpleEditorAnguloFijo.h"
MotorView::MotorView(int x, int y, int w, int h, SDL_Texture * textura,SimpleEditorAnguloFijo * editor): ObjetoView(x, y, w, h,textura, editor) {

}

MotorView::~MotorView() {
	// TODO Auto-generated destructor stub
}

void MotorView::dropTemplate() {
	controller->dropNuevaFigura(this);
}

EditorNivel* MotorView::getEditor() {
	SimpleEditorAnguloFijo * editor = (SimpleEditorAnguloFijo *)controller;
	editor->setFigura(this);
	return editor;
}
