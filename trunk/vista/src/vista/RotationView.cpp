/*
 * RotationView.cpp
 *
 *  Created on: 11/09/2013
 *      Author: jonathan
 */

#include "RotationView.h"

#include "SDL2/SDL.h"

RotationView::RotationView(Rotable* rotado, SDL_Texture * textura) {
this->rotado = rotado;
this->textura = textura;
}

RotationView::~RotationView() {
	// TODO Auto-generated destructor stub
}

void RotationView::dibujarse(SDL_Renderer* renderer) {
	if(this->rotado->isRotando()){
		View* rotado0 = this->rotado->getRotado();
		SDL_Rect dest;
		dest.x = rotado0->getX() + rotado0->getW() + 5;
		dest.y = rotado0->getY() - 5 ;
		dest.w = 20;
		dest.h = 20;
		SDL_RenderCopy(renderer,this->textura,NULL,&dest);
		rotado0->dibujarse(renderer);
//		cout << rotacion->getModelo()->getRotacion()<<endl;
	}
}
