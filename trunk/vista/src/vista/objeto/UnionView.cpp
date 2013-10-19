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
//	if(getModelo() != NULL){
//		getModelo()->removeObserver(this);
//	}
}

void UnionView::dibujarse(SDL_Renderer* ren, Uint8 r, Uint8 g, Uint8 b) {
	SDL_SetRenderDrawColor(ren,r,g,b,0);
	SDL_RenderDrawLine(ren,this->xDesde,this->yDesde,this->xHasta,this->yHasta);
}

EditorNivel* UnionView::getEditor() {
	return (EditorNivel*)this->controller;
}

void UnionView::update(){
	super::update();
	Union* un = (Union*)this->getModelo();
	tl.setVector(un->getXInicial(),un->getYInicial());
	float xDesde;
	float yDesde;
	tl.getResultadoInverso(xDesde,yDesde);
	this->xDesde = xDesde;
	this->yDesde = yDesde;
	tl.setVector(un->getXFinal(),un->getYFinal());
	float xHasta;
	float yHasta;
	tl.getResultadoInverso(xHasta,yHasta);
	this->xHasta =xHasta;
	this->yHasta =yHasta;
}

void UnionView::setModelo(Figura* f) {
//	f->addObserver(this);
	super::setModelo(f);
}

void UnionView::notifyEvent(ObservableModelo* o, Evento_type type) {
//	if(type == DESTRUCCION_FORZADA){
//		cout << "se entera la vista y solicita su destruccion" << endl;
//		o->removeObserver(this);
//		notifY(DESTRUIR_VISTA);
//	}
}

void UnionView::resizear() {
	super::resizear();
	update();
}
