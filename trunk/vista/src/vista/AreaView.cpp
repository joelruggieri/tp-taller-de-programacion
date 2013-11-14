/*
 * AreaView.cpp
 *
 *  Created on: 11/11/2013
 *      Author: ezequiel
 */

#include "AreaView.h"
#include "../ConstantesVista.h"
namespace CLIENTE {

AreaView::AreaView(float x, float y, float w, float h, SDL_Texture* textura) : View(x,y,w,h,LAYER_AREA){
this->textura = textura;
}

AreaView::~AreaView() {
	// TODO Auto-generated destructor stub
}

void AreaView::dibujarse(SDL_Renderer* renderer) {
	SDL_Rect dest;
		dest.h = this->hp;
		dest.w = this->wp;
		dest.x = this->xp;
		dest.y = this->yp;
//		dest.h = 120;
//		dest.w = 80;
//		dest.x = 200;
//		dest.y = 200;

		this->dibujarse(renderer, dest);
}

void AreaView::dibujarse(SDL_Renderer* re, SDL_Rect& dst) {
	SDL_RenderCopy(re,this->textura, NULL, &dst);
}



void CLIENTE::AreaView::update(ViewMsj*) {
}


void CLIENTE::AreaView::resize() {
//	Transformacion tl;
//	wp = tl.escalarInversaEnX(wl);
//	hp = tl.escalarInversaEnY(hl);
	wp = 200;
	hp = 100;
//	tl.setVector(xl, yl);
//	float xpf, ypf;
//	tl.getResultadoInverso(xpf,ypf);
//	xp = round(xpf);
//	yp = round (ypf);
	xp = 100;
	yp = 100;
}

bool AreaView::isUpdated() {
	return true;
}
} /* namespace CLIENTE */


