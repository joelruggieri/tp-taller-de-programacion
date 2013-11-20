/*
 * ViewGloboFactory.cpp
 *
 *  Created on: 20/09/2013
 *      Author: joel
 */

#include "ViewGloboFactory.h"
#include "../../vista/objeto/GloboHelioView.h"
#include "../../controller/editor/SimpleEditorAnguloFijo.h"
#include "src/Constantes.h"
#include "../../ConstantesVista.h"
ViewGloboFactory::ViewGloboFactory(SimpleEditorAnguloFijo * editor, int cantidad): ViewFiguraFactory(editor, cantidad,ID_FACTORY_GLOBO)  {


}

ViewGloboFactory::~ViewGloboFactory() {
	// TODO Auto-generated destructor stub
}

FiguraView* ViewGloboFactory::crear(float x, float y) {
	return new GloboHelioView(x, y, (SimpleEditorAnguloFijo*)this->controller);
}

View* ViewGloboFactory::crearVistaPropia(){
	return new FactoryView();
}

string ViewGloboFactory::getTagRemoto() {
	return TAG_FACTORY_GLOBO;
}

View * ViewGloboFactory::crearVistaPropia(float,float,float,float){
	return NULL;
}

ViewFiguraFactory* ViewGloboFactory::clone(int cantidad){
	SimpleEditorAnguloFijo * editor = ((SimpleEditorAnguloFijo*) this->controller);
	editor = (SimpleEditorAnguloFijo *)editor->clone();
	return new ViewGloboFactory(editor,cantidad);
}
