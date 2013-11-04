/*
 * ViewGloboFactory.cpp
 *
 *  Created on: 20/09/2013
 *      Author: joel
 */

#include "ViewGloboFactory.h"
#include "../../vista/objeto/GloboHelioView.h"
#include "../../ConstantesVista.h"
ViewGloboFactory::ViewGloboFactory(): ViewFiguraFactory(PATH_VISTA_GLOBO)  {


}

ViewGloboFactory::~ViewGloboFactory() {
	// TODO Auto-generated destructor stub
}

FiguraView* ViewGloboFactory::crear(int x, int y) {
//	Resizer* r = Resizer::Instance();
//	int ancho,alto;
//	r->adaptarDimensionLogica(RADIO_GLOBO *2,RADIO_GLOBO *2,ancho,alto);
//	return new GloboHelioView(x, y, ancho, alto, this->textura, (SimpleEditorAnguloFijo*)this->controller);
	return NULL;
}

