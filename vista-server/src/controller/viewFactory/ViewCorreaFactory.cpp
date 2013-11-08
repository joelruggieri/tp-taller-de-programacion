/*
 * ViewCorreaFactory.cpp
 *
 *  Created on: 15/10/2013
 *      Author: joel
 */

#include "ViewCorreaFactory.h"
#include "../../vista/objeto/CorreaEstaticaView.h"
#include "../../ConstantesVista.h"

ViewCorreaFactory::ViewCorreaFactory(EditorUnion* editor, int cantidad): ViewFiguraFactory(editor, cantidad) {


}

FiguraView* ViewCorreaFactory::crear(float x, float y){
	return new CorreaEstaticaView(x, y,(EditorUnion*) this->controller);
}

ViewCorreaFactory::~ViewCorreaFactory() {
	// TODO Auto-generated destructor stub
}

View* ViewCorreaFactory::crearVistaPropia(){
	return new FactoryView();
}

string ViewCorreaFactory::getTagRemoto() {
	return TAG_FACTORY_CORREA;
}
