/*
 * ClavoView.cpp
 *
 *  Created on: 14/11/2013
 *      Author: ezequiel
 */

#include "ClavoView.h"
#include "../../controller/editor/SimpleEditorAnguloFijo.h"
#include "src/objeto/Clavo.h"
ClavoView::ClavoView(float x, float y,SimpleEditorAnguloFijo * editor): ObjetoView(x, y, editor, OBJ_SIMPLE_S_CLAVO) {
	// TODO Auto-generated constructor stub

}

ClavoView::~ClavoView() {
	// TODO Auto-generated destructor stub
}

void ClavoView::dropTemplate() {
	((SimpleEditorAnguloFijo * )this->controller)->dropNuevaFigura(this);
}

EditorNivel* ClavoView::getEditor() {
	SimpleEditorNivel * editor = (SimpleEditorNivel*)controller;
	editor->setFigura(this);
	return editor;
}
