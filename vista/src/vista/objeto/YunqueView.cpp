/*
 * YunqueView.cpp
 *
 *  Created on: 13/11/2013
 *      Author: ezequiel
 */

#include "YunqueView.h"

namespace CLIENTE {

YunqueView::YunqueView(float x, float y, float w, float h,int numeroEvent, SDL_Texture * textura) :ObjetoView(x, y, w, h,numeroEvent,textura)  {
	// TODO Auto-generated constructor stub

}

YunqueView::~YunqueView() {
	// TODO Auto-generated destructor stub
}

void YunqueView::update(ViewMsj* mje) {
	ViewObjetoUpdateMsj* mjeCurrent = (ViewObjetoUpdateMsj*)mje;
	this->setXl(mjeCurrent->getX());
	this->setYl(mjeCurrent->getY());
	this->setAngulo(mjeCurrent->getAngulo());
	this->setIdEventoSonido(mjeCurrent->getIdEvento());

}

} /* namespace CLIENTE */
