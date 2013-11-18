/*
 * BombaView.cpp
 *
 *  Created on: 17/11/2013
 *      Author: ezequiel
 */

#include "BombaView.h"

namespace CLIENTE {

BombaView::BombaView(float x, float y, float w, float h, SDL_Texture * textura) : ObjetoView(x,y,w,h,textura) {

}

BombaView::~BombaView() {
	// TODO Auto-generated destructor stub
}

void BombaView::update(ViewMsj* mje) {
	ViewObjetoUpdateMsj* mjeCurrent = (ViewObjetoUpdateMsj*)mje;
	this->setXl(mjeCurrent->getX());
	this->setYl(mjeCurrent->getY());
	this->setAngulo(mjeCurrent->getAngulo());
}

} /* namespace CLIENTE */
