/*
 * CorreaEstaticaView.cpp
 *
 *  Created on: 16/10/2013
 *      Author: jonathan
 */

#include "CorreaEstaticaView.h"

#include "CorreaView.h"
namespace CLIENTE {
CorreaEstaticaView::CorreaEstaticaView(float x, float y, float w, float h,int numeroEvent,SDL_Texture * textura) :
		UnionEstaticaView(x, y, w, h,numeroEvent,textura) {

}

CorreaEstaticaView::~CorreaEstaticaView() {
	// TODO Auto-generated destructor stub
}

void CorreaEstaticaView::update(ViewMsj* mje) {
ViewObjetoUnionUpdateMsj* mjeCurrent = (ViewObjetoUnionUpdateMsj*) mje;
this->setXl(mjeCurrent->getX());
this->setYl(mjeCurrent->getY());
//this->setIdEventoSonido(mjeCurrent->getIdEvento());

}
}
