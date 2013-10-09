/*
 * ViewSogaFactory.cpp
 *
 *  Created on: Oct 5, 2013
 *      Author: matias
 */

#include "ViewSogaFactory.h"
#include "../../vista/objeto/SogaView.h"
#include "../../ConstantesVista.h"
namespace std {

ViewSogaFactory::ViewSogaFactory(SimpleEditorSoga* editor):ViewFiguraFactory(PATH_VISTA_CUERDA, controller) {
	this->editor = editor;

}

ViewSogaFactory::~ViewSogaFactory() {
	// TODO Auto-generated destructor stub
}

} /* namespace std */

View* ViewSogaFactory::crearVistaPropia(int x, int y, int w,int h) {
	return new FactoryView(x,y,w,h, this->textura);
}

FiguraView* ViewSogaFactory::crear(int x, int y, int w, int h) {
	return new SogaView(x, y, w, h, this->textura, this->editor);
}
