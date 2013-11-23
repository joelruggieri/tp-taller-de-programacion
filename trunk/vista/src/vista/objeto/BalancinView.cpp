/*
 * BalancinView.cpp
 *
 *  Created on: 05/10/2013
 *      Author: joel
 */

#include "BalancinView.h"
#include "../CargadorDeSonidos.h"
namespace CLIENTE {

BalancinView::~BalancinView() {
	// TODO Auto-generated destructor stub
}

void BalancinView::update(ViewMsj* mje) {
	ViewObjetoUpdateMsj* mjeCurrent = (ViewObjetoUpdateMsj*)mje;
	this->setXl(mjeCurrent->getX());
	this->setYl(mjeCurrent->getY());

	this->setAngulo(mjeCurrent->getAngulo());
	this->setIdEventoSonido(mjeCurrent->getIdEvento());
	resizear();
}

}

CLIENTE::BalancinView::BalancinView(float x, float y, float w, float h,int numeroEvent,
		SDL_Texture* textura): ObjetoView(x, y, w, h,numeroEvent,textura) {
	this->sonido = CargadorDeSonidos::Instance()->getSonido(ID_SONIDO_SUBIBAJA);
}

void CLIENTE::BalancinView::dibujarse(SDL_Renderer* r) {
	super::dibujarse(r);
}
