/*
 * ZonaPlay.cpp
 *
 *  Created on: 2/10/2013
 *      Author: jonathan
 */

#include "ZonaPlay.h"

ZonaPlay::ZonaPlay(float x, float y):Zona(new Cuadrado(x,y,10,20)) {

}

bool ZonaPlay::agregarTemplate(FiguraView* dragueable) {
	return false;
}

FiguraView* ZonaPlay::getFiguraTemplate(float x, float y) {
	return 0;
}

ZonaPlay::~ZonaPlay() {
	// TODO Auto-generated destructor stub
}

bool ZonaPlay::click(float x, float y) {
	if(this->getCuerpo()->contacto(x,y)){
		cout << "clickea" << endl;
		return true;
	}
	return false;
}

void ZonaPlay::dibujarse(SDL_Renderer*) {
	cout << "se dibuja" <<endl;
}

void ZonaPlay::dibujarse(SDL_Renderer*, SDL_Rect&) {
}

bool ZonaPlay::mouseScroll(float x, float y, int amountScrolled) {
	return false;
}
