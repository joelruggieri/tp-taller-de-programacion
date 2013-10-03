/*
 * ViewPlataformaFactory.cpp
 *
 *  Created on: 03/10/2013
 *      Author: joel
 */

#include "ViewPlataformaFactory.h"



ViewPlataformaFactory::ViewPlataformaFactory(DropController* controller): ViewFiguraFactory("resource/piso.png", controller) {

}

FiguraView* ViewPlataformaFactory::crear(int x, int y, int w, int h) {
	return new PlataformaView(x, y, w, h, this->textura, this->controller);
}

ViewPlataformaFactory::~ViewPlataformaFactory() {
	// TODO Auto-generated destructor stub
}

View* ViewPlataformaFactory::crearVistaPropia(int x, int y, int w,int h) {
	return new FactoryView(x,y,w,h, this->textura);
}
