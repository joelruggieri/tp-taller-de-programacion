/*
 * CarritoView.cpp
 *
 *  Created on: 14/11/2013
 *      Author: joel
 */

#include "CarritoView.h"

CLIENTE::CarritoView::CarritoView(float x, float y, float w, float h,
		SDL_Texture* textura): ObjetoView(x, y, w, h,textura) {

}

CLIENTE::CarritoView::~CarritoView() {
	// TODO Auto-generated destructor stub
}

/*void CLIENTE::CarritoView::dibujarse(SDL_Renderer* r) {
	super::dibujarse(r);
}*/

void CLIENTE::CarritoView::update(ViewMsj* mje) {
	ViewObjetoUpdateMsj* mjeCurrent = (ViewObjetoUpdateMsj*)mje;
	this->setXl(mjeCurrent->getX());
	this->setYl(mjeCurrent->getY());

	this->setAngulo(mjeCurrent->getAngulo());
	resizear();
}
