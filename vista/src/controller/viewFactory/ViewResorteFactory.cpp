/*
 * ViewResorteFactory.cpp
 *
 *  Created on: 20/09/2013
 *      Author: joel
 */

#include "ViewResorteFactory.h"
#include "../../vista/figura/ResorteView.h"

ViewResorteFactory::ViewResorteFactory(DropController* controller): ViewFiguraFactory("resource/resorte negro panteras.png", controller) {


}

ViewResorteFactory::~ViewResorteFactory() {
	// TODO Auto-generated destructor stub
}

FiguraView* ViewResorteFactory::crear(int x, int y, int w, int h) {
	return new ResorteView(x,y,w,h, this->textura, this->controller);
}

FiguraView* ViewResorteFactory::crearVistaPropia(int x, int y,
		int w, int h) {
	return new ResorteView(x,y,w,h, this->textura,this->controller);
}
