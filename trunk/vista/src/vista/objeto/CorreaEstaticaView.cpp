/*
 * CorreaEstaticaView.cpp
 *
 *  Created on: 16/10/2013
 *      Author: jonathan
 */

#include "CorreaEstaticaView.h"

#include "CorreaView.h"
namespace CLIENTE {
CorreaEstaticaView::CorreaEstaticaView(int x, int y, int w, int h, SDL_Texture * textura) :
		UnionEstaticaView(x, y, w, h, textura) {

}

CorreaEstaticaView::~CorreaEstaticaView() {
	// TODO Auto-generated destructor stub
}

void CorreaEstaticaView::update(ViewMsj*) {
}
}
