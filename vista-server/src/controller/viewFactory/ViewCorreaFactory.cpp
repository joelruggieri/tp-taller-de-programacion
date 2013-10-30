/*
 * ViewCorreaFactory.cpp
 *
 *  Created on: 15/10/2013
 *      Author: joel
 */

#include "ViewCorreaFactory.h"
#include "../../vista/objeto/CorreaEstaticaView.h"
#include "../../ConstantesVista.h"

ViewCorreaFactory::ViewCorreaFactory(EditorUnion* editor): ViewFiguraFactory(editor) {


}

FiguraView* ViewCorreaFactory::crear(float x, float y, float w, float h){
	return new CorreaEstaticaView(x, y,(EditorUnion*) this->controller);
}

ViewCorreaFactory::~ViewCorreaFactory() {
	// TODO Auto-generated destructor stub
}

View* ViewCorreaFactory::crearVistaPropia(float x, float y, float w, float h) {
	return new FactoryView(x,y);
}

