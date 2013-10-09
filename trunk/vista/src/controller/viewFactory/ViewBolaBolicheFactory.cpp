/*
 * ViewBolaBolicheFactory.cpp
 *
 *  Created on: 06/10/2013
 *      Author: ezequiel
 */

#include "ViewBolaBolicheFactory.h"
#include  "../../vista/objeto/BolaBolicheView.h"
#include "../../controller/editor/SimpleEditorAnguloFijo.h"
#include "../Resizer.h"
ViewBolaBolicheFactory::ViewBolaBolicheFactory(SimpleEditorAnguloFijo * editor): ViewFiguraFactory("resource/bolaBoliche.png", editor) {

}

ViewBolaBolicheFactory::~ViewBolaBolicheFactory() {
	// TODO Auto-generated destructor stub
}

FiguraView* ViewBolaBolicheFactory::crear(int x, int y, int w,
		int h) {
	Resizer* r = Resizer::Instance();
	float anchoHardcodeado = 6;
	float  altoHardcodeado = 6;
	int ancho = 0;
	int alto = 0;
	r->adaptarDimensionLogica(anchoHardcodeado,altoHardcodeado,ancho,alto);
	return new BolaBolicheView(x, y, ancho, alto, this->textura, (SimpleEditorAnguloFijo*)this->controller);
}

View* ViewBolaBolicheFactory::crearVistaPropia(int x, int y, int h,
		int w) {
	return new FactoryView(x,y,w,h, this->textura);
}
