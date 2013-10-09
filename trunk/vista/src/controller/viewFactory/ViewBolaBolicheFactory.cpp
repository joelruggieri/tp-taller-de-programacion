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
#include "src/Constantes.h"
#include "../../ConstantesVista.h"
ViewBolaBolicheFactory::ViewBolaBolicheFactory(SimpleEditorAnguloFijo * editor): ViewFiguraFactory(PATH_VISTA_BOLA, editor) {

}

ViewBolaBolicheFactory::~ViewBolaBolicheFactory() {
	// TODO Auto-generated destructor stub
}

FiguraView* ViewBolaBolicheFactory::crear(int x, int y, int w,
		int h) {
	Resizer* r = Resizer::Instance();
	int ancho,alto;
	r->adaptarDimensionLogica(RADIO_BOLA *2,RADIO_BOLA *2,ancho,alto);
	return new BolaBolicheView(x, y, ancho, alto, this->textura, (SimpleEditorAnguloFijo*)this->controller);
}

View* ViewBolaBolicheFactory::crearVistaPropia(int x, int y, int h,
		int w) {
	return new FactoryView(x,y,w,h, this->textura);
}
