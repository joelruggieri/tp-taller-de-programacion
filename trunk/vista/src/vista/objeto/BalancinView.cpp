/*
 * BalancinView.cpp
 *
 *  Created on: 05/10/2013
 *      Author: joel
 */

#include "BalancinView.h"
#include "../../controller/editor/SimpleEditorAnguloFijo.h"
#include "src/objeto/Balancin.h"

BalancinView::BalancinView(int x, int y, int w, int h, SDL_Texture * textura,SimpleEditorAnguloFijo * editor): ObjetoView(x, y, w, h,textura, editor) {

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

