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
#include "Dibujable.h"
#include "Resizeable.h"

namespace std {

class Canvas : public Dibujable, public Resizeable  {
	/*int x,y,w,h;
	SDL_Texture* imagenCanvas;
	SDL_Renderer* render ;*/
public:
	Canvas(int x, int y, int h, int w, SDL_Texture* textura, SDL_Renderer* render) : Dibujable(x,y,h,w,textura,render)
	{

	}
	//void Dibujarse();
	virtual ~Canvas();
	int ModificarFondo(char* rutaNueva);

	//void Resizear(int x, int y);
};

} /* namespace std */
#endif /* CANVAS_H_ */
