/*
 * UnionView.cpp
 *
 *  Created on: 16/10/2013
 *      Author: jonathan
 */

#include "UnionView.h"
#include "SDL2/SDL.h"
#include "../../controller/editor/EditorUnion.h"
#include "src/objeto/Union.h"
UnionView::UnionView(int x,int y, SDL_Texture * textura, EditorUnion * controller):ObjetoView(x,y,20,20,textura, controller) {
	xDesde = 0;
	yDesde = 0;
	xHasta = 0;
	yHasta = 0;
}

UnionView::~UnionView() {
	// TODO Auto-generated destructor stub
}

void UnionView::dibujarse(SDL_Renderer* ren, Uint8 r, Uint8 g, Uint8 b) {
		//TODO SETEAR EL COLOR AL RENDERER Y HACER EL DRAWLINE.
}

EditorNivel* UnionView::getEditor() {
	return (EditorNivel*)this->controller;
}

void UnionView::update(Transformacion & tl){
	super::update(tl);
	Resizer* r = Resizer::Instance();
	Union* un = (Union*)this->getModelo();
	tl.setVector(un->getXInicial(),un->getYInicial());
	float xDesde;
	float yDesde;
	tl.getResultadoInverso(xDesde,yDesde);
	int xDesdePixel;
	int yDesdePixel;
	r->adaptarPosicionLogica(xDesde,yDesde,xDesdePixel,yDesdePixel);
	xDesde = xDesdePixel;
	yDesde = yDesdePixel;
	tl.setVector(un->getXFinal(),un->getYFinal());
	float xHasta;
	float yHasta;
	tl.getResultadoInverso(xHasta,yHasta);
	int xHastaPixel;
	int yHastaPixel;
	r->adaptarPosicionLogica(xHasta,yHasta,xHastaPixel,yHastaPixel);
	xHasta =xHastaPixel;
	yHasta =yHastaPixel;
}
