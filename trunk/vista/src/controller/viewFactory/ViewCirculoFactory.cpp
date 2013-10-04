/*
 * ViewCirculoFactory.cpp
 *
 *  Created on: 05/09/2013
 *      Author: jonathan
 */

#include "ViewCirculoFactory.h"
#include "../../vista/figura/CirculoView.h"

ViewCirculoFactory::ViewCirculoFactory(DropController* controller, SimpleEditorNivel * editor): ViewFiguraFactory("resource/circulo.png", controller) {

}

ViewCirculoFactory::~ViewCirculoFactory() {
	// TODO Auto-generated destructor stub
}

FiguraView* ViewCirculoFactory::crear(int x, int y, int w, int h) {
	return new CirculoView(x, y, w, h, this->textura, this->controller);
}

FactoryView* ViewCirculoFactory::crearVistaPropia(int x, int y, int w,
		int h) {
	return new FactoryView(x,y,w,h, this->textura);
}
