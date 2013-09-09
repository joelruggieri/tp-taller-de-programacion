/*
 * ViewCirculoFactory.cpp
 *
 *  Created on: 05/09/2013
 *      Author: jonathan
 */

#include "ViewCirculoFactory.h"
#include "../../vista/figura/CirculoView.h"

ViewCirculoFactory::ViewCirculoFactory(SDL_Renderer * renderer): ViewFiguraFactory("resource/circulo.jpg", renderer) {

}

ViewCirculoFactory::~ViewCirculoFactory() {
	// TODO Auto-generated destructor stub
}

FiguraView* ViewCirculoFactory::crear(int x, int y, int w, int h) {
	return new CirculoView(x, y, w, h, this->textura);
}

FiguraView* ViewCirculoFactory::crearVistaPropia(int x, int y, int w,
		int h) {
	return new CirculoView(x,y,w,h, this->textura);
}
