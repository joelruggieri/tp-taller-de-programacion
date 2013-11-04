#include "FiguraView.h"

#include <iostream>
#include "src/Logger.h"
#include <cmath>
using namespace std;

/********************************************************
 * FIGURAVIEW

 ********************************************************/
FiguraView::FiguraView(int x, int y, int w, int h,SDL_Texture* textura): View(x,y,w,h) {
	this->tl = Resizer::Instance()->getTransformacionToModelo();

	this->textura = textura;
}

FiguraView::~FiguraView(){

}


void FiguraView::dibujarse(SDL_Renderer * renderer){
	SDL_Rect dest;
	dest.h = this->getH();
	dest.w = this->getW();
	dest.x = this->getX();
	dest.y = this->getY();
	this->dibujarse(renderer, dest);
}

void FiguraView::dibujarse(SDL_Renderer * renderer, SDL_Rect & dest){
//	if(this->getModelo() != NULL && this->getModelo()->getRotacion() != 0){
//		SDL_RenderCopyEx(renderer,this->textura, NULL, &dest,this->getModelo()->getRotacion(),NULL,SDL_FLIP_NONE);
//	} else {
//		SDL_RenderCopy(renderer,this->textura,NULL,&dest);
//	}
}

SDL_Texture* FiguraView::getTexture() {
	return textura;
}

void FiguraView::resizear() {
	super::resizear();
	this->tl = Resizer::Instance()->getTransformacionToModelo();
}
