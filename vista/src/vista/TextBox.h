/*
 * TextBox.h
 *
 *  Created on: 14/09/2013
 *      Author: ezequiel
 */

#ifndef TEXTBOX_H_
#define TEXTBOX_H_
#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"
#include "Herramientas.h"


class TextBox: public Herramientas {
public:
	TextBox(int x, int y, int w, int h, SDL_Texture* imagen);
	virtual ~TextBox();
	void dibujarse(SDL_Renderer* render);
private:
	int x,y,w,h;
	SDL_Texture* imagen ;

};

#endif /* TEXTBOX_H_ */
