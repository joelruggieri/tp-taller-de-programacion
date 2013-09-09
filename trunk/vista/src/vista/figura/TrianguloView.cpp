/*
 * View.cpp
 *
 *  Created on: 07/09/2013
 *      Author: jonathan
 */

#include "TrianguloView.h"
#include "../../controller/DropController.h"

void TrianguloView::dropTemplate() {
	controller->dropNuevaFigura(this);
}

TrianguloView::TrianguloView(int x, int y, int w, int h, SDL_Texture * textura,DropController * controller): FiguraView(x, y, w, h, textura, controller) {

}

TrianguloView::~TrianguloView() {

}

