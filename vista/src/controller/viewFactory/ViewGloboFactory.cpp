/*
 * ViewGloboFactory.cpp
 *
 *  Created on: 20/09/2013
 *      Author: joel
 */

#include "ViewGloboFactory.h"
#include "../../vista/objeto/GloboHelioView.h"
#include "../../controller/editor/SimpleEditorAnguloFijo.h"
#include "src/Constantes.h"
ViewGloboFactory::ViewGloboFactory(SimpleEditorAnguloFijo * editor): ViewFiguraFactory("resource/globo-3-naranja.png", editor)  {


}

ViewGloboFactory::~ViewGloboFactory() {
	// TODO Auto-generated destructor stub
}

FiguraView* ViewGloboFactory::crear(int x, int y, int w, int h) {
	Resizer* r = Resizer::Instance();
	int ancho,alto;
	r->adaptarDimensionLogica(RADIO_GLOBO *2,RADIO_GLOBO *2,ancho,alto);
	return new GloboHelioView(x, y, ancho, alto, this->textura, (SimpleEditorAnguloFijo*)this->controller);
}

View* ViewGloboFactory::crearVistaPropia(int x, int y, int w,
		int h) {
	return new FactoryView(x,y,w,h, this->textura);
}
