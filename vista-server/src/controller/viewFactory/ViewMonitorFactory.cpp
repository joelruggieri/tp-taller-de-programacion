/*
 * ViewMonitorFactory.cpp
 *
 *  Created on: 06/10/2013
 *      Author: ezequiel
 */

#include "ViewMonitorFactory.h"
#include  "../../vista/objeto/MonitorView.h"
#include "../../controller/editor/SimpleEditorAnguloFijo.h"
#include "src/Constantes.h"
#include "../../ConstantesVista.h"
ViewMonitorFactory::ViewMonitorFactory(SimpleEditorAnguloFijo * editor, int cantidad) : ViewFiguraFactory(editor, cantidad,ID_FACTORY_PELOTA) {
	// TODO Auto-generated constructor stub

}

ViewMonitorFactory::~ViewMonitorFactory() {
	// TODO Auto-generated destructor stub
}

FiguraView* ViewMonitorFactory::crear(float x, float y) {
	return new MonitorView(x, y, (SimpleEditorAnguloFijo*)this->controller);
}

View* ViewMonitorFactory::crearVistaPropia(){
	return new FactoryView();
}

string ViewMonitorFactory::getTagRemoto() {
	return TAG_FACTORY_PELOTA;
}

View * ViewMonitorFactory::crearVistaPropia(float,float,float,float){
	return NULL;
}

ViewFiguraFactory* ViewMonitorFactory::clone(int cantidad){
	SimpleEditorAnguloFijo * editor = ((SimpleEditorAnguloFijo*) this->controller);
	editor = (SimpleEditorAnguloFijo *)editor->clone();
	return new ViewMonitorFactory(editor,cantidad);
}


