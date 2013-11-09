/*
 * SogaEstaticaView.cpp
 *
 *  Created on: 15/10/2013
 *      Author: jonathan
 */

#include "SogaEstaticaView.h"
#include "../CargadorDeTextures.h"
#include "SogaView.h"

namespace CLIENTE {
SogaEstaticaView::SogaEstaticaView(float x, float y, float w, float h, SDL_Texture * textura): UnionEstaticaView (x, y, w, h,textura) {
	texturaTramo = CargadorDeTextures::Instance()->cargarTexture("resource/eslabon_cinta.png");
}


SogaEstaticaView::~SogaEstaticaView() {
	// TODO Auto-generated destructor stub
}

void SogaEstaticaView::update(ViewMsj* mje) {
	ViewObjetoUpdateMsj* mjeCurrent = (ViewObjetoUpdateMsj*) mje;
	this->setXl(mjeCurrent->getX());
	this->setYl(mjeCurrent->getY());
}
}
