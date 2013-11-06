/*
 * ViewPelotaJuegoFactory.cpp
 *
 *  Created on: 06/10/2013
 *      Author: ezequiel
 */

#include "ViewPelotaJuegoFactory.h"
#include  "../../vista/objeto/PelotaJuegoView.h"
#include "../../ConstantesVista.h"


namespace CLIENTE {

ViewPelotaJuegoFactory::ViewPelotaJuegoFactory() : ViewFiguraFactory(PATH_VISTA_PELOTA) {
	// TODO Auto-generated constructor stub

}

ViewPelotaJuegoFactory::~ViewPelotaJuegoFactory() {
	// TODO Auto-generated destructor stub
}

FiguraView* ViewPelotaJuegoFactory::crear(int x, int y) {
//	Resizer* r = Resizer::Instance();
//	int ancho, alto;
//	r->adaptarDimensionLogica(RADIO_PELOTA*2,RADIO_PELOTA*2,ancho,alto);
//	return new PelotaJuegoView(x, y, ancho, alto, this->textura, (SimpleEditorAnguloFijo*)this->controller);
	return NULL;
}

}
