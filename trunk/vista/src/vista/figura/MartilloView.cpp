/*
 * MartilloView.cpp
 *
 *  Created on: 20/09/2013
 *      Author: joel
 */

#include "MartilloView.h"
#include "../../controller/DropController.h"

void MartilloView::dropTemplate(){
	controller->dropNuevaFigura(this);
}
MartilloView::MartilloView(int x, int y, int w, int h, SDL_Texture * textura,DropController * controller): FiguraView(x,y,w,h,textura,controller) {


}

MartilloView::~MartilloView() {
	// TODO Auto-generated destructor stub
}

