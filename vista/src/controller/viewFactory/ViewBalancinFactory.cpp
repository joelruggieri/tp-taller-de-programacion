/*
 * ViewBalancinFactory.cpp
 *
 *  Created on: 05/10/2013
 *      Author: joel
 */

#include "ViewBalancinFactory.h"
#include "../../vista/CargadorDeTextures.h"

#include "../../ConstantesVista.h"
#include "../../vista/objeto/BalancinView.h"
ViewBalancinFactory::ViewBalancinFactory(): ViewFiguraFactory(PATH_VISTA_BALANCIN_F) {

}

FiguraView* ViewBalancinFactory::crear(int x, int Y) {
//	Resizer* r = Resizer::Instance();
//	int ancho, alto;
//	CargadorDeTextures* i = CargadorDeTextures::Instance();
//	r->adaptarDimensionLogica(ANCHO_BALANCIN,ALTO_VISTA_BALANCIN_LOG,ancho,alto);
//	return new BalancinView(x, y, ancho, alto, i->cargarTexture(PATH_VISTA_BALANCIN));
	return NULL;
}

ViewBalancinFactory::~ViewBalancinFactory() {
	// TODO Auto-generated constructor stub
}


