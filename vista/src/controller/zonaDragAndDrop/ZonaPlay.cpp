/*
 * ZonaPlay.cpp
 *
 *  Created on: 2/10/2013
 *      Author: jonathan
 */

#include "ZonaPlay.h"
#include "../UserEventCreator.h"
#include "../../vista/CargadorDeTextures.h"
#include "../../vista/ViewConBorde.h"

#include "SDL2/SDL.h"
ZonaPlay::ZonaPlay(float x, float y):Zona(new Cuadrado(x,y,20,10)) {
	Resizer* r = Resizer::Instance();
	int w,h;
	r->adaptarDimensionLogica(20,10,w,h);
	int lx,ly;
	r->adaptarPosicionLogica(x,y,lx,ly);
	CargadorDeTextures* loader = CargadorDeTextures::Instance();
	SDL_Texture* text1 = loader->cargarTexture("resource/play.png");
	SDL_Texture* text2 = loader->cargarTexture("resource/stop.png");
	boton = new BotonSwitch(lx,ly,w,h,USREVENT_START, USREVENT_STOP,text1,text2);
	vista = new ViewConBorde(boton);
}

bool ZonaPlay::agregarTemplate(FiguraView* dragueable) {
	return false;
}

FiguraView* ZonaPlay::getFiguraTemplate(float x, float y) {
	return 0;
}

ZonaPlay::~ZonaPlay() {
	delete vista;
}

bool ZonaPlay::click(float x, float y) {
	if(this->getCuerpo()->contacto(x,y)){
		this->boton->click();
		return true;
	}
	return false;
}

void ZonaPlay::dibujarse(SDL_Renderer*r) {
	this->vista->dibujarse(r);
}

void ZonaPlay::dibujarse(SDL_Renderer*r, SDL_Rect&) {
	this->vista->dibujarse(r);
}

bool ZonaPlay::mouseScroll(float x, float y, int amountScrolled) {
	return false;
}
