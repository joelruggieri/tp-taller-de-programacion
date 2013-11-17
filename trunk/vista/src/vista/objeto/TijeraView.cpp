/*
 * TijeraView.cpp
 *
 *  Created on: 16/11/2013
 *      Author: joel
 */

#include "TijeraView.h"

namespace CLIENTE {

TijeraView::TijeraView(float x, float y, float w, float h, SDL_Texture* textura): ObjetoView(x, y, w, h,textura) {

}

void TijeraView::dibujarse(SDL_Renderer* r) {

	super::dibujarse(r);
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
