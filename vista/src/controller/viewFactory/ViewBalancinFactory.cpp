/*
 * ViewBalancinFactory.cpp
 *
 *  Created on: 05/10/2013
 *      Author: joel
 */

#include "ViewBalancinFactory.h"
#include "../../vista/CargadorDeTextures.h"
ViewBalancinFactory::ViewBalancinFactory(SimpleEditorAnguloFijo * editor): ViewFiguraFactory("resource/barra_f.png",editor) {

}

FiguraView* ViewBalancinFactory::crear(int x, int y, int w, int h) {
	Resizer* r = Resizer::Instance();
	float anchoHardcodeado = 34;
	float  altoHardcodeado = 4;
	int ancho = 0;
	int alto = 0;
	CargadorDeTextures* i = CargadorDeTextures::Instance();
	r->adaptarDimensionLogica(anchoHardcodeado,altoHardcodeado,ancho,alto);
	return new BalancinView(x, y, ancho, alto, i->cargarTexture("resource/barra.png"),(SimpleEditorAnguloFijo *) this->controller);
}

ViewBalancinFactory::~ViewBalancinFactory() {
	// TODO Auto-generated constructor stub

}

View * ViewBalancinFactory::crearVistaPropia(int x,int y,int ancho,int alto){
	return new FactoryView(x,y,ancho,alto,this->textura );
}

