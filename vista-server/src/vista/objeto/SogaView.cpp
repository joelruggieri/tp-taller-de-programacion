/*
 * Sogaview.cpp
 *
 *  Created on: Oct 5, 2013
 *      Author: matias
 */

#include "SogaView.h"
#include "../../controller/editor/EditorUnion.h"
#include <src/objeto/Soga.h>
SogaView::SogaView(float x, float y,EditorUnion * editor): UnionView(x, y,editor) {
}

void SogaView::dropTemplate() {
	//controller->dropNuevaFigura(this);
}

EditorNivel* SogaView::getEditor() {
	EditorUnion* editor = (EditorUnion*)controller;
	editor->setFigura(this);
	return editor;
}

SogaView::~SogaView() {
	// TODO Auto-generated destructor stub
}

void SogaView::dibujarse(SDL_Renderer * renderer, SDL_Rect & dest){
	super::dibujarse(renderer, 100, 100, 100);
}
