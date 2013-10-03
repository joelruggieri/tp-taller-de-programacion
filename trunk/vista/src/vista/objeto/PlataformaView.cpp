/*
 * PlataformaView.cpp
 *
 *  Created on: 03/10/2013
 *      Author: joel
 */

#include "PlataformaView.h"
#include "../../controller/DropController.h"

PlataformaView::PlataformaView(int x, int y, int w, int h, SDL_Texture * textura,DropController * controller) : ObjetoView(x,y,w,h,textura,controller) {

}

PlataformaView::~PlataformaView() {
	// TODO Auto-generated destructor stub
}

void 	PlataformaView::dropTemplate() {
	controller->dropNuevaFigura(this);
}

