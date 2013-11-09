/*
 * ViewBalancinFactory.cpp
 *
 *  Created on: 05/10/2013
 *      Author: joel
 */

#include "ViewBalancinFactory.h"
#include "src/Constantes.h"
#include "../../ConstantesVista.h"
ViewBalancinFactory::ViewBalancinFactory(SimpleEditorAnguloFijo * editor, int cantidad): ViewFiguraFactory(editor, cantidad) {

}

FiguraView* ViewBalancinFactory::crear(float x, float y) {
	return new BalancinView(x, y, (SimpleEditorAnguloFijo *) this->controller);
}

ViewBalancinFactory::~ViewBalancinFactory() {
	// TODO Auto-generated constructor stub

}

View * ViewBalancinFactory::crearVistaPropia(){
	return new FactoryView();
}

string ViewBalancinFactory::getTagRemoto() {
	return TAG_FACTORY_BALANCIN;
}

View * ViewBalancinFactory::crearVistaPropia(float,float,float,float){
	return NULL;
}

ViewFiguraFactory* ViewBalancinFactory::clone(int cantidad){
	return new ViewBalancinFactory((SimpleEditorAnguloFijo *)this->controller,cantidad);
}
