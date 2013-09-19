/*
 * Canvas.cpp
 *
 *  Created on: 31/08/2013
 *      Author: ezequiel
 */

#include "Canvas.h"
#include "SDL2/SDL.h"

//SDL_Texture* cargarTexture (char* file, SDL_Renderer* ren){
////	SDL_Texture* texture = IMG_LoadTexture(ren, file );
//
////	if (texture == NULL) cout << "IMG_Load error: " << IMG_GetError() <<endl;
//
//	return texture;
//}

Canvas::~Canvas() {
	std::list<Dibujable*>::const_iterator it;
	for (it = vistas.begin(); it != vistas.end(); ++it) {
		delete (*it);
	}
}

void Canvas::remover(Dibujable* vista) {
	this->vistas.remove(vista);
}

void Canvas::agregar(Dibujable* vista) {
	this->vistas.push_back(vista);
}

const list<Dibujable*>& Canvas::getDibujables() const {
	return vistas;
}

/*void Canvas::Resizear(int x, int y)
 {
 this->w = this->w + x;
 this->h = this->h + y;

 }*/

void Canvas::ModificarFondo(SDL_Texture* nuevaImagen) {
	this->imagenCanvas = nuevaImagen;
}

//robo 3 pixels.
void Canvas::generarConBorde(SDL_Rect & dest) {
	dest.h = this->getH() - 10;
	dest.w = this->getW() - 10;
	dest.x = this->getX() + 5;
	dest.y = this->getY() + 5;
}

void Canvas::generarSinBorde(SDL_Rect & dest) {
	dest.h = this->getH();
	dest.w = this->getW();
	dest.x = this->getX();
	dest.y = this->getY();
}

void Canvas::dibujarBordeIzquierdo(SDL_Renderer* renderer) {
	SDL_Rect dest;
	this->generarSinBorde(dest);
	dest.w = 3;
	SDL_SetRenderDrawColor(renderer, COLOR_BORDE_EXTERNO.r,
			COLOR_BORDE_EXTERNO.g, COLOR_BORDE_EXTERNO.b, 1);
	SDL_RenderFillRect(renderer, &dest);
	dest.x = dest.x + 3;
	dest.y = dest.y + 3;
	dest.h = dest.h - 6;
	dest.w = 2;
	SDL_SetRenderDrawColor(renderer, COLOR_BORDE_INTERNO.r,
			COLOR_BORDE_INTERNO.g, COLOR_BORDE_INTERNO.b, 1);
	SDL_RenderFillRect(renderer, &dest);
}

void Canvas::dibujarBordeDerecho(SDL_Renderer* renderer) {
	SDL_Rect dest;
	this->generarSinBorde(dest);
	dest.x = dest.x + dest.w - 3;
	dest.w = 3;
	SDL_SetRenderDrawColor(renderer, COLOR_BORDE_EXTERNO.r,
			COLOR_BORDE_EXTERNO.g, COLOR_BORDE_EXTERNO.b, 1);
	SDL_RenderFillRect(renderer, &dest);
	dest.x = dest.x - 2;
	dest.y = dest.y + 3;
	dest.h = dest.h - 6;
	dest.w = 2;
	SDL_SetRenderDrawColor(renderer, COLOR_BORDE_INTERNO.r,
			COLOR_BORDE_INTERNO.g, COLOR_BORDE_INTERNO.b, 1);
	SDL_RenderFillRect(renderer, &dest);
}

void Canvas::dibujarBordeSuperior(SDL_Renderer* renderer) {
	SDL_Rect dest;
	this->generarSinBorde(dest);
	dest.h = 3;
	SDL_SetRenderDrawColor(renderer, COLOR_BORDE_EXTERNO.r,
			COLOR_BORDE_EXTERNO.g, COLOR_BORDE_EXTERNO.b, 1);
	SDL_RenderFillRect(renderer, &dest);
	dest.x = dest.x + 3;
	dest.y = dest.y + 3;
	dest.w = dest.w - 6;
	dest.h = 2;
	SDL_SetRenderDrawColor(renderer, COLOR_BORDE_INTERNO.r,
			COLOR_BORDE_INTERNO.g, COLOR_BORDE_INTERNO.b, 1);
	SDL_RenderFillRect(renderer, &dest);
}

void Canvas::dibujarBordeInferior(SDL_Renderer* renderer) {
	SDL_Rect dest;
	this->generarSinBorde(dest);
	dest.y = dest.y + dest.h - 3;
	dest.h = 3;
	SDL_SetRenderDrawColor(renderer, COLOR_BORDE_EXTERNO.r,
			COLOR_BORDE_EXTERNO.g, COLOR_BORDE_EXTERNO.b, 1);
	SDL_RenderFillRect(renderer, &dest);
	dest.x = dest.x + 3;
	dest.y = dest.y - 2;
	dest.w = dest.w - 6;
	dest.h = 2;
	SDL_SetRenderDrawColor(renderer, COLOR_BORDE_INTERNO.r,
			COLOR_BORDE_INTERNO.g, COLOR_BORDE_INTERNO.b, 1);
	SDL_RenderFillRect(renderer, &dest);
}
void Canvas::dibujarBorde(SDL_Renderer * renderer) {
	dibujarBordeIzquierdo(renderer);
	dibujarBordeDerecho(renderer);
	dibujarBordeSuperior(renderer);
	dibujarBordeInferior(renderer);
}
void Canvas::dibujarse(SDL_Renderer * renderer) {
	SDL_Rect dest;

	if (this->border) {
		generarConBorde(dest);
	} else {
		generarSinBorde(dest);
	}
	SDL_RenderCopy(renderer, this->imagenCanvas, NULL, &dest);
	std::list<Dibujable*>::const_iterator it;
	for (it = vistas.begin(); it != vistas.end(); ++it) {
		(*it)->dibujarse(renderer);
	}
	if (this->border) {
		this->dibujarBorde(renderer);
	}

}

Canvas::Canvas(int x, int y, int w, int h, SDL_Texture* textura) :
		View(x, y, w, h) {
	this->imagenCanvas = textura;
	this->border = false;
}

bool Canvas::isBorder() const {
	return border;
}

void Canvas::setBorder(bool border) {
	this->border = border;
}

const list<Dibujable*>& Canvas::getVistas() {
	return (this->vistas);
}

void Canvas::resizear() {
	cout << "canvas resizeado" << endl;
//	int wFinal, hFinal, xFinal, yFinal;

this->setW(Resizer::Instance()->resizearDistanciaX(this->getW()));
this->setXc(Resizer::Instance()->resizearDistanciaX(this->getXCentro()));
this->setH(Resizer::Instance()->resizearDistanciaY(this->getH()));
this->setYc((Resizer::Instance()->resizearDistanciaY(this->getYCentro())));
//	TODO resizear
}
