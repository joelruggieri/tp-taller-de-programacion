/*
 * GloboView.cpp
 *
 *  Created on: 20/09/2013
 *      Author: joel
 */

#include "GloboView.h"
#include "../../controller/DropController.h"

void GloboView::dropTemplate() {
	controller->dropNuevaFigura(this);
}


GloboView::GloboView(int x, int y, int w, int h, SDL_Texture * textura,DropController * controller):FiguraView(x, y, w, h,textura, controller) {

}

GloboView::~GloboView() {
	// TODO Auto-generated destructor stub
}

