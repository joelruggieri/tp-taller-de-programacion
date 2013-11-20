/*
 * FactoryView.cpp
 *
 *  Created on: 21/09/2013
 *      Author: jonathan
 */

#include "FactoryView.h"
#include "SDL2/SDL.h"

namespace CLIENTE {
FactoryView::FactoryView(float x, float y, float w, float h, SDL_Texture * textura) :
		View(x, y, w, h, LAYER_FACTORIES) {
	this->textura = textura;
	TTF_Init();
	this->tamanoFuente = 12;
	this->fuente = TTF_OpenFont("resource/times.ttf", tamanoFuente);
	this->color.a = 0;
	this->color.b = 255;
	this->color.g = 255;
	this->color.r = 0;
	this->texto = "";
	this->xpc = 0;
	this->ypc = 0;
}

FactoryView::~FactoryView() {
	// TODO Auto-generated destructor stub
}

void FactoryView::dibujarse(SDL_Renderer * renderer) {
	dibujarFondo(renderer);
	SDL_Rect dest;
	generarConBorde(dest);
	SDL_RenderCopy(renderer, this->textura, NULL, &dest);
	dibujarBorde(renderer);
	dibujarCantidad(renderer);
}

void FactoryView::dibujarse(SDL_Renderer * renderer, SDL_Rect & dest) {

}

void FactoryView::update(ViewMsj* mje) {
	MensajeCantidadRestante* m = (MensajeCantidadRestante*) mje;
//	this->texto = std::to_string(this->cantidadRestante);
	stringstream s;
	s << m->getCantidadRestante();
	this->texto = s.str();
}

void FactoryView::dibujarFondo(SDL_Renderer* r) {
	SDL_Rect dest;
	dest.h = this->hp;
	dest.w = this->wp;
	dest.x = this->xp;
	dest.y = this->yp;
	SDL_SetRenderDrawColor(r, 170, 255, 214, 1);
	SDL_RenderFillRect(r, &dest);
}

void FactoryView::dibujarBordeIzquierdo(SDL_Renderer* renderer) {
	SDL_Rect dest;
	int corrimiento = 0;
	this->generarSinBorde(dest);
	dest.w = 3;
	dest.x = dest.x - corrimiento;
	dest.y = dest.y - corrimiento;
	dest.h = dest.h + corrimiento * 2;
	SDL_SetRenderDrawColor(renderer, CBORDE_EXTERNO.r,
			CBORDE_EXTERNO.g, CBORDE_EXTERNO.b, 1);
	SDL_RenderFillRect(renderer, &dest);
	dest.x = dest.x + 3;
	dest.y = dest.y + 3;
	dest.h = dest.h - 6;
	dest.w = 2;
	SDL_SetRenderDrawColor(renderer, CBORDE_INTERNO.r,
			CBORDE_INTERNO.g, CBORDE_INTERNO.b, 1);
	SDL_RenderFillRect(renderer, &dest);
}

void FactoryView::dibujarBordeDerecho(SDL_Renderer* renderer) {
	SDL_Rect dest;
	this->generarSinBorde(dest);
	dest.x = dest.x + dest.w - 3;
	dest.w = 3;
	SDL_SetRenderDrawColor(renderer, CBORDE_EXTERNO.r,
			CBORDE_EXTERNO.g, CBORDE_EXTERNO.b, 1);
	SDL_RenderFillRect(renderer, &dest);
	dest.x = dest.x - 2;
	dest.y = dest.y + 3;
	dest.h = dest.h - 6;
	dest.w = 2;
	SDL_SetRenderDrawColor(renderer, CBORDE_INTERNO.r,
			CBORDE_INTERNO.g, CBORDE_INTERNO.b, 1);
	SDL_RenderFillRect(renderer, &dest);
}

void FactoryView::dibujarBordeSuperior(SDL_Renderer* renderer) {
	SDL_Rect dest;
	this->generarSinBorde(dest);
	dest.h = 3;
	SDL_SetRenderDrawColor(renderer, CBORDE_EXTERNO.r,
			CBORDE_EXTERNO.g, CBORDE_EXTERNO.b, 1);
	SDL_RenderFillRect(renderer, &dest);
	dest.x = dest.x + 3;
	dest.y = dest.y + 3;
	dest.w = dest.w - 6;
	dest.h = 2;
	SDL_SetRenderDrawColor(renderer, CBORDE_INTERNO.r,
			CBORDE_INTERNO.g, CBORDE_INTERNO.b, 1);
	SDL_RenderFillRect(renderer, &dest);
}

void FactoryView::dibujarBordeInferior(SDL_Renderer* renderer) {
	SDL_Rect dest;
	this->generarSinBorde(dest);
	dest.y = dest.y + dest.h - 3;
	dest.h = 3;
	SDL_SetRenderDrawColor(renderer, CBORDE_EXTERNO.r,
			CBORDE_EXTERNO.g, CBORDE_EXTERNO.b, 1);
	SDL_RenderFillRect(renderer, &dest);
	dest.x = dest.x + 3;
	dest.y = dest.y - 2;
	dest.w = dest.w - 6;
	dest.h = 2;
	SDL_SetRenderDrawColor(renderer, CBORDE_INTERNO.r,
			CBORDE_INTERNO.g, CBORDE_INTERNO.b, 1);
	SDL_RenderFillRect(renderer, &dest);
}
void FactoryView::dibujarBorde(SDL_Renderer * renderer) {
	dibujarBordeIzquierdo(renderer);
	dibujarBordeDerecho(renderer);
	dibujarBordeSuperior(renderer);
	dibujarBordeInferior(renderer);
}

void FactoryView::generarSinBorde(SDL_Rect & dest) {
	dest.h = hp;
	dest.w = wp;
	dest.x = xp;
	dest.y = yp;
}

void FactoryView::generarConBorde(SDL_Rect & dest) {
	dest.h = hp - 12;
	dest.w = wp - 12;
	dest.x = xp + 6;
	dest.y = yp + 6;
}


bool FactoryView::isUpdated() {
	return true;
}
void FactoryView::dibujarCantidad(SDL_Renderer* renderer) {
	SDL_Rect dest;
	dest.x = this->xp+xpc;
	dest.y = this->yp;
	dest.w = 50;
	dest.h = 50;
	TTF_SizeUTF8(this->fuente, this->texto.c_str(), &(dest.w),  &(dest.h));
		 this->surfaceTexto = TTF_RenderText_Solid(fuente, this->texto.c_str(), this->color);
		 SDL_Texture* textureTexto = SDL_CreateTextureFromSurface(renderer, this->surfaceTexto);
		 SDL_RenderCopy(renderer,textureTexto, NULL, &dest);
	     SDL_FreeSurface(this->surfaceTexto);
	      SDL_DestroyTexture(textureTexto);


}

void FactoryView::resizear() {
	super::resizear();
	xpc = tl->escalarInversaEnX(10.5);
	ypc = tl->escalarInversaEnY(5);
}

}



