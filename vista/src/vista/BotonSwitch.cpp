/*
 * BotonSwitch.cpp
 *
 *  Created on: 2/10/2013
 *      Author: jonathan
 */

#include "BotonSwitch.h"
#include "../controller/UserEventCreator.h"
#include "src/mensajes/viewMensaje/ViewBotonStartMsj.h"
namespace CLIENTE {
BotonSwitch::BotonSwitch(float x,float y,float w,float h, SDL_Texture * text1, SDL_Texture * text2):View(x,y,w,h) {
	this->presionado = false;
	this->t1 = text1;
	this->t2 = text2;
}

BotonSwitch::~BotonSwitch() {

}

void BotonSwitch::dibujarse(SDL_Renderer* r) {
	SDL_Rect dest;
	dest.h = hp;
	dest.w = wp;
	dest.x = xp;
	dest.y = yp;
	this->dibujarse(r , dest);

}

void BotonSwitch::dibujarse(SDL_Renderer* r, SDL_Rect& d) {
	SDL_Texture * textura = presionado ? t2: t1;
	SDL_RenderCopy(r,textura,NULL,&d);
}

void BotonSwitch::click() {
	presionado = !presionado;
}

void BotonSwitch::update(ViewMsj* m) {
	ViewBotonStartMsj * msj = (ViewBotonStartMsj *)m;
	this->presionado = msj->isListo();
}


bool BotonSwitch::isUpdated() {
	return true;
}

bool BotonSwitch::isPresionado() {
	return presionado;
}

}
