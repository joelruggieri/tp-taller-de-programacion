/*
 * Dibujable.cpp
 *
 *  Created on: 04/09/2013
 *      Author: ezequiel
 */

#include "Dibujable.h"

namespace std {

Dibujable::Dibujable(int x, int y, int h, int w, SDL_Texture* textura, SDL_Renderer* render) {

		this->render = render;
		this->imagen = textura;
			this->x = x;
			this->y = y;
			this->w = w;
			this->h = h;

}

Dibujable::~Dibujable() {
	// TODO Auto-generated destructor stub


} /* namespace std */

void Dibujable::Dibujarse()
{
	SDL_Rect dst ;
		dst.x = (this->x) ;
		dst.y = (this->y) ;
		dst.h =  this->h;
		dst.w = this->w;
		SDL_RenderCopy(this->render, this->imagen,NULL,&dst);
		return;
}
}

