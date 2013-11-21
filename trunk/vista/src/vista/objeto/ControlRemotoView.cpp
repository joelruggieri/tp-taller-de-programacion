/*
 * ControlRemotoView.cpp
 *
 *  Created on: 17/11/2013
 *      Author: ezequiel
 */

#include "ControlRemotoView.h"

namespace CLIENTE {

ControlRemotoView::ControlRemotoView(float x, float y, float w, float h, SDL_Texture* textura) : ObjetoView(x,y,w,h,textura) {
	// TODO Auto-generated constructor stub

}

ControlRemotoView::~ControlRemotoView() {
	// TODO Auto-generated destructor stub
}

void ControlRemotoView::update(ViewMsj* mje) {
	ViewObjetoUpdateMsj* mjeCurrent = (ViewObjetoUpdateMsj*) mje ;
	this->setXl(mjeCurrent->getX());
	this->setYl(mjeCurrent->getY());
	this->setAngulo(mjeCurrent->getAngulo());
	this->setIdEventoSonido(mjeCurrent->getIdEvento());
}

} /* namespace CLIENTE */
