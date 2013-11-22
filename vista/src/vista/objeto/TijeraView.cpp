/*
 * TijeraView.cpp
 *
 *  Created on: 16/11/2013
 *      Author: joel
 */

#include "TijeraView.h"
#include "../CargadorDeTextures.h"
namespace CLIENTE {

TijeraView::TijeraView(float x, float y, float w, float h,int numeroEvent,SDL_Texture* textura1, SDL_Texture* textura2): ObjetoView(x, y, w, h,numeroEvent,textura1) {
	t2 = textura2;
}

void TijeraView::dibujarse(SDL_Renderer* r) {
	SDL_Rect dest;
	dest.h = this->hp;
	dest.w = this->wp;
	dest.x = this->xp;
	dest.y = this->yp;
	SDL_RenderCopyEx(r,this->t2, NULL, &dest,angulo1,NULL,SDL_FLIP_NONE);
	SDL_RenderCopyEx(r,this->getTexture(), NULL, &dest,angulo2,NULL,SDL_FLIP_NONE);

}

void TijeraView::update(ViewMsj* mje) {
	ViewTijeraMsj* mjeCurrent = (ViewTijeraMsj*)mje;
	this->setXl(mjeCurrent->getX());
	this->setYl(mjeCurrent->getY());
	angulo1= mjeCurrent->getRotacionAspa1();
	angulo2= mjeCurrent->getRotacionAspa2();
	this->setIdEventoSonido(mjeCurrent->getIdEvento());
}

TijeraView::~TijeraView() {
	// TODO Auto-generated destructor stub
}

} /* namespace CLIENTE */
