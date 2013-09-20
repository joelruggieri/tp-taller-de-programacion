/*
 * FlechaScrollView.cpp
 *
 *  Created on: 13/09/2013
 *      Author: jonathan
 */

#include "FlechaScrollView.h"

FlechaScrollView::FlechaScrollView(int x, int y, int w, int h, SDL_Texture * flecha) :
		View(x, y, w, h) {
	inicializar(flecha, false);
}
void FlechaScrollView::inicializar(SDL_Texture* flecha, bool abajo) {
	this->abajo = abajo;
	this->textura = flecha;
	this->presionado = false;
}

FlechaScrollView::FlechaScrollView(int x, int y, int w, int h, SDL_Texture* flecha,
		bool abajo):View(x,y,w,h) {
	inicializar(flecha,abajo);
}

bool FlechaScrollView::isAbajo() const {
	return abajo;
}

void FlechaScrollView::setAbajo(bool abajo) {
	this->abajo = abajo;
}

FlechaScrollView::~FlechaScrollView() {
	// TODO Auto-generated destructor stub
}

bool FlechaScrollView::isPresionado() const {
	return presionado;
}

void FlechaScrollView::dibujarse(SDL_Renderer* renderer) {
	SDL_Rect dest;
	int ancho = this->getW() * 0.3;
	int alto = this->getH()*0.5;

	dest.x = this->getX();
	dest.y = this->getY();
	dest.w = this->getW();
	dest.h = this->getH();
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

void FlechaScrollView::setPresionado(bool presionado) {
	this->presionado = presionado;
}

void FlechaScrollView::resizear() {
	cout << "se ha resieado las flechas scrooll view" << endl ;
	this->setXc(Resizer::Instance()->resizearDistanciaX(this->getXCentro()));
	this->setYc((Resizer::Instance()->resizearDistanciaY(this->getYCentro())));
		this->setW(Resizer::Instance()->resizearDistanciaX(this->getW()));

}
