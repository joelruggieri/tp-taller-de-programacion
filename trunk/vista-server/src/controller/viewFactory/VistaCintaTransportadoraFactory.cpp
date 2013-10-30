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
VistaCintaTransportadoraFactory::VistaCintaTransportadoraFactory(SimpleEditorEstirar* editor) : ViewFiguraFactory(editor) {
}

VistaCintaTransportadoraFactory::~VistaCintaTransportadoraFactory() {
	// TODO Auto-generated destructor stub
}

FiguraView* VistaCintaTransportadoraFactory::crear(float x, float y, float w, float h) {
	return new CintaTransportadoraView(x, y, ANCHO_CINTA,(SimpleEditorEstirar *) this->controller);
}

View* VistaCintaTransportadoraFactory::crearVistaPropia(float x, float y, float w, float h) {
	return new FactoryView(x,y);
}
