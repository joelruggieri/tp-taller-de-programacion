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
this->tamanoFuente = TAM_FUENTE;
this->fuente = TTF_OpenFont("resource/times.ttf", tamanoFuente);
this->color.a = 50;
this->color.b = 0;
this->color.g = 255;
this->color.r = 0;

}

AreaMensajes::~AreaMensajes() {
	TTF_CloseFont(fuente);
	TTF_Quit();
}

void AreaMensajes::dibujarse(SDL_Renderer* render) {
	SDL_Rect dest;
	dest.h = this->hp;
	dest.w = this->wp;
	dest.x = this->xp;
	dest.y = this->yp;
	SDL_RenderCopy(render,this->textura, NULL, &dest);
	dest.h = this->hp;
//	dest.w = this->texto.length() * 4;
	dest.x = this->xp+10;
	dest.y = this->yp;
//	TTF_SizeText(this->fuente, this->texto.c_str(), &(dest.w), NULL);
	TTF_SizeUTF8(this->fuente, this->texto.c_str(), &(dest.w), NULL);
	 this->surfaceTexto = TTF_RenderText_Solid(fuente, this->texto.c_str(), this->color);
	 SDL_Texture* textureTexto = SDL_CreateTextureFromSurface(render, this->surfaceTexto);
	 SDL_RenderCopy(render,textureTexto, NULL, &dest);
     SDL_FreeSurface(this->surfaceTexto);
        SDL_DestroyTexture(textureTexto);
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

void AreaMensajes::setMensaje(string mensaje) {
	this->texto = mensaje;
}

void AreaMensajes::resizear() {
	super::resizear();


}

} /* namespace CLIENTE */

