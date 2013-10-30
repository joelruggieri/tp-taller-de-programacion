/*
 * ViewBalancinFactory.cpp
 *
 *  Created on: 05/10/2013
 *      Author: joel
 */

#include "ViewBalancinFactory.h"
#include "src/Constantes.h"
#include "../../ConstantesVista.h"
ViewBalancinFactory::ViewBalancinFactory(SimpleEditorAnguloFijo * editor): ViewFiguraFactory(editor) {

}

FiguraView* ViewBalancinFactory::crear(float x, float y, float w, float h) {
	return new BalancinView(x, y, (SimpleEditorAnguloFijo *) this->controller);
}

ViewBalancinFactory::~ViewBalancinFactory() {
	// TODO Auto-generated constructor stub

}

View * ViewBalancinFactory::crearVistaPropia(float x, float y, float w, float h){
	return new FactoryView(x,y);
}

