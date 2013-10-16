/*
 * CorreaView.cpp
 *
 *  Created on: 15/10/2013
 *      Author: joel
 */

#include "CorreaView.h"
#include "../../controller/editor/EditorUnion.h"
#include "src/objeto/Correa.h"

CorreaView::CorreaView(int x, int y, SDL_Texture * textura,EditorUnion* editor,Uint8 r,Uint8 g,Uint8 b): ObjetoView(x, y, 2, 3,textura, editor) { //TODO CREO QUE TENDRIA QUE HARDCODEAR EL W Y EL H
	xDesde = 0;
	yDesde = 0;
	xHasta = 0;
	yHasta = 0;
	color = SDL_Color{r,g,b};

}

CorreaView::~CorreaView() {
	// TODO Auto-generated destructor stub
}

EditorNivel* CorreaView::getEditor(){
	EditorUnion * editor = (EditorUnion *)controller;
	editor->setFigura(this);
	return editor;
}

void CorreaView::dropTemplate(){

}


void CorreaView::dibujarse(SDL_Renderer* renderer){
	SDL_Rect dest;
	dest.h = this->getH();
	dest.w = this->getW();
	dest.x = xHasta;
	dest.y = yHasta;
	SDL_Rect src;
	src.h = this->getH();
	src.w = this->getW();
	src.x = xDesde;
	src.y = yDesde;
	this->dibujarse(renderer, src, dest);
}

void CorreaView::dibujarse(SDL_Renderer* renderer, SDL_Rect& src, SDL_Rect& dest){
	if(this->getModelo() != NULL && this->getModelo()->getRotacion() != 0){
			SDL_RenderCopyEx(renderer,this->getTexture(),&src, &dest,this->getModelo()->getRotacion(),NULL,SDL_FLIP_NONE);
		} else {
			SDL_RenderCopy(renderer,this->getTexture(),&src,&dest);

		}
}

void CorreaView::update(Transformacion & tl){
	super::update(tl);
	Resizer* r = Resizer::Instance();
	Correa* correa = (Correa*)this->getModelo();
	tl.setVector(correa->getXInicial(),correa->getYInicial());
	float xDesde;
	float yDesde;
	tl.getResultadoInverso(xDesde,yDesde);
	int xDesdePixel;
	int yDesdePixel;
	r->adaptarPosicionLogica(xDesde,yDesde,xDesdePixel,yDesdePixel);
	this->setXDesde(xDesdePixel);
	this->setYDesde(yDesdePixel);

	tl.setVector(correa->getXFinal(),correa->getYFinal());
	float xHasta;
	float yHasta;
	tl.getResultadoInverso(xHasta,yHasta);
	int xHastaPixel;
	int yHastaPixel;
	r->adaptarPosicionLogica(xHasta,yHasta,xHastaPixel,yHastaPixel);
	this->setXHasta(xHastaPixel);
	this->setYHasta(yHastaPixel);
}

void CorreaView::setYDesde(int yDesde){
	this->yDesde = yDesde;
}

void CorreaView::setXDesde(int xDesde){
	this->xDesde = xDesde;
}

void CorreaView::setYHasta(int yHasta){
	this->yHasta = yHasta;
}

void CorreaView::setXHasta(int xHasta){
	this->xHasta = xHasta;
}

