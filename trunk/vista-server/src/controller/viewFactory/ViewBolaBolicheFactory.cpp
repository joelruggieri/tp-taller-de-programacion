/*
 * ViewBolaBolicheFactory.cpp
 *
 *  Created on: 06/10/2013
 *      Author: ezequiel
 */

#include "ViewBolaBolicheFactory.h"
#include  "../../vista/objeto/BolaBolicheView.h"
#include "../../controller/editor/SimpleEditorAnguloFijo.h"
#include "src/Constantes.h"
#include "../../ConstantesVista.h"
ViewBolaBolicheFactory::ViewBolaBolicheFactory(SimpleEditorAnguloFijo * editor, int cantidad): ViewFiguraFactory(editor, cantidad) {

}

ViewBolaBolicheFactory::~ViewBolaBolicheFactory() {
	// TODO Auto-generated destructor stub
}

FiguraView* ViewBolaBolicheFactory::crear(float x, float y) {
	return new BolaBolicheView(x, y,(SimpleEditorAnguloFijo*)this->controller);
}

View* ViewBolaBolicheFactory::crearVistaPropia(){
	return new FactoryView();
}

string ViewBolaBolicheFactory::getTagRemoto() {
	return TAG_FACTORY_BOLA;
}

View * ViewBolaBolicheFactory::crearVistaPropia(float,float,float,float){
	return NULL;
}

ViewFiguraFactory* ViewBolaBolicheFactory::clone(int cantidad){
	SimpleEditorAnguloFijo * editor = ((SimpleEditorAnguloFijo*) this->controller);
	editor = (SimpleEditorAnguloFijo *)editor->clone();
	return new ViewBolaBolicheFactory(editor,cantidad);
}
