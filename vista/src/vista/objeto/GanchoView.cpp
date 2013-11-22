/*
 * GanchoView.cpp
 *
 *  Created on: 13/11/2013
 *      Author: joel
 */

#include "GanchoView.h"

namespace CLIENTE {

GanchoView::GanchoView(float x, float y, float w, float h,int numeroEvent,SDL_Texture * textura): ObjetoView(x, y, w, h,numeroEvent,textura) {

}

GanchoView::~GanchoView() {
	// TODO Auto-generated destructor stub
}

void GanchoView::update(ViewMsj* mje) {
	ViewObjetoUpdateMsj* mjeCurrent = (ViewObjetoUpdateMsj*) mje ;
	this->setXl(mjeCurrent->getX());
	this->setYl(mjeCurrent->getY());
	this->setAngulo(mjeCurrent->getAngulo());
	this->setIdEventoSonido(mjeCurrent->getIdEvento());
}

} /* namespace CLIENTE */
