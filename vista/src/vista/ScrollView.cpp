/*
 * ScrollView.cpp
 *
 *  Created on: 13/09/2013
 *      Author: jonathan
 */

#include "ScrollView.h"

ScrollView::ScrollView(int x, int y, int w, int h, SDL_Texture * flecha) :
		View(x, y, w, h) {
	inicializar(flecha, false);
}
void ScrollView::inicializar(SDL_Texture* flecha, bool abajo) {
	this->abajo = abajo;
	this->textura = flecha;

}

ScrollView::ScrollView(int x, int y, int w, int h, SDL_Texture* flecha,
		bool abajo):View(x,y,w,h) {
	inicializar(flecha,abajo);
}

bool ScrollView::isAbajo() const {
	return abajo;
}

void ScrollView::setAbajo(bool abajo) {
	this->abajo = abajo;
}

ScrollView::~ScrollView() {
	// TODO Auto-generated destructor stub
}

void ScrollView::dibujarse(SDL_Renderer* renderer) {
	SDL_Rect dest;
	int ancho = this->getW() * 0.3;
	int alto = this->getH()*0.5;

	dest.x = this->getX();
	dest.y = this->getY();
	dest.w = this->getW();
	dest.h = this->getH();
	//dibujo el fondo:
	SDL_SetRenderDrawColor(renderer, 0, 50, 0, 0);
	SDL_RenderFillRect(renderer, &dest);
	dest.x = dest.x + dest.w/2 - ancho/2;
	dest.y = dest. y +(dest.h - alto) /2;
	dest.h= alto;
	dest.w = ancho;

	if (this->abajo) {
		SDL_RenderCopyEx(renderer, this->textura, NULL, &dest, 180, NULL,
				SDL_FLIP_NONE);
	} else {
		SDL_RenderCopy(renderer, this->textura, NULL, &dest);
	}

}
