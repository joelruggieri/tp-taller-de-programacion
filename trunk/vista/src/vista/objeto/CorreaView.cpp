/*
 * CorreaView.cpp
 *
 *  Created on: 15/10/2013
 *      Author: joel
 */

#include "CorreaView.h"
#include "../../controller/editor/EditorUnion.h"
#include "src/objeto/Correa.h"
#include <cmath>
#define PI 3.14159265

CorreaView::CorreaView(int x, int y, SDL_Texture * textura,EditorUnion* editor): UnionView(x, y,textura, editor) {

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
	SDL_SetRenderDrawColor(renderer,10,10,10,0);
	SDL_RenderDrawLine(renderer,this->xDesde + v1oX,this->yDesde + v1oY,this->xHasta + v1oX,this->yHasta + v1oY);
	SDL_RenderDrawLine(renderer,this->xDesde + v2oX,this->yDesde + v2oY,this->xHasta + v2oX,this->yHasta + v2oY);

	this->dibujarseEstatica(renderer);
}

void CorreaView::update(){
	super::update();
	double xHastaRespectoXDesde = (float)this->xHasta - (float)this->xDesde;
	double yHastaRespectoYDesde = (float)this->yHasta - (float)this->yDesde;
	double norma = sqrt((xHastaRespectoXDesde*xHastaRespectoXDesde) + (yHastaRespectoYDesde*yHastaRespectoYDesde));
	xHastaRespectoXDesde = xHastaRespectoXDesde / norma;
	yHastaRespectoYDesde = yHastaRespectoYDesde / norma;
	//V1o
	v1oX = (-yHastaRespectoYDesde) * ((float)this->getW()/2);
	v1oY = xHastaRespectoXDesde * ((float)this->getW()/2);
	//V2o
	v2oX = -v1oX;
	v2oY = -v1oY;
}
