/*
 * BolaBolicheView.cpp
 *
 *  Created on: 06/10/2013
 *      Author: ezequiel
 */

#include "BolaBolicheView.h"
namespace CLIENTE {
BolaBolicheView::BolaBolicheView(float x, float y, float w, float h,int numeroEvent,SDL_Texture * textura): ObjetoView(x, y, w, h,numeroEvent,textura) {
	// TODO Auto-generated constructor stub

}

BolaBolicheView::~BolaBolicheView() {
	// TODO Auto-generated destructor stub
}

void BolaBolicheView::update(ViewMsj* mje) {
	ViewObjetoUpdateMsj* mjeCurrent = (ViewObjetoUpdateMsj*) mje ;
	this->setXl(mjeCurrent->getX());
	this->setYl(mjeCurrent->getY());
	this->setAngulo(mjeCurrent->getAngulo());
	this->setIdEventoSonido(mjeCurrent->getIdEvento());
}
}
