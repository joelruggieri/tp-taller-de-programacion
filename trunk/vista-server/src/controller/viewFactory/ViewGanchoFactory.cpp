/*
 * ViewGanchoFactory.cpp
 *
 *  Created on: 13/11/2013
 *      Author: joel
 */

#include "ViewGanchoFactory.h"
#include "../../vista/objeto/GanchoView.h"
#include "../../controller/editor/SimpleEditorAnguloFijo.h"
#include "src/Constantes.h"
#include "../../ConstantesVista.h"

ViewGanchoFactory::ViewGanchoFactory(SimpleEditorAnguloFijo * editor, int cantidad): ViewFiguraFactory(editor, cantidad, ID_FACTORY_GANCHO) {

}

ViewGanchoFactory::~ViewGanchoFactory() {
	// TODO Auto-generated destructor stub
}

FiguraView* ViewGanchoFactory::crear(float x, float y) {
	return new GanchoView(x, y,(SimpleEditorAnguloFijo*)this->controller);
}

View* ViewGanchoFactory::crearVistaPropia(){
	return new FactoryView();
}

string ViewGanchoFactory::getTagRemoto() {
	return TAG_FACTORY_GANCHO;
}

View * ViewGanchoFactory::crearVistaPropia(float,float,float,float){
	return NULL;
}

ViewFiguraFactory* ViewGanchoFactory::clone(int cantidad){
	SimpleEditorAnguloFijo * editor = ((SimpleEditorAnguloFijo*) this->controller);
	editor = (SimpleEditorAnguloFijo *)editor->clone();
	return new ViewGanchoFactory(editor,cantidad);
}

