/*
 * PelotaJuegoView.cpp
 *
 *  Created on: 06/10/2013
 *      Author: ezequiel
 */

#include "PelotaJuegoView.h"
#include "../../controller/editor/SimpleEditorAnguloFijo.h"
PelotaJuegoView::PelotaJuegoView(int x, int y, int w, int h, SDL_Texture * textura, SimpleEditorAnguloFijo * editor): ObjetoView(x, y, w, h,textura, editor) {

}

PelotaJuegoView::~PelotaJuegoView() {
	// TODO Auto-generated destructor stub
}

void PelotaJuegoView::dropTemplate() {
	((SimpleEditorAnguloFijo * )this->controller)->dropNuevaFigura(this);
}

EditorNivel* PelotaJuegoView::getEditor() {
	SimpleEditorAnguloFijo * editor = (SimpleEditorAnguloFijo *)controller;
	editor->setFigura(this);
	return editor;
}
