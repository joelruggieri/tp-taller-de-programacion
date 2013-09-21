/*
 * ViewBloqueFactory.cpp
 *
 *  Created on: 21/09/2013
 *      Author: joel
 */

#include "ViewBloqueFactory.h"
#include "../../vista/figura/BloqueView.h"

ViewBloqueFactory::ViewBloqueFactory(DropController* controller): ViewFiguraFactory("resource/Bloque_Ladrillo.png",controller) {
	// TODO Auto-generated constructor stub

}

ViewBloqueFactory::~ViewBloqueFactory() {
	// TODO Auto-generated destructor stub
}

FiguraView* ViewBloqueFactory::crear(int x, int y, int w, int h) {
	return new BloqueView(x,y,w,h, this->textura, this->controller);
}

FiguraView* ViewBloqueFactory::crearVistaPropia(int x, int y,
		int w, int h) {
	return new BloqueView(x,y,w,h, this->textura,this->controller);
}
