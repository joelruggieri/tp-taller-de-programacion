/*
 * CarritoView.cpp
 *
 *  Created on: 21/09/2013
 *      Author: joel
 */

#include "CarritoView.h"
#include "../../controller/DropController.h"

void CarritoView::dropTemplate(){
	controller->dropNuevaFigura(this);
}
CarritoView::CarritoView(int x, int y, int w, int h, SDL_Texture * textura,DropController * controller): FiguraView(x,y,w,h,textura,controller) {


}

CarritoView::~CarritoView() {
	// TODO Auto-generated destructor stub
}

