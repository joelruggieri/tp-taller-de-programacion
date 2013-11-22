#include "FiguraView.h"

#include <iostream>
#include "src/Logger.h"
#include <cmath>
using namespace std;
namespace CLIENTE {
/********************************************************
 * FIGURAVIEW

 ********************************************************/
FiguraView::FiguraView(float x, float y, float w, float h,int layer,int numeroEvent,SDL_Texture* textura): View(x,y,w,h, layer) {
//	this->tl = Resizer::Instance()->getTransformacionToModelo();
	this->angulo = 0;
	this->textura = textura;
	this->numeroEvento = numeroEvent;
}

FiguraView::~FiguraView(){

}


void FiguraView::dibujarse(SDL_Renderer * renderer){
	SDL_Rect dest;
	dest.h = this->hp;
	dest.w = this->wp;
	dest.x = this->xp;
	dest.y = this->yp;
	this->dibujarse(renderer, dest);
}

void FiguraView::dibujarse(SDL_Renderer * renderer, SDL_Rect & dest){
	if(this->angulo != 0){
		SDL_RenderCopyEx(renderer,this->textura, NULL, &dest,this->angulo,NULL,SDL_FLIP_NONE);
	} else {
		SDL_RenderCopy(renderer,this->textura,NULL,&dest);
	}
}

SDL_Texture* FiguraView::getTexture() {
	return textura;
}

void FiguraView::resizear() {
	super::resizear();
//	this->tl = Resizer::Instance()->getTransformacionToModelo();
}


float FiguraView::getAngulo() const {
	return angulo;
}

void FiguraView::setAngulo(float angulo) {
	this->angulo = angulo;
}

int FiguraView::getNumeroEvento() const{
	return this->numeroEvento;
}
}
