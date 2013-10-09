/*
 * ViewBalancinFactory.cpp
 *
 *  Created on: 05/10/2013
 *      Author: joel
 */

#include "ViewBalancinFactory.h"
#include "../../vista/CargadorDeTextures.h"
#include "src/Constantes.h"
#include "../../ConstantesVista.h"
ViewBalancinFactory::ViewBalancinFactory(SimpleEditorAnguloFijo * editor): ViewFiguraFactory(PATH_VISTA_BALANCIN_F,editor) {

}

FiguraView* ViewBalancinFactory::crear(int x, int y, int w, int h) {
	Resizer* r = Resizer::Instance();
	int ancho, alto;
	CargadorDeTextures* i = CargadorDeTextures::Instance();
	r->adaptarDimensionLogica(ANCHO_BALANCIN,ALTO_VISTA_BALANCIN_LOG,ancho,alto);
	return new BalancinView(x, y, ancho, alto, i->cargarTexture(PATH_VISTA_BALANCIN),(SimpleEditorAnguloFijo *) this->controller);
}

ViewBalancinFactory::~ViewBalancinFactory() {
	// TODO Auto-generated constructor stub

}

View * ViewBalancinFactory::crearVistaPropia(int x,int y,int ancho,int alto){
	return new FactoryView(x,y,ancho,alto,this->textura );
}

