/*
 * FlechaScrollView.cpp
 *
 *  Created on: 13/09/2013
 *      Author: jonathan
 */

#include "FlechaScrollView.h"
namespace CLIENTE {
FlechaScrollView::FlechaScrollView(float x, float y, float w, float h, SDL_Texture * flecha,int sleep) :
		View(x, y, w, h) {
	inicializar(flecha, false, sleep);
}
void FlechaScrollView::inicializar(SDL_Texture* flecha, bool abajo, int sleep) {
	this->abajo = abajo;
	this->textura = flecha;
	this->presionado = false;
	this->sleep = sleep;
}

FlechaScrollView::FlechaScrollView(float x, float y, float w, float h, SDL_Texture* flecha,int sleep,
		bool abajo):View(x,y,w,h) {
	inicializar(flecha,abajo,sleep);
}

FlechaScrollView::~FlechaScrollView() {
	// TODO Auto-generated destructor stub
}

void FlechaScrollView::dibujarse(SDL_Renderer* renderer) {
	if(presionado && contAbajo++ == sleep){
		presionado =false;
	}
	SDL_Rect dest;
	dest.x = xp;
	dest.y = yp;
	dest.w = wp;
	dest.h = hp;
	this->dibujarse(renderer, dest);
}

void FlechaScrollView::dibujarse(SDL_Renderer* renderer, SDL_Rect& dest) {
	int ancho = dest.w * 0.3;
	int alto = dest.h*0.5;

	//dibujo el fondo:
	int corrPresion = 0;//px

	if(this->presionado){
		corrPresion = 1;
		SDL_SetRenderDrawColor(renderer, 0, 70, 0, 0);
	} else {
		SDL_SetRenderDrawColor(renderer, 0, 50, 0, 0);
	}
	SDL_RenderFillRect(renderer, &dest);
	dest.x = dest.x + dest.w/2 - ancho/2;
	dest.y = dest. y +(dest.h - alto) /2;
	dest.h= alto;
	dest.w = ancho;

	if (this->abajo) {
		dest.y = dest.y - 2 +corrPresion;
		SDL_RenderCopyEx(renderer, this->textura, NULL, &dest, 180, NULL,
				SDL_FLIP_NONE);
	} else {
		dest.y = dest.y + 2 + corrPresion;
		SDL_RenderCopy(renderer, this->textura, NULL, &dest);
	}

}

void FlechaScrollView::accionar() {
	presionado = true;
	contAbajo = 1;
}

void FlechaScrollView::update(ViewMsj*) {
}
}

