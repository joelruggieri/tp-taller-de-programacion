/*
 * BotonSwitch.cpp
 *
 *  Created on: 2/10/2013
 *      Author: jonathan
 */

#include "BotonSwitch.h"
#include "../controller/UserEventCreator.h"
BotonSwitch::BotonSwitch(float x,float y,float w,float h,int eventoUno, int eventoDos):View(x,y) {
	this->presionado = 0;
	this->evento1 = eventoUno;
	this->evento2 = eventoDos;
}
BotonSwitch::~BotonSwitch() {

}

void BotonSwitch::dibujarse(SDL_Renderer* r) {
//	SDL_Rect dest;
//	dest.h = this->getH();
//	dest.w = this->getW();
//	dest.x = this->getX();
//	dest.y = this->getY();
//	this->dibujarse(r , dest);

}

void BotonSwitch::click() {
	int evento = presionado ? evento2: evento1;
	SDL_Event event = crearEvento(evento, NULL, NULL);
	presionado = !presionado;
	SDL_PushEvent(&event);
}
