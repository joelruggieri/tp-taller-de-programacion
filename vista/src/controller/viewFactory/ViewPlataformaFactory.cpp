/*
 * ViewPlataformaFactory.cpp
 *
 *  Created on: 03/10/2013
 *      Author: joel
 */

#include "ViewPlataformaFactory.h"



ViewPlataformaFactory::ViewPlataformaFactory(SimpleEditorNivel * editor): ViewFiguraFactory("resource/piso.png", controller) {
	this->editor= editor;
}

FiguraView* ViewPlataformaFactory::crear(int x, int y, int w, int h) {
	return new PlataformaView(x, y, w, h, this->textura, this->editor);
}

ViewPlataformaFactory::~ViewPlataformaFactory() {
	// TODO Auto-generated destructor stub
}

View* ViewPlataformaFactory::crearVistaPropia(int x, int y, int w,int h) {
	return new FactoryView(x,y,w,h, this->textura);
}
