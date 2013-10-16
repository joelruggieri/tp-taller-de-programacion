/*
 * ViewCorreaFactory.cpp
 *
 *  Created on: 15/10/2013
 *      Author: joel
 */

#include "ViewCorreaFactory.h"
#include "../../vista/objeto/CorreaView.h"
#include "../../ConstantesVista.h"

ViewCorreaFactory::ViewCorreaFactory(EditorUnion* editor): ViewFiguraFactory(PATH_VISTA_CORREA,editor) {


}

FiguraView* ViewCorreaFactory::crear(int x,int y,int w, int h){
	return new CorreaView(x, y,this->textura, (EditorUnion*) this->controller);
}

ViewCorreaFactory::~ViewCorreaFactory() {
	// TODO Auto-generated destructor stub
}

View* ViewCorreaFactory::crearVistaPropia(int x, int y, int w,int h) {
	return new FactoryView(x,y,w,h, this->textura);
}

