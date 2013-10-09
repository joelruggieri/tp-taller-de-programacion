/*
 * ViewPlataformaFactory.cpp
 *
 *  Created on: 03/10/2013
 *      Author: joel
 */

#include "ViewPlataformaFactory.h"



ViewPlataformaFactory::ViewPlataformaFactory(SimpleEditorEstirar * editor): ViewFiguraFactory("resource/piso.png", editor) {

}

FiguraView* ViewPlataformaFactory::crear(int x, int y, int w, int h) {
	//TODO REVEER MEDIDAS DE LA VISTA DE LA FACTORY
	return new PlataformaView(x, y, w, h, this->textura, (SimpleEditorEstirar *) this->controller);
}

ViewPlataformaFactory::~ViewPlataformaFactory() {
	// TODO Auto-generated destructor stub
}

View* ViewPlataformaFactory::crearVistaPropia(int x, int y, int w,int h) {
	return new FactoryView(x,y,w,h, this->textura);
}
