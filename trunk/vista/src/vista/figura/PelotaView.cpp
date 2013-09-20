/*
 * PelotaView.cpp
 *
 *  Created on: 20/09/2013
 *      Author: joel
 */

#include "PelotaView.h"
#include "../../controller/DropController.h"

void PelotaView::dropTemplate(){
	controller->dropNuevaFigura(this);
}

PelotaView::PelotaView(int x, int y, int w, int h, SDL_Texture * textura,DropController * controller): FiguraView(x,y,w,h,textura,controller) {


}

PelotaView::~PelotaView() {
	// TODO Auto-generated destructor stub
}

