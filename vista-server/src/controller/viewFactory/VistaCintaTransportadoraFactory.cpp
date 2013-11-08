/*
 * VistaCintaTransportadoraFactory.cpp
 *
 *  Created on: 05/10/2013
 *      Author: javier
 */

#include "VistaCintaTransportadoraFactory.h"
#include "../../ConstantesVista.h"
#include "../../vista/objeto/CintaTransportadoraView.h"
#include "../editor/SimpleEditorEstirar.h"
#include "src/Constantes.h"
VistaCintaTransportadoraFactory::VistaCintaTransportadoraFactory(SimpleEditorEstirar* editor, int cantidad) : ViewFiguraFactory(editor, cantidad) {
}

VistaCintaTransportadoraFactory::~VistaCintaTransportadoraFactory() {
	// TODO Auto-generated destructor stub
}

FiguraView* VistaCintaTransportadoraFactory::crear(float x, float y) {
	return new CintaTransportadoraView(x, y, ANCHO_CINTA,(SimpleEditorEstirar *) this->controller);
}

View* VistaCintaTransportadoraFactory::crearVistaPropia(){
	return new FactoryView();
}

string VistaCintaTransportadoraFactory::getTagRemoto() {
	return TAG_FACTORY_CINTA;
}
