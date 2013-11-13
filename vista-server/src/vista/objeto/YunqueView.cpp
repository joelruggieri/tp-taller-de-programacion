/*
 * YunqueView.cpp
 *
 *  Created on: 13/11/2013
 *      Author: ezequiel
 */

#include "YunqueView.h"
#include "../../controller/editor/SimpleEditorAnguloFijo.h"
YunqueView::YunqueView(float x, float y,SimpleEditorAnguloFijo * editor): ObjetoView(x, y, editor, OBJ_SIMPLE_S_YUNQUE) {
	// TODO Auto-generated constructor stub

}

YunqueView::~YunqueView() {
	// TODO Auto-generated destructor stub
}

void YunqueView::dropTemplate() {
	((SimpleEditorAnguloFijo * )this->controller)->dropNuevaFigura(this);
}

EditorNivel* YunqueView::getEditor() {
	SimpleEditorAnguloFijo * editor = (SimpleEditorAnguloFijo *)controller;
	editor->setFigura(this);
	return editor;
}
