/*
 * CuadradoView.cpp
 *
 *  Created on: 07/09/2013
 *      Author: jonathan
 */

#include "CuadradoView.h"
#include "../../controller/DropController.h"

void CuadradoView::dropTemplate(DropController* manager) {
	manager->dropNuevaFigura(this);
}

CuadradoView::CuadradoView(int x, int y, int w, int h):FiguraView(x, y, w, h) {

}

CuadradoView::~CuadradoView() {

}

void CuadradoView::dibujarse(SDL_Renderer* renderer) {
	SDL_Rect dest;
	dest.x= this->getX();
	dest.y=this->getY();
	dest.w=this->getW();
	dest.h= this->getH();
	SDL_RenderFillRect(renderer, &dest);
}
