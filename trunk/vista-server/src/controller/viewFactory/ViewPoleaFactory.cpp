/*
 * ViewPoleaFactory.cpp
 *
 *  Created on: 13/11/2013
 *      Author: joel
 */

#include "ViewPoleaFactory.h"
#include "../../vista/objeto/PoleaView.h"
#include "../../controller/editor/SimpleEditorAnguloFijo.h"
#include "src/Constantes.h"
#include "../../ConstantesVista.h"

ViewPoleaFactory::ViewPoleaFactory(SimpleEditorAnguloFijo * editor, int cantidad): ViewFiguraFactory(editor, cantidad) {

}

ViewPoleaFactory::~ViewPoleaFactory() {
	// TODO Auto-generated destructor stub
}

FiguraView* ViewPoleaFactory::crear(float x, float y) {
	return new PoleaView(x, y,(SimpleEditorAnguloFijo*)this->controller);
}

View* ViewPoleaFactory::crearVistaPropia(){
	return new FactoryView();
}

string ViewPoleaFactory::getTagRemoto() {
	return TAG_FACTORY_POLEA;
}

View * ViewPoleaFactory::crearVistaPropia(float,float,float,float){
	return NULL;
}

ViewFiguraFactory* ViewPoleaFactory::clone(int cantidad){
	SimpleEditorAnguloFijo * editor = ((SimpleEditorAnguloFijo*) this->controller);
	editor = (SimpleEditorAnguloFijo *)editor->clone();
	return new ViewPoleaFactory(editor,cantidad);
}

