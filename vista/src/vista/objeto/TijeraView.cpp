/*
 * TijeraView.cpp
 *
 *  Created on: 16/11/2013
 *      Author: joel
 */

#include "TijeraView.h"
#include "../CargadorDeTextures.h"
namespace CLIENTE {

TijeraView::TijeraView(float x, float y, float w, float h, SDL_Texture* textura): ObjetoView(x, y, w, h,textura) {
	t2 = CargadorDeTextures::Instance()->cargarTexture(PATH_VISTA_TIJERA2);
}

void TijeraView::dibujarse(SDL_Renderer* r) {
	SDL_Rect dest;
	dest.h = this->hp;
	dest.w = this->wp;
	dest.x = this->xp;
	dest.y = this->yp;
	SDL_RenderCopyEx(r,this->getTexture(), NULL, &dest,this->getAngulo() +30,NULL,SDL_FLIP_NONE);
	SDL_RenderCopyEx(r,this->t2, NULL, &dest,this->getAngulo()-30,NULL,SDL_FLIP_NONE);

}

void TijeraView::update(ViewMsj* mje) {
	ViewObjetoUpdateMsj* mjeCurrent = (ViewObjetoUpdateMsj*)mje;
	this->setXl(mjeCurrent->getX());
	this->setYl(mjeCurrent->getY());

	this->setAngulo(mjeCurrent->getAngulo());
	resizear();
}

TijeraView::~TijeraView() {
	// TODO Auto-generated destructor stub
}

} /* namespace CLIENTE */
