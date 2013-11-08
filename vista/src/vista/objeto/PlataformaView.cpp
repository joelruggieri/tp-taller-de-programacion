/*
 * PlataformaView.cpp
 *
 *  Created on: 03/10/2013
 *      Author: joel
 */

#include "PlataformaView.h"

namespace CLIENTE {
PlataformaView::PlataformaView(float x, float y, float w, float h, SDL_Texture * textura) : ObjetoView(x,y,w,h,textura) {

}

PlataformaView::~PlataformaView() {
	// TODO Auto-generated destructor stub
}

void PlataformaView::update(ViewMsj* mje){
	ViewObjetoConAnchoUpdateMsj* mjeCurrent = (ViewObjetoConAnchoUpdateMsj*)mje;
	this->setXp(mjeCurrent->getX());
	this->setYp(mjeCurrent->getY());
	this->setAngulo(mjeCurrent->getAngulo());
	this->setWp(mjeCurrent->getAncho());

}
}
