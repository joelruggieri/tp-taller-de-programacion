/*
 * ViewRuedaFactory.cpp
 *
 *  Created on: 19/09/2013
 *      Author: joel
 */

#include "ViewRuedaFactory.h"
#include "../../vista/figura/RuedaView.h"

ViewRuedaFactory::ViewRuedaFactory(DropController * controller): ViewFiguraFactory("resource/rueda.png", controller) {

}

ViewRuedaFactory::~ViewRuedaFactory() {
	// TODO Auto-generated destructor stub
}

FiguraView* ViewRuedaFactory::crear(int x, int y, int w, int h) {
	return new RuedaView(x, y, w, h, this->textura, this->controller);
}

FiguraView* ViewRuedaFactory::crearVistaPropia(int x, int y, int w,
		int h) {
	return new RuedaView(x,y,w,h, this->textura, this->controller);
}
