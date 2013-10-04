/*
 * RuedaView.cpp
 *
 *  Created on: 19/09/2013
 *      Author: joel
 */

#include "RuedaView.h"
#include "CirculoView.h"
#include "../../controller/DropController.h"


namespace std {

void RuedaView::dropTemplate() {
	controller->dropNuevaFigura(this);
}

RuedaView::RuedaView(int x, int y, int w, int h, SDL_Texture * textura, DropController * controller):FiguraView(x, y, w, h,textura, controller) {

}

RuedaView::~RuedaView() {

}

} /* namespace std */

EditorNivel* std::RuedaView::getEditor() {
	return 0;
}
