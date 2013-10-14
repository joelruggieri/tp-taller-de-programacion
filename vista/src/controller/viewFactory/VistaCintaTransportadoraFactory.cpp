/*
 * VistaCintaTransportadoraFactory.cpp
 *
 *  Created on: 05/10/2013
 *      Author: javier
 */

#include "VistaCintaTransportadoraFactory.h"
#include "../../ConstantesVista.h"
#include "../editor/EditorDeEstiramientoDeCinta.h"

VistaCintaTransportadoraFactory::VistaCintaTransportadoraFactory(EditorDeEstiramientoDeCinta* editor) : ViewFiguraFactory(PATH_VISTA_CINTA, editor) {
}

VistaCintaTransportadoraFactory::~VistaCintaTransportadoraFactory() {
	// TODO Auto-generated destructor stub
}

FiguraView* VistaCintaTransportadoraFactory::crear(int x, int y, int w, int h) {
	Resizer * r = Resizer::Instance();
	int ancho,alto;
	r->adaptarDimensionLogica(LONGITUD_CINTA + 2.0f * RADIO_EJE_CINTA_LOG, RADIO_EJE_CINTA_LOG * 10.0f, ancho,alto);
	return new VistaCintaTransportadora(x, y, ancho, alto, this->textura, dynamic_cast<EditorDeEstiramientoDeCinta*>(this->controller));
}

View* VistaCintaTransportadoraFactory::crearVistaPropia(int x, int y,
		int w, int h) {
	return new FactoryView(x,y,w,h, this->textura);
}
