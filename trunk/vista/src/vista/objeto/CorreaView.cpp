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
	/*SDL_RenderDrawLine(renderer,this->xDesde + v1oX +5,this->yDesde + v1oY -5,this->xHasta + v1oX +5,this->yHasta + v1oY -5);
	SDL_RenderDrawLine(renderer,this->xDesde + v1oX +4,this->yDesde + v1oY -4,this->xHasta + v1oX +4,this->yHasta + v1oY -4);
	SDL_RenderDrawLine(renderer,this->xDesde + v1oX +3,this->yDesde + v1oY -3,this->xHasta + v1oX +1,this->yHasta + v1oY -3);
	SDL_RenderDrawLine(renderer,this->xDesde + v1oX +2,this->yDesde + v1oY -2,this->xHasta + v1oX +2,this->yHasta + v1oY -2);
	SDL_RenderDrawLine(renderer,this->xDesde + v1oX +1,this->yDesde + v1oY -1,this->xHasta + v1oX +1,this->yHasta + v1oY -1);*/
	SDL_RenderDrawLine(renderer,this->xDesde + v1iX,this->yDesde + v1iY,this->xHasta + v1fX,this->yHasta + v1fY);
	SDL_RenderDrawLine(renderer,this->xDesde + v2iX,this->yDesde + v2iY,this->xHasta + v2fX,this->yHasta + v2fY);

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
	float v1oX = (-yHastaRespectoYDesde);
	float v1oY = xHastaRespectoXDesde;

	if(this->getModelo() == NULL){
		 v1iX = v1oX *((float)this->getW()/2);
		 v1iY = v1oY * ((float)this->getW()/2);
		 v1fX = v1oX * ((float)this->getW()/2);
		 v1fY = v1oY * ((float)this->getW()/2);
	} else {
		Correa* c = (Correa*)this->getModelo();
		float radio,foo;
		tl.setVector(c->getRadioInicial() * 0.8,0.0f);
		tl.getResultadoInverso(radio,foo);
		v1iX = v1oX * radio;
		v1iY = v1oY * radio;
		tl.setVector(c->getRadioFinal() * 0.8,0.0f);
		tl.getResultadoInverso(radio,foo);
		v1fX = v1oX * radio;
		v1fY = v1oY * radio;
	}
	//V2o
	v2iX = -v1iX;
	v2iY = -v1iY;
	v2fX = -v1fX;
	v2fY = -v1fY;

}
