/*
 * BotonSwitch.cpp
 *
 *  Created on: 2/10/2013
 *      Author: jonathan
 */

#include "BotonSwitch.h"
#include "../controller/UserEventCreator.h"
BotonSwitch::BotonSwitch(float x,float y,float w,float h, SDL_Texture * text1, SDL_Texture * text2):View(x,y,w,h) {
	this->presionado = 0;
	this->t1 = text1;
	this->t2 = text2;
}

BotonSwitch::~BotonSwitch() {

}

void BotonSwitch::dibujarse(SDL_Renderer* r) {
	SDL_Rect dest;
	dest.h = this->getH();
	dest.w = this->getW();
	dest.x = this->getX();
	dest.y = this->getY();
	this->dibujarse(r , dest);

}

void BotonSwitch::dibujarse(SDL_Renderer* r, SDL_Rect& d) {
	SDL_Texture * textura = presionado ? t2: t1;
	SDL_RenderCopy(r,textura,NULL,&d);
}

void BotonSwitch::click() {
	presionado = !presionado;
}
