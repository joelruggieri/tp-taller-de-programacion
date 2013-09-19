/*
 * RomboView.cpp
 *
 *  Created on: 07/09/2013
 *      Author: jonathan
 */

#include "RomboView.h"
#include "../../controller/DropController.h"

RomboView::RomboView(int x, int y, int w, int h,SDL_Texture * textura,DropController * controller):FiguraView(x, y, w, h, textura, controller) {
	// TODO Auto-generated constructor stub

}

RomboView::~RomboView() {
	// TODO Auto-generated destructor stub
}

void RomboView::dropTemplate() {
	controller->dropNuevaFigura(this);
}