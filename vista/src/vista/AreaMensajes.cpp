/*
 * AreaMensajes.cpp
 *
 *  Created on: 19/11/2013
 *      Author: ezequiel
 */

#include "AreaMensajes.h"
namespace CLIENTE {

AreaMensajes::AreaMensajes(float x, float y, float w, float h, SDL_Texture* textura, string mensaje): View(x,y,w,h,30) {
TTF_Init();
this->textura = textura ;
this->texto = mensaje ;
this->fuente = TTF_OpenFont("resource/times.ttf", TAM_FUENTE);
this->color.a = 50;
this->color.b = 0;
this->color.g = 255;
this->color.r = 0;
}

AreaMensajes::~AreaMensajes() {
	// TODO Auto-generated destructor stub
}

void AreaMensajes::dibujarse(SDL_Renderer* render) {
	SDL_Rect dest;
	dest.h = this->hp;
	dest.w = this->wp;
	dest.x = this->xp;
	dest.y = this->yp;
	SDL_RenderCopy(render,this->textura, NULL, &dest);
//	dest.h = 75;
//	dest.w = this->texto.length() * 4;
	dest.x = this->xp+10;
	dest.y = this->yp+7;
//	TTF_SizeText(this->fuente, this->texto.c_str(), &(dest.w), NULL);
	TTF_SizeUTF8(this->fuente, this->texto.c_str(), &(dest.w), &(dest.h));
	 this->surfaceTexto = TTF_RenderText_Solid(fuente, this->texto.c_str(), this->color);
	 SDL_Texture* textureTexto = SDL_CreateTextureFromSurface(render, this->surfaceTexto);
	 SDL_RenderCopy(render,textureTexto, NULL, &dest);
}

void AreaMensajes::update(ViewMsj*) {
}

//void AreaMensajes::resize() {
//}

bool AreaMensajes::isUpdated() {
	return true;
}

void AreaMensajes::dibujarse(SDL_Renderer*, SDL_Rect&) {
}
} /* namespace CLIENTE */

