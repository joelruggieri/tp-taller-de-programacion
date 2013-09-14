/*
 * TextBox.cpp
 *
 *  Created on: 14/09/2013
 *      Author: ezequiel
 */

#include "TextBox.h"

TextBox::TextBox(int x, int y, int w, int h, SDL_Texture* imagen) {
this->x = x;
this->y = y ;
this->w = w;
this->h = h ;
this->imagen = imagen ;

}

TextBox::~TextBox() {
	// TODO Auto-generated destructor stub
}

void TextBox::dibujarse(SDL_Renderer* render) {
	SDL_Rect dst ;
	dst.x = this->x ;
	dst.y =  this ->y;
	dst.h = this->h ;
	dst.w = this->w ;
	SDL_RenderCopy(render,this->imagen, NULL, &dst);

}
