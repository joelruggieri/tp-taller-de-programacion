/*
 * BalancinView.cpp
 *
 *  Created on: 05/10/2013
 *      Author: joel
 */

#include "BalancinView.h"
#include "../CargadorDeSonidos.h"
#include "src/Logger.h"
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
}

}

CLIENTE::BalancinView::BalancinView(float x, float y, float w, float h,int numeroEvent,
		SDL_Texture* textura): ObjetoView(x, y, w, h,numeroEvent,textura) {
}

void CLIENTE::BalancinView::dibujarse(SDL_Renderer* r) {
	super::dibujarse(r);
}
