/*
 * VistaCintaTransportadoraFactory.cpp
 *
 *  Created on: 05/10/2013
 *      Author: javier
 */

#include "VistaCintaTransportadoraFactory.h"
#include "../../ConstantesVista.h"

VistaCintaTransportadoraFactory::VistaCintaTransportadoraFactory(SimpleEditorAnguloFijo* editor) : ViewFiguraFactory(PATH_VISTA_CINTA, editor) {
}

VistaCintaTransportadoraFactory::~VistaCintaTransportadoraFactory() {
	// TODO Auto-generated destructor stub
}

FiguraView* VistaCintaTransportadoraFactory::crear(int x, int y, int w,
		int h) {
	Resizer * r = Resizer::Instance();
	return new VistaCintaTransportadora(x, y, r->resizearDistanciaLogicaX(20), h, this->textura, (SimpleEditorAnguloFijo*)this->controller);
}

View* VistaCintaTransportadoraFactory::crearVistaPropia(int x, int y,
		int w, int h) {
	return new FactoryView(x,y,w,h, this->textura);
}
