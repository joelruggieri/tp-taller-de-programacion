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
VistaCintaTransportadoraFactory::VistaCintaTransportadoraFactory(SimpleEditorEstirar* editor) : ViewFiguraFactory(PATH_VISTA_CINTA, editor) {
}

VistaCintaTransportadoraFactory::~VistaCintaTransportadoraFactory() {
	// TODO Auto-generated destructor stub
}

FiguraView* VistaCintaTransportadoraFactory::crear(int x, int y, int w, int h) {
	Resizer * r = Resizer::Instance();
	int ancho,alto,altoModelo;
	r->adaptarDimensionLogica(ANCHO_CINTA,ALTO_VISTA_CINTA_LOG,ancho,alto);
	altoModelo = r->resizearDistanciaLogicaY(ALTO_CINTA);
	return new CintaTransportadoraView(x, y, ancho, alto,altoModelo,this->textura, (SimpleEditorEstirar *) this->controller);
}

View* VistaCintaTransportadoraFactory::crearVistaPropia(int x, int y,
		int w, int h) {
	return new FactoryView(x,y,w,h, this->textura);
}
