/*
 * ViewConBorde.cpp
 *
 *  Created on: 22/09/2013
 *      Author: jonathan
 */

#include "ViewConBorde.h"
namespace CLIENTE {
ViewConBorde::ViewConBorde(View * view) :
		View(view->getXCentro(), view->getYCentro(), view->getW(), view->getH()) {
	this->decorable = view;
	this->ajustarTamanio = true;
}

ViewConBorde::~ViewConBorde() {
	delete decorable;
}
//robo 3 pixels.
void ViewConBorde::generarConBorde(SDL_Rect & dest) {
	dest.h = this->decorable->getH() - 12;
	dest.w = this->decorable->getW() - 12;
	dest.x = this->decorable->getX() + 6;
	dest.y = this->decorable->getY() + 6;
}

void ViewConBorde::dibujarBordeIzquierdo(SDL_Renderer* renderer) {
	SDL_Rect dest;
	int corrimiento = 0;
	this->generarSinBorde(dest);
	dest.w = 3;
	dest.x = dest.x - corrimiento;
	dest.y = dest.y - corrimiento;
	dest.h = dest.h + corrimiento * 2;
	SDL_SetRenderDrawColor(renderer, COLOR_BORDE_EXTERNO.r,
			COLOR_BORDE_EXTERNO.g, COLOR_BORDE_EXTERNO.b, 1);
	SDL_RenderFillRect(renderer, &dest);
	dest.x = dest.x + 3;
	dest.y = dest.y + 3;
	dest.h = dest.h - 6;
	dest.w = 2;
	SDL_SetRenderDrawColor(renderer, COLOR_BORDE_INTERNO.r,
			COLOR_BORDE_INTERNO.g, COLOR_BORDE_INTERNO.b, 1);
	SDL_RenderFillRect(renderer, &dest);
}

void ViewConBorde::dibujarBordeDerecho(SDL_Renderer* renderer) {
	SDL_Rect dest;
	this->generarSinBorde(dest);
	dest.x = dest.x + dest.w - 3;
	dest.w = 3;
	SDL_SetRenderDrawColor(renderer, COLOR_BORDE_EXTERNO.r,
			COLOR_BORDE_EXTERNO.g, COLOR_BORDE_EXTERNO.b, 1);
	SDL_RenderFillRect(renderer, &dest);
	dest.x = dest.x - 2;
	dest.y = dest.y + 3;
	dest.h = dest.h - 6;
	dest.w = 2;
	SDL_SetRenderDrawColor(renderer, COLOR_BORDE_INTERNO.r,
			COLOR_BORDE_INTERNO.g, COLOR_BORDE_INTERNO.b, 1);
	SDL_RenderFillRect(renderer, &dest);
}

void ViewConBorde::dibujarBordeSuperior(SDL_Renderer* renderer) {
	SDL_Rect dest;
	this->generarSinBorde(dest);
	dest.h = 3;
	SDL_SetRenderDrawColor(renderer, COLOR_BORDE_EXTERNO.r,
			COLOR_BORDE_EXTERNO.g, COLOR_BORDE_EXTERNO.b, 1);
	SDL_RenderFillRect(renderer, &dest);
	dest.x = dest.x + 3;
	dest.y = dest.y + 3;
	dest.w = dest.w - 6;
	dest.h = 2;
	SDL_SetRenderDrawColor(renderer, COLOR_BORDE_INTERNO.r,
			COLOR_BORDE_INTERNO.g, COLOR_BORDE_INTERNO.b, 1);
	SDL_RenderFillRect(renderer, &dest);
}

void ViewConBorde::dibujarBordeInferior(SDL_Renderer* renderer) {
	SDL_Rect dest;
	this->generarSinBorde(dest);
	dest.y = dest.y + dest.h - 3;
	dest.h = 3;
	SDL_SetRenderDrawColor(renderer, COLOR_BORDE_EXTERNO.r,
			COLOR_BORDE_EXTERNO.g, COLOR_BORDE_EXTERNO.b, 1);
	SDL_RenderFillRect(renderer, &dest);
	dest.x = dest.x + 3;
	dest.y = dest.y - 2;
	dest.w = dest.w - 6;
	dest.h = 2;
	SDL_SetRenderDrawColor(renderer, COLOR_BORDE_INTERNO.r,
			COLOR_BORDE_INTERNO.g, COLOR_BORDE_INTERNO.b, 1);
	SDL_RenderFillRect(renderer, &dest);
}
void ViewConBorde::dibujarBorde(SDL_Renderer * renderer) {
	dibujarBordeIzquierdo(renderer);
	dibujarBordeDerecho(renderer);
	dibujarBordeSuperior(renderer);
	dibujarBordeInferior(renderer);
}

void ViewConBorde::generarSinBorde(SDL_Rect & dest) {
	dest.h = this->decorable->getH();
	dest.w = this->decorable->getW();
	dest.x = this->decorable->getX();
	dest.y = this->decorable->getY();
}
void ViewConBorde::dibujarse(SDL_Renderer* renderer) {
	if (this->ajustarTamanio) {
		SDL_Rect dest;
		generarConBorde(dest);
		this->decorable->dibujarse(renderer, dest);
	} else {
		this->decorable->dibujarse(renderer);

	}

	this->dibujarBorde(renderer);
}

int ViewConBorde::getH() const {
	return this->decorable->getH();
}

int ViewConBorde::getW() const {
	return this->decorable->getW();
}

int ViewConBorde::getX() const {
	return this->decorable->getX();
}

int ViewConBorde::getY() const {
	return this->decorable->getY();
}

int ViewConBorde::getXCentro() const {
	return this->decorable->getXCentro();
}

int ViewConBorde::getYCentro() const {
	return this->decorable->getYCentro();
}

void ViewConBorde::resizear() {
}

void ViewConBorde::desplazarCentroA(int x, int y) {
	this->decorable->desplazarCentroA(x, y);
}

void ViewConBorde::setH(int h) {
	this->decorable->setH(h);
}

void ViewConBorde::setW(int w) {
	this->decorable->setW(w);
}

void ViewConBorde::setXc(int xc) {
	this->decorable->setXc(xc);
}

void ViewConBorde::setYc(int yc) {
	this->decorable->setYc(yc);
}

void ViewConBorde::dibujarse(SDL_Renderer* renderer, SDL_Rect& dest) {
	this->dibujarse(renderer);
}

void ViewConBorde::setAjustarTamanio(bool bool1) {
	this->ajustarTamanio = bool1;
}
}
