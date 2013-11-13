/*
 * ViewYunqueFactory.cpp
 *
 *  Created on: 13/11/2013
 *      Author: ezequiel
 */

#include "ViewYunqueFactory.h"
#include "../../controller/editor/SimpleEditorAnguloFijo.h"
#include "src/Constantes.h"
#include "../../ConstantesVista.h"
#include "../../vista/objeto/YunqueView.h"
ViewYunqueFactory::ViewYunqueFactory(SimpleEditorAnguloFijo * editor, int cantidad) : ViewFiguraFactory(editor, cantidad) {
	// TODO Auto-generated constructor stub

}

ViewYunqueFactory::~ViewYunqueFactory() {
	// TODO Auto-generated destructor stub
}

FiguraView* ViewYunqueFactory::crear(float x, float y) {
	return new YunqueView(x, y, (SimpleEditorAnguloFijo*)this->controller);
}

View* ViewYunqueFactory::crearVistaPropia() {
	return new FactoryView();
}

string ViewYunqueFactory::getTagRemoto() {
	return TAG_FACTORY_YUNQUE;
}

View* ViewYunqueFactory::crearVistaPropia(float float1, float float2,
		float float3, float float4) {
	return NULL;
}

ViewFiguraFactory* ViewYunqueFactory::clone(int cantidad) {
	SimpleEditorAnguloFijo * editor = ((SimpleEditorAnguloFijo*) this->controller);
	editor = (SimpleEditorAnguloFijo *)editor->clone();
	return new ViewYunqueFactory(editor,cantidad);
}
