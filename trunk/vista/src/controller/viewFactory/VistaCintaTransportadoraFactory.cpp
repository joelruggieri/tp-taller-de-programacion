/*
 * VistaCintaTransportadoraFactory.cpp
 *
 *  Created on: 05/10/2013
 *      Author: javier
 */

#include "VistaCintaTransportadoraFactory.h"
#include "../../ConstantesVista.h"
#include "../../vista/objeto/CintaTransportadoraView.h"
#include "../../vista/CargadorDeTextures.h"


namespace CLIENTE {
VistaCintaTransportadoraFactory::VistaCintaTransportadoraFactory() : ViewFiguraFactory(PATH_VISTA_CINTA) {
}

VistaCintaTransportadoraFactory::~VistaCintaTransportadoraFactory() {
	// TODO Auto-generated destructor stub
}

FiguraView* VistaCintaTransportadoraFactory::crear(int x, int y) {
//	Resizer * r = Resizer::Instance();
//	int ancho,alto,altoModelo,altoPlataforma;
//	r->adaptarDimensionLogica(ANCHO_CINTA,ALTO_VISTA_CINTA_LOG,ancho,alto);
//	altoModelo = r->resizearDistanciaLogicaY(ALTO_CINTA);
//	altoPlataforma = r->resizearDistanciaLogicaY(ALTO_VISTA_CINTA_RAMPA_LOG);
//	SDL_Texture* texturaBase = CargadorDeTextures::Instance()->cargarTexture(PATH_VISTA_CINTA_PLATAF);
//	return new CintaTransportadoraView(x, y, ancho, altoModelo,altoModelo, altoPlataforma,texturaBase);
	return NULL;
}

}
