/*
 * PlataformaView.cpp
 *
 *  Created on: 03/10/2013
 *      Author: joel
 */

#include "PlataformaView.h"

namespace CLIENTE {
PlataformaView::PlataformaView(float x, float y, float w, float h,int numeroEvent, SDL_Texture * textura) : ObjetoView(x,y,w,h,numeroEvent,textura) {

}

PlataformaView::~PlataformaView() {
	// TODO Auto-generated destructor stub
}

void PlataformaView::update(ViewMsj* mje){
	ViewObjetoConAnchoUpdateMsj* mjeCurrent = (ViewObjetoConAnchoUpdateMsj*)mje;
	this->setXl(mjeCurrent->getX());
	this->setYl(mjeCurrent->getY());
	this->setAngulo(mjeCurrent->getAngulo());
	this->setWl(mjeCurrent->getAncho());
	this->setIdEventoSonido(mjeCurrent->getIdEvento());
}
}
