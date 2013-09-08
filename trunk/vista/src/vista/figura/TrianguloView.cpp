/*
 * View.cpp
 *
 *  Created on: 07/09/2013
 *      Author: jonathan
 */

#include "TrianguloView.h"
#include "../../controller/DropController.h"

void TrianguloView::dropTemplate(DropController* manager) {
	manager->dropNuevaFigura(this);
}

TrianguloView::TrianguloView(int x, int y, int w, int h): FiguraView(x, y, w, h) {

}

TrianguloView::~TrianguloView() {

}

void TrianguloView::dibujarse(SDL_Renderer*) {
}
