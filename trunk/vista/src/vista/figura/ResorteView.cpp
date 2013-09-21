/*
 * ResorteView.cpp
 *
 *  Created on: 20/09/2013
 *      Author: joel
 */

#include "ResorteView.h"
#include "../../controller/DropController.h"

void ResorteView::dropTemplate() {
	controller->dropNuevaFigura(this);
}

ResorteView::ResorteView(int x, int y, int w, int h, SDL_Texture * textura,DropController * controller): FiguraView(x,y,w,h,textura,controller) {
	// TODO Auto-generated constructor stub

}

ResorteView::~ResorteView() {
	// TODO Auto-generated destructor stub
}

