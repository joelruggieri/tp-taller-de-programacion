/*
 * AreaMensajes.cpp
 *
 *  Created on: 19/11/2013
 *      Author: ezequiel
 */

#include "AreaMensajes.h"
namespace CLIENTE {

AreaMensajes::AreaMensajes(float x, float y, float w, float h, SDL_Texture* textura, string mensaje) :
		View(x, y, w, h, 30) {
	TTF_Init();
	this->textura = textura;
	this->texto = mensaje;
	this->tamanoFuente = TAM_FUENTE;
	this->fuente = TTF_OpenFont("resource/times.ttf", tamanoFuente);
	this->color.a = 50;
	this->color.b = 0;
	this->color.g = 255;
	this->color.r = 0;
	debeActualizar = true;
	textureTexto = NULL;
	surfaceTexto = NULL;
}

AreaMensajes::~AreaMensajes() {
	TTF_CloseFont(fuente);
	TTF_Quit();
}

void AreaMensajes::dibujarse(SDL_Renderer* renderer) {
	if (debeActualizar) {
		dest.h = this->hp;
		dest.w = this->wp;
		dest.x = this->xp + 10;
		dest.y = this->yp;
		if (surfaceTexto)
			SDL_FreeSurface(this->surfaceTexto);
		if (textureTexto)
			SDL_DestroyTexture(textureTexto);
		TTF_SizeUTF8(this->fuente, this->texto.c_str(), &(dest.w), &(dest.h));
		this->surfaceTexto = TTF_RenderText_Solid(fuente, this->texto.c_str(), this->color);
		textureTexto = SDL_CreateTextureFromSurface(renderer, this->surfaceTexto);
		debeActualizar = false;
	}
		SDL_Rect dest2;
		dest2.h = hp;
		dest2.w = wp;
		dest2.x = xp;
		dest2.y = yp;
		SDL_RenderCopy(renderer, this->textura, NULL, &dest2);
		SDL_RenderCopy(renderer, textureTexto, NULL, &dest);
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
	debeActualizar = true;
	this->texto = mensaje;
}

void AreaMensajes::resizear() {
	super::resizear();

}

} /* namespace CLIENTE */

