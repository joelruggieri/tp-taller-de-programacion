/*
 * CorreaView.cpp
 *
 *  Created on: 15/10/2013
 *      Author: joel
 */

#include "CorreaView.h"
#include "../../controller/editor/EditorUnion.h"
#include "src/objeto/Correa.h"

CorreaView::CorreaView(int x, int y, SDL_Texture * textura,EditorUnion* editor): UnionView(x, y,textura, editor) {

}

CorreaView::~CorreaView() {
	// TODO Auto-generated destructor stub
}

EditorNivel* CorreaView::getEditor(){
	EditorUnion * editor = (EditorUnion *)controller;
	editor->setFigura(this);
	return editor;
}

void CorreaView::dropTemplate(){

}


void CorreaView::dibujarse(SDL_Renderer* renderer){
//	SDL_Rect dest;
//	dest.h = this->getH();
//	dest.w = this->getW();
//	dest.x = xHasta;
//	dest.y = yHasta;
//	SDL_Rect src;
//	src.h = this->getH();
//	src.w = this->getW();
//	src.x = xDesde;
//	src.y = yDesde;
//	this->dibujarse(renderer, src, dest);
	super::dibujarse(renderer,10,10,10);
}


