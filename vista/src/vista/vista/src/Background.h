/*
 * Background.h
 *
 *  Created on: 31/08/2013
 *      Author: ezequiel
 */

#ifndef BACKGROUND_H_
#define BACKGROUND_H_
#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"
#include <iostream>
#include "Dibujable.h"
#include "Resizeable.h"

namespace std {

class Background : public Dibujable, public Resizeable {
/*	int x,y,w,h;
	SDL_Texture* imagen;
	SDL_Renderer* render ;*/
public:
	Background(int x, int y, int h, int w, SDL_Texture* textura, SDL_Renderer* render);
	// void Dibujarse();
	void Resizear(int x, int y);

	virtual ~Background();
};

} /* namespace std */
#endif /* BACKGROUND_H_ */
