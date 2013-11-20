/*
 * viewClavoFactory.cpp
 *
 *  Created on: 14/11/2013
 *      Author: ezequiel
 */

#include "viewClavoFactory.h"
#include "src/Constantes.h"
#include "../../ConstantesVista.h"


viewClavoFactory::viewClavoFactory(SimpleEditorAnguloFijo* editor, int cantidad):ViewFiguraFactory(editor, cantidad,ID_FACTORY_CLAVO) {
	// TODO Auto-generated constructor stub

}

viewClavoFactory::~viewClavoFactory() {
	// TODO Auto-generated destructor stub
}

FiguraView* viewClavoFactory::crear(float x, float y) {
	return new ClavoView(x, y, (SimpleEditorAnguloFijo *) this->controller);
}

View* viewClavoFactory::crearVistaPropia() {
	return new FactoryView();
}

string viewClavoFactory::getTagRemoto() {
	return TAG_FACTORY_CLAVO;
}

View* viewClavoFactory::crearVistaPropia(float float1, float float2,
		float float3, float float4) {
	return NULL;
}

ViewFiguraFactory* viewClavoFactory::clone(int cantidad) {
	SimpleEditorAnguloFijo * editor = ((SimpleEditorAnguloFijo*) this->controller);
	editor = (SimpleEditorAnguloFijo *)editor->clone();
	return new viewClavoFactory(editor,cantidad);
}
