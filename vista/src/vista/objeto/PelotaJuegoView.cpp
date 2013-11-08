/*
 * PelotaJuegoView.cpp
 *
 *  Created on: 06/10/2013
 *      Author: ezequiel
 */

#include "PelotaJuegoView.h"
namespace CLIENTE {
PelotaJuegoView::PelotaJuegoView(float x, float y, float w, float h, SDL_Texture * textura): ObjetoView(x, y, w, h,textura) {

}

PelotaJuegoView::~PelotaJuegoView() {
	// TODO Auto-generated destructor stub
}

}

void CLIENTE::PelotaJuegoView::update(ViewMsj* mje) {
ViewObjetoUpdateMsj* mjeCurrent = (ViewObjetoUpdateMsj*)mje;
this->setXl(mjeCurrent->getX());
this->setYl(mjeCurrent->getY());
this->setAngulo(mjeCurrent->getAngulo());
}
