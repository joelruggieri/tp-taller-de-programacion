/*
 * FactoryView.cpp
 *
 *  Created on: 21/09/2013
 *      Author: jonathan
 */

#include "FactoryView.h"
#include "SDL2/SDL.h"

namespace CLIENTE {
FactoryView::FactoryView(float x, float y, float w, float h, SDL_Texture * textura) :
		View(x, y, w, h) {
	this->textura = textura;

}

FactoryView::~FactoryView() {
	// TODO Auto-generated destructor stub
}


void FactoryView::dibujarse(SDL_Renderer * renderer){
	SDL_Rect dest;
	dest.h = this->hp;
	dest.w = this->wp;
	dest.x = this->xp;
	dest.y = this->yp;
	this->dibujarse(renderer, dest);
}

void FactoryView::dibujarse(SDL_Renderer * renderer, SDL_Rect & dest){
		SDL_RenderCopy(renderer,this->textura,NULL,&dest);
}

void FactoryView::resizear() {

	//ENTREGA3 GETTL
//	this->setW(Resizer::Instance()->resizearDistanciaX(this->getW()));
//	this->setXc((Resizer::Instance()->resizearDistanciaX(this->getXCentro())));
//	this->setH(Resizer::Instance()->resizearDistanciaY(this->getH()));
//	this->setYc((Resizer::Instance()->resizearDistanciaY(this->getYCentro())));
}
}
