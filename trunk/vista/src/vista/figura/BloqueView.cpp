/*
 * BloqueView.cpp
 *
 *  Created on: 21/09/2013
 *      Author: joel
 */

#include "BloqueView.h"
#include "../../controller/DropController.h"

void BloqueView::dropTemplate(){
	controller->dropNuevaFigura(this);
}


BloqueView::BloqueView(int x, int y, int w, int h, SDL_Texture * textura,DropController * controller):FiguraView(x,y,w,h,textura,controller) {

}

BloqueView::~BloqueView() {
	// TODO Auto-generated destructor stub
}

