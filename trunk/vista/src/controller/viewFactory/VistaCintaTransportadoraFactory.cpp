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
#include "../../vista/CargadorDeTextures.h"
VistaCintaTransportadoraFactory::VistaCintaTransportadoraFactory(SimpleEditorEstirar* editor) : ViewFiguraFactory(PATH_VISTA_CINTA, editor) {
}

VistaCintaTransportadoraFactory::~VistaCintaTransportadoraFactory() {
	// TODO Auto-generated destructor stub
}

FiguraView* VistaCintaTransportadoraFactory::crear(int x, int y, int w, int h) {
	Resizer * r = Resizer::Instance();
	int ancho,alto,altoModelo,altoPlataforma;
	r->adaptarDimensionLogica(ANCHO_CINTA,ALTO_VISTA_CINTA_LOG,ancho,alto);
	altoModelo = r->resizearDistanciaLogicaY(ALTO_CINTA);
	altoPlataforma = r->resizearDistanciaLogicaY(ALTO_VISTA_CINTA_RAMPA_LOG);
	SDL_Texture* texturaBase = CargadorDeTextures::Instance()->cargarTexture(PATH_VISTA_CINTA_PLATAF);
	return new CintaTransportadoraView(x, y, ancho, altoModelo,altoModelo, altoPlataforma,texturaBase, (SimpleEditorEstirar *) this->controller);
}

View* VistaCintaTransportadoraFactory::crearVistaPropia(int x, int y,
		int w, int h) {
	return new FactoryView(x,y,w,h, this->textura);
}
