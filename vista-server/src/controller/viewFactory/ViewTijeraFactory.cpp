/*
 * ViewTijeraFactory.cpp
 *
 *  Created on: 16/11/2013
 *      Author: joel
 */

#include "ViewTijeraFactory.h"

ViewTijeraFactory::ViewTijeraFactory(SimpleEditorAnguloFijo* editor, int cantidad): ViewFiguraFactory(editor, cantidad) {

}

ViewTijeraFactory::~ViewTijeraFactory() {
	// TODO Auto-generated destructor stub
}

FiguraView* ViewTijeraFactory::crear(float x, float y) {
	return new TijeraView(x, y, (SimpleEditorAnguloFijo*) this->controller);
}

View * ViewTijeraFactory::crearVistaPropia(){
	return new FactoryView();
}

string ViewTijeraFactory::getTagRemoto() {
	return TAG_FACTORY_TIJERA;
}

View * ViewTijeraFactory::crearVistaPropia(float x,float y,float ancho,float alto){
	return NULL;
}

ViewFiguraFactory* ViewTijeraFactory::clone(int cantidad){
	SimpleEditorAnguloFijo* editor = ((SimpleEditorAnguloFijo*) this->controller);
	editor = (SimpleEditorAnguloFijo*)editor->clone();
	return new ViewTijeraFactory(editor,cantidad);
}
