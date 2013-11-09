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
VistaEngranajeFactory::VistaEngranajeFactory(SimpleEditorCambiarRadio *editor, int cantidad): ViewFiguraFactory(editor,  cantidad) {
	// TODO Auto-generated constructor stub

}

VistaEngranajeFactory::~VistaEngranajeFactory() {
	// TODO Auto-generated destructor stub
}

FiguraView* VistaEngranajeFactory::crear(float x, float y) {
	return new VistaEngranaje(x, y, RADIO_ENGRANAJE, dynamic_cast<SimpleEditorCambiarRadio*>(this->controller));
}

View* VistaEngranajeFactory::crearVistaPropia(){
	return new FactoryView();
}

string VistaEngranajeFactory::getTagRemoto() {
	return TAG_FACTORY_ENGRANAJE;
}

View * VistaEngranajeFactory::crearVistaPropia(float,float,float,float){
	return NULL;
}

ViewFiguraFactory* VistaEngranajeFactory::clone(int cantidad){
	SimpleEditorCambiarRadio * editor = ((SimpleEditorCambiarRadio*) this->controller);
	editor = (SimpleEditorCambiarRadio *)editor->clone();
	return new VistaEngranajeFactory(editor,cantidad);
}
