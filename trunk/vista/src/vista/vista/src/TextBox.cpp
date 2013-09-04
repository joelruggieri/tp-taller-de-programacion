/*
 * TextBox.cpp
 *
 *  Created on: 02/09/2013
 *      Author: ezequiel
 */

#include "TextBox.h"

namespace std {

TextBox::TextBox(int x, int y, int w, int h,SDL_Texture* imagen, SDL_Renderer* render) {
	// TODO Auto-generated constructor stub
	TTF_Init();
	this->x = x;
	this->y = y;
	this->w = w;
	this->h = h;
	this->imagen = imagen;
	this->render = render ;
	font = TTF_OpenFont("Achafita.ttf", 16);
	colorTexto.b = 0;
	colorTexto.g = 140;
	colorTexto.r = 100;
	//TTF_SizeText(font,"a", &w, &h);
	texto = "";




}

TextBox::~TextBox() {
	// TODO Auto-generated destructor stub
}


void TextBox::Resizear(int x, int y)
{
	this->x = this->x + x;
	this->y = this->y + y;

}

} /* namespace std */
