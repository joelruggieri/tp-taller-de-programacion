/*
 * BalancinView.cpp
 *
 *  Created on: 05/10/2013
 *      Author: joel
 */

#include "BalancinView.h"
#include "../../controller/editor/SimpleEditorAnguloFijo.h"
#include "src/objeto/Balancin.h"

BalancinView::BalancinView(float x, float y,SimpleEditorAnguloFijo * editor): ObjetoView(x, y, editor, OBJ_SIMPLE_S_BALANCIN) {

}

void BalancinView::dropTemplate(){


	((SimpleEditorAnguloFijo * )this->controller)->dropNuevaFigura(this);
}

EditorNivel * BalancinView::getEditor(){
	SimpleEditorNivel * editor = (SimpleEditorNivel*)controller;
	editor->setFigura(this);
	return editor;
}

BalancinView::~BalancinView() {
	// TODO Auto-generated destructor stub
}

