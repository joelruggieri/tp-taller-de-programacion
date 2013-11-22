/*
 * ClavoView.cpp
 *
 *  Created on: 14/11/2013
 *      Author: ezequiel
 */

#include "ClavoView.h"

namespace CLIENTE {

ClavoView::ClavoView(float x, float y, float w, float h,int numeroEvent,
		SDL_Texture* textura): ObjetoView(x, y, w, h,numeroEvent,textura) {
	// TODO Auto-generated constructor stub

}

ClavoView::~ClavoView() {
	// TODO Auto-generated destructor stub
}

void ClavoView::update(ViewMsj* mje) {
	ViewObjetoUpdateMsj* mjeCurrent = (ViewObjetoUpdateMsj*)mje;
	this->setXl(mjeCurrent->getX());
	this->setYl(mjeCurrent->getY());

	this->setAngulo(mjeCurrent->getAngulo());
	this->setIdEventoSonido(mjeCurrent->getIdEvento());
	resizear();
}

void ClavoView::dibujarse(SDL_Renderer* r) {
	super::dibujarse(r);
}

} /* namespace CLIENTE */
