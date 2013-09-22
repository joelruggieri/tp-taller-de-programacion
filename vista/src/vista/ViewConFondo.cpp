/*
 * ViewConFondo.cpp
 *
 *  Created on: 22/09/2013
 *      Author: jonathan
 */

#include "ViewConFondo.h"

ViewConFondo::ViewConFondo(View * view) :
View(view->getXCentro(), view->getYCentro(), view->getW(), view->getH()) {
	this->decorable = view;
}

ViewConFondo::~ViewConFondo() {
	delete decorable;
}

int ViewConFondo::getH() const {
	return this->decorable->getH();
}

int ViewConFondo::getW() const {
	return this->decorable->getW();
}

int ViewConFondo::getX() const {
	return this->decorable->getX();
}

int ViewConFondo::getY() const {
	return this->decorable->getY();
}

int ViewConFondo::getXCentro() const {
	return this->decorable->getXCentro();
}

int ViewConFondo::getYCentro() const {
	return this->decorable->getYCentro();
}

void ViewConFondo::resizear() {
}

void ViewConFondo::desplazarCentroA(int x, int y) {
	this->decorable->desplazarCentroA(x, y);
}

void ViewConFondo::setH(int h) {
	this->decorable->setH(h);
}

void ViewConFondo::setW(int w) {
	this->decorable->setW(w);
}

void ViewConFondo::setXc(int xc) {
	this->decorable->setXc(xc);
}

void ViewConFondo::setYc(int yc) {
	this->decorable->setYc(yc);
}

void ViewConFondo::dibujarse(SDL_Renderer* renderer, SDL_Rect& dest) {
	this->dibujarse(renderer);
}

void ViewConFondo::dibujarse(SDL_Renderer*r){
	SDL_Rect dst;
	dst.x = this->decorable->getX();
	dst.y = this->decorable->getY();
	dst.w = this->decorable->getW();
	dst.h = this->decorable->getH();

	SDL_SetRenderDrawColor(r, 170,
			255, 214, 1);
	SDL_RenderFillRect(r, &dst);
	this->decorable->dibujarse(r);
}
