/*
 * ZonaPlay.cpp
 *
 *  Created on: 2/10/2013
 *      Author: jonathan
 */

#include "ZonaPlay.h"
#include "../UserEventCreator.h"
#include "SDL2/SDL.h"
ZonaPlay::ZonaPlay(float x, float y):Zona(new Cuadrado(x,y,20,10)) {
	boton = new BotonSwitch(x,y,20,10,USREVENT_START, USREVENT_STOP);
}

bool ZonaPlay::agregarTemplate(FiguraView* dragueable) {
	return false;
}

FiguraView* ZonaPlay::getFiguraTemplate(float x, float y) {
	return 0;
}

ZonaPlay::~ZonaPlay() {
	delete boton;
}

bool ZonaPlay::click(float x, float y) {
	if(this->getCuerpo()->contacto(x,y)){
		this->boton->click();
		return true;
	}
	return false;
}

void ZonaPlay::dibujarse(SDL_Renderer*r) {
	this->boton->dibujarse(r);
}

bool ZonaPlay::mouseScroll(float x, float y, int amountScrolled) {
	return false;
}
