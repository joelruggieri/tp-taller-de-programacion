/*
 * ZonaPlay.cpp
 *
 *  Created on: 2/10/2013
 *      Author: jonathan
 */

#include "ZonaPlay.h"
#include "SDL2/SDL.h"
ZonaPlay::ZonaPlay(float x, float y):Zona(new Cuadrado(x,y,20,10)) {
}

bool ZonaPlay::agregarTemplate(FiguraView* dragueable) {
	return false;
}

FiguraView* ZonaPlay::getFiguraTemplate(float x, float y) {
	return 0;
}

ZonaPlay::~ZonaPlay() {
}

bool ZonaPlay::click(float x, float y) {
	if(this->getCuerpo()->contacto(x,y)){
		return true;
	}
	return false;
}

void ZonaPlay::dibujarse(list<ViewMsj*> & lista){
}

bool ZonaPlay::mouseScroll(float x, float y, int amountScrolled) {
	return false;
}
