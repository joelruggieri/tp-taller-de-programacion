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
namespace CLIENTE {

class Dibujable{
private:
	int layer;
	bool highlight;
public:
	Dibujable(int layer);
	virtual ~Dibujable();
	int getLayer();
	virtual void dibujarse(SDL_Renderer *) = 0;
	virtual void dibujarse(SDL_Renderer *, SDL_Rect& destino) = 0;
	void higlight(bool);
};

}
#endif /* DIBUJABLE_H_ */
