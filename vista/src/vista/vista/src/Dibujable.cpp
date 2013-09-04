/*
 * Dibujable.cpp
 *
 *  Created on: 04/09/2013
 *      Author: ezequiel
 */

#include "Dibujable.h"

namespace std {

Dibujable::Dibujable() {



}

Dibujable::~Dibujable() {
	// TODO Auto-generated destructor stub


} /* namespace std */

void Dibujable::Dibujarse()
{
	SDL_Rect dst ;
		dst.x = this->x;
		dst.y = this->y;
		dst.h = this->h;
		dst.w = this->w;
		SDL_RenderCopy(this->render, this->imagen,NULL,&dst);
		return;
}
}

