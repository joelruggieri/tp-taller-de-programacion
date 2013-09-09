/*
 * Canvas.h
 *
 *  Created on: 31/08/2013
 *      Author: ezequiel
 */

#ifndef CANVAS_H_
#define CANVAS_H_
#include "SDL2/SDL_image.h"
#include "SDL2/SDL.h"
#include <iostream>
#include "View.h"
#include "Resizeable.h"


class Canvas: public View{
	 SDL_Texture* imagenCanvas;
	 /* SDL_Renderer* render ;*/
public:
	Canvas(int x, int y, int h, int w, SDL_Texture* textura);
	void dibujarse(SDL_Renderer *);
	virtual ~Canvas();
	int ModificarFondo(char* rutaNueva);

	//void Resizear(int x, int y);
};

#endif /* CANVAS_H_ */
