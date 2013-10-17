/*
 * MotorView.cpp
 *
 *  Created on: 28/09/2013
 *      Author: jonathan
 */

#include "MotorView.h"
#include "../../controller/editor/SimpleEditorAnguloFijo.h"
#include "../../controller/editor/SimpleEditorOrientacionCambiable.h"
//MotorView::MotorView(int x, int y, int w, int h, SDL_Texture * textura,SimpleEditorAnguloFijo * editor): ObjetoView(x, y, w, h,textura, editor) {
//
//}

MotorView::MotorView(int x, int y, int w, int h, SDL_Texture * textura,SimpleEditorOrientacionCambiable * editor): ObjetoView(x, y, w, h,textura, editor) {

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
