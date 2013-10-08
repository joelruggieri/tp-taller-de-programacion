/*
 * ViewBalancinFactory.cpp
 *
 *  Created on: 05/10/2013
 *      Author: joel
 */

#include "ViewBalancinFactory.h"

ViewBalancinFactory::ViewBalancinFactory(SimpleEditorAnguloFijo * editor): ViewFiguraFactory("resource/barra.png",editor) {

}

FiguraView* ViewBalancinFactory::crear(int x, int y, int w, int h) {
	Resizer* r = Resizer::Instance();
	float anchoHardcodeado = 50;
	float  altoHardcodeado = 25;
	int ancho = 0;
	int alto = 0;
	r->adaptarDimensionLogica(anchoHardcodeado,altoHardcodeado,ancho,alto);
	return new BalancinView(x, y, ancho, alto, this->textura,(SimpleEditorAnguloFijo *) this->controller);
}

ViewBalancinFactory::~ViewBalancinFactory() {
	// TODO Auto-generated constructor stub

}

View * ViewBalancinFactory::crearVistaPropia(int x,int y,int ancho,int alto){
	return new FactoryView(x,y,ancho,alto, this->textura);
}

