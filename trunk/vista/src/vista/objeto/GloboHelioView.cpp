/*
 * GloboHelioView.cpp
 *
 *  Created on: 05/10/2013
 *      Author: ezequiel
 */

#include "GloboHelioView.h"


namespace CLIENTE {
GloboHelioView::GloboHelioView(float x, float y, float w, float h, SDL_Texture * textura): ObjetoView(x, y, w, h,textura) {

}

GloboHelioView::~GloboHelioView() {
	// TODO Auto-generated destructor stub
}

}

void CLIENTE::GloboHelioView::update(ViewMsj* mje) {
	ViewObjetoUpdateMsj* mjeCurrent = (ViewObjetoUpdateMsj*)mje;
	this->setXp(mjeCurrent->getX());
	this->setYp(mjeCurrent->getY());
	this->setAngulo(mjeCurrent->getAngulo());
}
