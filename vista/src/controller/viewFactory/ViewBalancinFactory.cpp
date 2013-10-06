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
	return new BalancinView(x, y, 250, h, this->textura,(SimpleEditorAnguloFijo *) this->controller);
}

ViewBalancinFactory::~ViewBalancinFactory() {
	// TODO Auto-generated constructor stub

}

View * ViewBalancinFactory::crearVistaPropia(int x,int y,int ancho,int alto){
	return new FactoryView(x,y,ancho,alto, this->textura);
}

