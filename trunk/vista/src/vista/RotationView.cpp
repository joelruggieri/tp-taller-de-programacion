/*
 * RotationView.cpp
 *
 *  Created on: 11/09/2013
 *      Author: jonathan
 */

#include "RotationView.h"

#include "SDL2/SDL.h"

RotationView::RotationView(Rotable* rotado) {
this->rotado = rotado;
}

RotationView::~RotationView() {
	// TODO Auto-generated destructor stub
}

void RotationView::dibujarse(SDL_Renderer* renderer) {
	if(this->rotado->isRotando()){
		View* rotado0 = this->rotado->getRotado();
		SDL_Rect dest;
		dest.x = rotado0->getX() -2;
		dest.y = rotado0->getY() -2;
		dest.w = rotado0->getW() +4;
		dest.h = rotado0->getH() +4;
		SDL_RenderFillRect(renderer,&dest);
		rotado0->dibujarse(renderer);
		FiguraView* rotacion= (FiguraView*) this->rotado->getRotado();
		cout << rotacion->getModelo()->getRotacion()<<endl;
	}
}
