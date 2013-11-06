/*
 * ViewBolaBolicheFactory.cpp
 *
 *  Created on: 06/10/2013
 *      Author: ezequiel
 */

#include "ViewBolaBolicheFactory.h"
#include  "../../vista/objeto/BolaBolicheView.h"
#include "../Resizer.h"
#include "../../ConstantesVista.h"

namespace CLIENTE {
ViewBolaBolicheFactory::ViewBolaBolicheFactory() :
		ViewFiguraFactory(PATH_VISTA_BOLA) {

}

ViewBolaBolicheFactory::~ViewBolaBolicheFactory() {
	// TODO Auto-generated destructor stub
}

FiguraView* ViewBolaBolicheFactory::crear(int x, int y) {
//	Resizer* r = Resizer::Instance();
//	int ancho,alto;
//	r->adaptarDimensionLogica(RADIO_BOLA *2,RADIO_BOLA *2,ancho,alto);
//	return new BolaBolicheView(x, y, ancho, alto, this->textura);
	return NULL;
}

}
