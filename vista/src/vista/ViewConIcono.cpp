/*
 * ViewConIcono.cpp
 *
 *  Created on: 03/10/2013
 *      Author: jonathan
 */

#include "ViewConIcono.h"
namespace CLIENTE {
ViewConIcono::ViewConIcono(View * view, SDL_Texture * t, int esquina) {
	vista = view;
	textura = t;
	this->esquina = esquina;
}

ViewConIcono::~ViewConIcono() {
}

void ViewConIcono::dibujarse(SDL_Renderer* renderer) {
//	SDL_Rect dest;
//	switch (esquina) {
//		case 0:
//			dest = this->rectEsquina0();
//			break;
//		case 1:
//			dest = this->rectEsquina1();
//			break;
//
//		case 2:
//			dest = this->rectEsquina2();
//			break;
//
//		case 3:
//			dest = this->rectEsquina3();
//			break;
//
//		default:
//			dest = this->rectEsquina0();
//			break;
//
//	}
//	vista->dibujarse(renderer);
//	SDL_RenderCopy(renderer, this->textura, 0, &dest);
}

//SDL_Rect ViewConIcono::rectEsquina0() {
//	SDL_Rect r;
//	r.x = vista->getX() + vista->getW() - 5;
//	r.y = vista->getY() + 5;
//	r.w = 20;
//	r.h = 20;
//	return r;
//}
//
//SDL_Rect ViewConIcono::rectEsquina1() {
//	SDL_Rect r;
//	r.x = vista->getX()+ vista->getW() + 5;
//	r.y = vista->getY() + + vista->getH()+ 5;
//	r.w = 20;
//	r.h = 20;
//	return r;
//}
//
//SDL_Rect ViewConIcono::rectEsquina2() {
//	SDL_Rect r;
//	r.x = vista->getX() + vista->getW() + 5;
//	r.y = vista->getY() - 5;
//	r.w = 20;
//	r.h = 20;
//	return r;
//}
//
//SDL_Rect ViewConIcono::rectEsquina3() {
//	SDL_Rect r;
//	r.x = vista->getX() - 5;
//	r.y = vista->getY() - 5;
//	r.w = 20;
//	r.h = 20;
//	return r;
//
//}

void ViewConIcono::dibujarse(SDL_Renderer*r, SDL_Rect& destino) {
	this->dibujarse(r);
}
}
