/*
 * Sogaview.cpp
 *
 *  Created on: Oct 5, 2013
 *      Author: matias
 */

#include "SogaView.h"
#include "../../controller/editor/SimpleEditorSoga.h"

SogaView::SogaView(int x, int y, int w, int h, SDL_Texture * textura,SimpleEditorSoga * editor): ObjetoView(x, y, w, h,textura, editor) {

}

void SogaView::dropTemplate() {
	//controller->dropNuevaFigura(this);
}

EditorNivel* SogaView::getEditor() {
	SimpleEditorSoga* editor = (SimpleEditorSoga*)controller;
	editor->setFigura(this);
	return editor;
}

SogaView::~SogaView() {
	// TODO Auto-generated destructor stub
}

