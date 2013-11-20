/*
 * ViewBombaFactory.cpp
 *
 *  Created on: 17/11/2013
 *      Author: ezequiel
 */

#include "ViewBombaFactory.h"
#include "../../vista/objeto/PelotaJuegoView.h"
#include "../../controller/editor/SimpleEditorAnguloFijo.h"
#include "src/Constantes.h"
#include "../../ConstantesVista.h"
ViewBombaFactory::ViewBombaFactory(SimpleEditorAnguloFijo * editor, int cantidad) : ViewFiguraFactory(editor, cantidad,ID_FACTORY_BOMBA) {

}

ViewBombaFactory::~ViewBombaFactory() {
	// TODO Auto-generated destructor stub
}

FiguraView* ViewBombaFactory::crear(float x, float y) {
	return new BombaView(x,y, (SimpleEditorAnguloFijo*)this->controller);
}

View* ViewBombaFactory::crearVistaPropia() {
	return new FactoryView();
}

string ViewBombaFactory::getTagRemoto() {
	return TAG_FACTORY_BOMBA;
}

View* ViewBombaFactory::crearVistaPropia(float float1, float float2,
		float float3, float float4) {
	return NULL;
}

ViewFiguraFactory* ViewBombaFactory::clone(int cantidad) {
	SimpleEditorAnguloFijo * editor = ((SimpleEditorAnguloFijo*) this->controller);
	editor = (SimpleEditorAnguloFijo *)editor->clone();
	return new ViewBombaFactory(editor,cantidad);
}
