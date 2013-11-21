/*
 * PoleaView.cpp
 *
 *  Created on: 13/11/2013
 *      Author: joel
 */

#include "PoleaView.h"

namespace CLIENTE {

PoleaView::PoleaView(float x, float y, float w, float h, SDL_Texture * textura): ObjetoView(x, y, w, h,textura) {

}

PoleaView::~PoleaView() {
	// TODO Auto-generated destructor stub
}

void PoleaView::update(ViewMsj* mje) {
	ViewObjetoUpdateMsj* mjeCurrent = (ViewObjetoUpdateMsj*) mje ;
	this->setXl(mjeCurrent->getX());
	this->setYl(mjeCurrent->getY());
	this->setAngulo(mjeCurrent->getAngulo());
	this->setIdEventoSonido(mjeCurrent->getIdEvento());
}

} /* namespace CLIENTE */
