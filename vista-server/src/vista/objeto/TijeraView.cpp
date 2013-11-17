/*
 * TijeraView.cpp
 *
 *  Created on: 17/11/2013
 *      Author: joel
 */

#include "TijeraView.h"
#include "../../controller/editor/SimpleEditorAnguloFijo.h"
#include "src/objeto/Tijera.h"

TijeraView::TijeraView(float x, float y, SimpleEditorAnguloFijo* editor): ObjetoView(x,y,editor,OBJ_SIMPLE_S_TIJERA) {


}

TijeraView::~TijeraView() {
	// TODO Auto-generated destructor stub
}

void TijeraView::dropTemplate(){


	((SimpleEditorAnguloFijo* )this->controller)->dropNuevaFigura(this);
}

EditorNivel * TijeraView::getEditor(){
	SimpleEditorAnguloFijo* editor = (SimpleEditorAnguloFijo*)controller;
	editor->setFigura(this);
	return editor;
}

