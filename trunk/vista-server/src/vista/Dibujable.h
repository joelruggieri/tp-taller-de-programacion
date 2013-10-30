/*
 * Dibujable.h
 *
 *  Created on: 04/09/2013
 *      Author: ezequiel
 */

#ifndef DIBUJABLE_H_
#define DIBUJABLE_H_
#include "SDL2/SDL_image.h"
#include "SDL2/SDL.h"
#include <iostream>


class Dibujable{

public:
	Dibujable();
	virtual ~Dibujable();
	virtual int getLayer();
	virtual void dibujarse(SDL_Renderer *) = 0;

};

#endif /* DIBUJABLE_H_ */
