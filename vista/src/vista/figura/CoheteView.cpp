/*
 * CoheteView.cpp
 *
 *  Created on: 21/09/2013
 *      Author: joel
 */

#include "CoheteView.h"
#include "../../controller/DropController.h"


void CoheteView::dropTemplate(){
	controller->dropNuevaFigura(this);
}

CoheteView::CoheteView(int x, int y, int w, int h, SDL_Texture * textura,DropController * controller): FiguraView(x,y,w,h,textura,controller) {

}

CoheteView::~CoheteView() {
	// TODO Auto-generated destructor stub
}

