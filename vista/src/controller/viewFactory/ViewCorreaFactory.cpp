/*
 * ViewCorreaFactory.cpp
 *
 *  Created on: 15/10/2013
 *      Author: joel
 */

#include "ViewCorreaFactory.h"
#include "../../vista/objeto/CorreaView.h"
#include "../../ConstantesVista.h"

ViewCorreaFactory::ViewCorreaFactory(SimpleEditorSoga* editor): ViewFiguraFactory(PATH_VISTA_CORREA,editor) {


}

FiguraView* ViewCorreaFactory::crear(int x,int y,int w, int h){
	Uint8 r = 0;
	Uint8 g = 0;
	Uint8 b = 0;
	return new CorreaView(x, y,this->textura, (SimpleEditorSoga*) this->controller,r,g,b);
}

ViewCorreaFactory::~ViewCorreaFactory() {
	// TODO Auto-generated destructor stub
}

View* ViewCorreaFactory::crearVistaPropia(int x, int y, int w,int h) {
	return new FactoryView(x,y,w,h, this->textura);
}

