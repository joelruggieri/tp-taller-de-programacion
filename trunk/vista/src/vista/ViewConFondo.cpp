/*
 * ViewConFondo.cpp
 *
 *  Created on: 22/09/2013
 *      Author: jonathan
 */

#include "ViewConFondo.h"
namespace CLIENTE {
ViewConFondo::ViewConFondo(View * view) :View(0,0,0,0){
//View(view->getXCentro(), view->getYCentro(), view->getW(), view->getH()) {
	this->decorable = view;
}

ViewConFondo::~ViewConFondo() {
	delete decorable;
}


void ViewConFondo::resizear() {
}

void ViewConFondo::desplazarCentroA(int x, int y) {
//	this->decorable->desplazarCentroA(x, y);
}

void ViewConFondo::dibujarse(SDL_Renderer* renderer, SDL_Rect& dest) {
	this->dibujarse(renderer);
}

void ViewConFondo::dibujarse(SDL_Renderer*r){
//	SDL_Rect dst;
//	dst.x = this->decorable->getX();
//	dst.y = this->decorable->getY();
//	dst.w = this->decorable->getW();
//	dst.h = this->decorable->getH();
//
//	SDL_SetRenderDrawColor(r, 170,
//			255, 214, 1);
//	SDL_RenderFillRect(r, &dst);
//	this->decorable->dibujarse(r);
}
}
