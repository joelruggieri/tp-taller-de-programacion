/*
 * TextBox.cpp
 *
 *  Created on: 14/09/2013
 *      Author: ezequiel
 */

#include "TextBox.h"
#define TAM_FUENTE 13
TextBox::TextBox(int x, int y, int w, int h, SDL_Texture* imagen) {

if (!TTF_Init()) cout << "Inicio bien" << endl;
this->x = x;
this->y = y ;
this->w = w;
this->h = h ;
this->imagen = imagen ;
this->fuente = TTF_OpenFont("resource/Arial Bold.ttf", TAM_FUENTE);
this->texto = "Escriba su texto aqui";
this->color.a = 50;
this->color.b = 20;
this->color.g = 20;
this->color.r = 200;
this->surfaceTexto = NULL;
this->textureTexto = NULL ;


}

TextBox::~TextBox() {	// TODO Auto-generated destructor stub
}

void TextBox::dibujarse(SDL_Renderer* render) {
	SDL_Rect dstFondo;
	dstFondo.x = this->x ;
	dstFondo.y =  this ->y;
	dstFondo.h = this->h ;
	dstFondo.w = this->w ;
	SDL_RenderCopy(render,this->imagen, NULL, &dstFondo);
	SDL_Rect dstTxt;
	dstTxt.x = this->x + 5;
	dstTxt.y = this->y ;
	dstTxt.h = this->h - 4 ;
	dstTxt.w = this->texto.size() * 8 ;



	this->surfaceTexto = TTF_RenderText_Solid(fuente, this->texto.c_str(), this->color);
	this->textureTexto = SDL_CreateTextureFromSurface(render, this->surfaceTexto);


	SDL_RenderCopy(render,this->textureTexto, NULL, &dstTxt);




}

void TextBox::agregarCaracter(char caracter) {
	this->texto += caracter ;


}

void TextBox::borrarCaracter() {
	this->texto.erase((this->texto.size()-1), 1);
}

void TextBox::setearTexto() {
	this->texto.clear();

}

bool TextBox::fueSeleccionado(int x, int y) {
	return false;

}

void TextBox::ejecutar() {
}
