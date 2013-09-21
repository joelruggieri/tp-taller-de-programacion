/*
 * ViewCarritoFactory.cpp
 *
 *  Created on: 21/09/2013
 *      Author: joel
 */

#include "ViewCarritoFactory.h"
#include "../../vista/figura/CarritoView.h"

ViewCarritoFactory::ViewCarritoFactory(DropController* controller): ViewFiguraFactory("resource/carrito-supermercado.png",controller) {

}

ViewCarritoFactory::~ViewCarritoFactory() {
	// TODO Auto-generated destructor stub
}

FiguraView* ViewCarritoFactory::crear(int x, int y, int w, int h) {
	return new CarritoView(x,y,w,h, this->textura, this->controller);
}

FiguraView* ViewCarritoFactory::crearVistaPropia(int x, int y,
		int w, int h) {
	return new CarritoView(x,y,w,h, this->textura,this->controller);
}
