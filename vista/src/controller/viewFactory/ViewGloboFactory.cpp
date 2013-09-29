/*
 * ViewGloboFactory.cpp
 *
 *  Created on: 20/09/2013
 *      Author: joel
 */

#include "ViewGloboFactory.h"
#include "../../vista/figura/GloboView.h"


ViewGloboFactory::ViewGloboFactory(DropController* controler): ViewFiguraFactory("resource/globo-3-naranja.png", controler)  {


}

ViewGloboFactory::~ViewGloboFactory() {
	// TODO Auto-generated destructor stub
}

FiguraView* ViewGloboFactory::crear(int x, int y, int w, int h) {
	return new GloboView(x, y, w, h, this->textura, this->controller);
}

View* ViewGloboFactory::crearVistaPropia(int x, int y, int w,
		int h) {
	return new FactoryView(x,y,w,h, this->textura);
}
