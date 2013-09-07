/*
 * TextBox.cpp
 *
 *  Created on: 02/09/2013
 *      Author: ezequiel
 */

#include "TextBox.h"

namespace std {

//TextBox::TextBox(int x, int y, int w, int h,SDL_Texture* imagen, SDL_Renderer* render) {
//	// TODO Auto-generated constructor stub
//	TTF_Init();
////	this->x = x;
////	this->y = y;
////	this->w = w;
////	this->h = h;
////	this->imagen = imagen;
////	this->render = render ;
//	font = TTF_OpenFont("Arial Bold.ttf", 10);
//	colorTexto.b = 255;
//	colorTexto.g = 255;
//	colorTexto.r = 255;
//	colorBackGroundTexto.b = 0;
//	colorBackGroundTexto.r = 0;
//	colorBackGroundTexto.g = 0;
//
//	TTF_SizeText(font,"a", &w, &h);
//	snprintf(buf,256," Escriba su texto aqui ");
//
//
//
//}

TextBox::~TextBox() {
	// TODO Auto-generated destructor stub
}

void TextBox::Dibujarse()
{
	SDL_Texture *textTexture;
	char buf[256];
	SDL_Rect dst;
	SDL_Rect fondo;

	fondo.h = this->h;
	fondo.w = this->w;
	fondo.x = this->x;
	fondo.y = this->y;

	snprintf(buf,256," ");



	SDL_Surface *textSurface= TTF_RenderText_Solid(font, buf,colorBackGroundTexto);

	if(textSurface)
	{
	textTexture = SDL_CreateTextureFromSurface(this->render, textSurface);
	dst.h = this->h - 3;
	dst.w = strlen(buf)*5;
	dst.x = this->x+8;
	dst.y = this->y+1;
	}

	SDL_FreeSurface(textSurface);
	SDL_RenderCopy(render,this->imagen, NULL, &fondo);
	SDL_RenderCopy(render, textTexture, NULL, &dst);
}

int TextBox::EditarTextBox(char letra)
{
	//strcat(&letra, this->buf);
	return 0;

}

void TextBox::Resizear(int x, int y)
{
//	this->x = this->x + x;
	this->y = this->y + y;

}

//bool TextBox::FueSeleccionado(int x, int y)
//{
//	if ((x <= this->x + this->w) and ( x >= this->x ) and (y <= this->y + this->h) and ( y>= this->y))
//			return true;
//	else
//		return false;
//}

} /* namespace std */
