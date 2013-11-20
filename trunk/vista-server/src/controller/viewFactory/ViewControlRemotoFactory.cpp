/*
 * ViewControlRemotoFactory.cpp
 *
 *  Created on: 17/11/2013
 *      Author: ezequiel
 */

#include "ViewControlRemotoFactory.h"
#include  "../../vista/objeto/PelotaJuegoView.h"
#include "../../controller/editor/SimpleEditorAnguloFijo.h"
#include "src/Constantes.h"
#include "../../ConstantesVista.h"
ViewControlRemotoFactory::ViewControlRemotoFactory(SimpleEditorAnguloFijo * editor, int cantidad) : ViewFiguraFactory(editor, cantidad,ID_FACTORY_CONTROL)  {
	// TODO Auto-generated constructor stub

}

ViewControlRemotoFactory::~ViewControlRemotoFactory() {
	// TODO Auto-generated destructor stub
}

FiguraView* ViewControlRemotoFactory::crear(float x, float y) {
	return new ControlRemotoView(x, y, (SimpleEditorAnguloFijo*)this->controller);
}

View* ViewControlRemotoFactory::crearVistaPropia() {
	return new FactoryView();
}

string ViewControlRemotoFactory::getTagRemoto() {
	return TAG_FACTORY_CONTROL;
}

View* ViewControlRemotoFactory::crearVistaPropia(float float1, float float2,
		float float3, float float4) {
	return NULL;
}

ViewFiguraFactory* ViewControlRemotoFactory::clone(int cantidad) {
	SimpleEditorAnguloFijo * editor = ((SimpleEditorAnguloFijo*) this->controller);
	editor = (SimpleEditorAnguloFijo *)editor->clone();
	return new ViewControlRemotoFactory(editor,cantidad);
}
