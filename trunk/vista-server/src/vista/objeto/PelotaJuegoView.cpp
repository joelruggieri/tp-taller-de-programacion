/*
 * PelotaJuegoView.cpp
 *
 *  Created on: 06/10/2013
 *      Author: ezequiel
 */

#include "PelotaJuegoView.h"
#include "../../controller/editor/SimpleEditorAnguloFijo.h"
PelotaJuegoView::PelotaJuegoView(float x, float y,SimpleEditorAnguloFijo * editor): ObjetoView(x, y, editor) {

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
