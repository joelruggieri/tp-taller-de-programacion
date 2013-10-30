/*
 * VistaEngranajeFactory.cpp
 *
 *  Created on: 12/10/2013
 *      Author: javier
 */

#include "VistaEngranajeFactory.h"
#include "../editor/SimpleEditorAnguloFijo.h"
#include "../../vista/objeto/VistaEngranaje.h"
#include "../../ConstantesVista.h"
#include "../editor/SimpleEditorCambiarRadio.h"
VistaEngranajeFactory::VistaEngranajeFactory(SimpleEditorCambiarRadio *editor): ViewFiguraFactory(editor) {
	// TODO Auto-generated constructor stub

}

VistaEngranajeFactory::~VistaEngranajeFactory() {
	// TODO Auto-generated destructor stub
}

FiguraView* VistaEngranajeFactory::crear(float x, float y, float w, float h) {
	return new VistaEngranaje(x, y, RADIO_ENGRANAJE, dynamic_cast<SimpleEditorCambiarRadio*>(this->controller));
}

View* VistaEngranajeFactory::crearVistaPropia(float x, float y, float w, float h) {
	return new FactoryView(x,y);
}
