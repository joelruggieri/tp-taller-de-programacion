/*
 * ViewBalancinFactory.cpp
 *
 *  Created on: 05/10/2013
 *      Author: joel
 */

#include "ViewBalancinFactory.h"

ViewBalancinFactory::ViewBalancinFactory(SimpleEditorAnguloFijo * editor): ViewFiguraFactory("resource/arco.png",editor) {

}

FiguraView* ViewBalancinFactory::crear(int x, int y, int w, int h) {
	Resizer* r = Resizer::Instance();
	float anchoHardcodeado = 30;
	float  aux = 0;
	int ancho = 0;
	int aux2 = 0;
	r->adaptarDimensionLogica(anchoHardcodeado,aux,ancho,aux2);
	return new BalancinView(x, y, ancho, h, this->textura,(SimpleEditorAnguloFijo *) this->controller);
}

ViewBalancinFactory::~ViewBalancinFactory() {
	// TODO Auto-generated constructor stub

}

View * ViewBalancinFactory::crearVistaPropia(int x,int y,int ancho,int alto){
	return new FactoryView(x,y,ancho,alto, this->textura);
}

