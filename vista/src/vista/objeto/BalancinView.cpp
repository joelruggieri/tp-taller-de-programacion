/*
 * BalancinView.cpp
 *
 *  Created on: 05/10/2013
 *      Author: joel
 */

#include "BalancinView.h"
namespace CLIENTE {

BalancinView::~BalancinView() {
	// TODO Auto-generated destructor stub
}

void BalancinView::update(ViewMsj* mje) {
	ViewObjetoUpdateMsj* mjeCurrent = (ViewObjetoUpdateMsj*)mje;
	this->setXp(mjeCurrent->getX());
	this->setYp(mjeCurrent->getY());
	this->setAngulo(mjeCurrent->getAngulo());
}

}

CLIENTE::BalancinView::BalancinView(float x, float y, float w, float h,
		SDL_Texture* textura): ObjetoView(x, y, w, h,textura) {
}
