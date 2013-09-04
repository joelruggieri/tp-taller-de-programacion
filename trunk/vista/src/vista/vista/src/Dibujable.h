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
#include "Posicionable.h"

namespace std {

class Dibujable : virtual public Posicionable {

public:
	Dibujable();
	virtual ~Dibujable();
	void Dibujarse();
protected:
	SDL_Texture* imagen;
	SDL_Renderer* render ;
};

} /* namespace std */
#endif /* DIBUJABLE_H_ */
