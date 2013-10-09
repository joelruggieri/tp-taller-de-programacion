/*
 * ViewGloboFactory.cpp
 *
 *  Created on: 20/09/2013
 *      Author: joel
 */

#include "ViewGloboFactory.h"
#include "../../vista/objeto/GloboHelioView.h"
#include "../../controller/editor/SimpleEditorAnguloFijo.h"

ViewGloboFactory::ViewGloboFactory(SimpleEditorAnguloFijo * editor): ViewFiguraFactory("resource/globo-3-naranja.png", editor)  {


}

ViewGloboFactory::~ViewGloboFactory() {
	// TODO Auto-generated destructor stub
}

FiguraView* ViewGloboFactory::crear(int x, int y, int w, int h) {
	Resizer* r = Resizer::Instance();
	float anchoHardcodeado = 4;
	float  altoHardcodeado = 4;
	int ancho = 0;
	int alto = 0;
	r->adaptarDimensionLogica(anchoHardcodeado,altoHardcodeado,ancho,alto);
	return new GloboHelioView(x, y, ancho, alto, this->textura, (SimpleEditorAnguloFijo*)this->controller);
}

View* ViewGloboFactory::crearVistaPropia(int x, int y, int w,
		int h) {
	return new FactoryView(x,y,w,h, this->textura);
}
