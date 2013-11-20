/*
 * ViewCarritoFactory.cpp
 *
 *  Created on: 14/11/2013
 *      Author: joel
 */

#include "ViewCarritoFactory.h"
#include "src/Constantes.h"
#include "../../ConstantesVista.h"
ViewCarritoFactory::ViewCarritoFactory(SimpleEditorNivel* editor, int cantidad): ViewFiguraFactory(editor, cantidad, ID_FACTORY_CARRITO) {

}

FiguraView* ViewCarritoFactory::crear(float x, float y) {
	return new CarritoView(x, y, (SimpleEditorNivel*) this->controller);
}

ViewCarritoFactory::~ViewCarritoFactory() {
	// TODO Auto-generated destructor stub
}

View * ViewCarritoFactory::crearVistaPropia(){
	return new FactoryView();
}

string ViewCarritoFactory::getTagRemoto() {
	return TAG_FACTORY_CARRITO;
}

View * ViewCarritoFactory::crearVistaPropia(float x,float y,float ancho ,float alto){
	return NULL;
}

ViewFiguraFactory* ViewCarritoFactory::clone(int cantidad){
	SimpleEditorNivel* editor = ((SimpleEditorNivel*) this->controller);
	editor = (SimpleEditorNivel*)editor->clone();
	return new ViewCarritoFactory(editor,cantidad);
}

