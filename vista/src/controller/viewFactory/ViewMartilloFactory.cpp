/*
 * ViewMartilloFactory.cpp
 *
 *  Created on: 20/09/2013
 *      Author: joel
 */

#include "ViewMartilloFactory.h"
#include "ViewFiguraFactory.h"
#include "../../vista/figura/MartilloView.h"

ViewMartilloFactory::ViewMartilloFactory(DropController* controller): ViewFiguraFactory("resource/martillo.png",controller) {


}

ViewMartilloFactory::~ViewMartilloFactory() {
	// TODO Auto-generated destructor stub
}

FiguraView* ViewMartilloFactory::crear(int x, int y, int w, int h) {
	return new MartilloView(x, y, w, h, this->textura, this->controller);
}

FiguraView* ViewMartilloFactory::crearVistaPropia(int x, int y, int w,
		int h) {
	return new MartilloView(x,y,w,h, this->textura, this->controller);
}
