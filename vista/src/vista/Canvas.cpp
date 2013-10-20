/*
 * Canvas.cpp
 *
 *  Created on: 31/08/2013
 *      Author: ezequiel
 */

#include "Canvas.h"
#include "SDL2/SDL.h"
#include "LayerDibujablesComparator.h"

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
	this->vistas.sort(comparar_layers);
}

void Canvas::agregar(Dibujable* vista) {
	this->vistas.push_back(vista);
	this->vistas.sort(comparar_layers);
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


void Canvas::generarSinBorde(SDL_Rect & dest) {
	dest.h = this->getH();
	dest.w = this->getW();
	dest.x = this->getX();
	dest.y = this->getY();
}


void Canvas::dibujarse(SDL_Renderer * renderer) {
	SDL_Rect dest;

	generarSinBorde(dest);
	this->dibujarse(renderer, dest);
//	SDL_RenderCopy(renderer, this->imagenCanvas, NULL, &dest);
//	std::list<Dibujable*>::const_iterator it;
//	for (it = vistas.begin(); it != vistas.end(); ++it) {
//		(*it)->dibujar(renderer);
//	}

}
void Canvas::dibujarse(SDL_Renderer * renderer, SDL_Rect& dest) {

	SDL_RenderCopy(renderer, this->imagenCanvas, NULL, &dest);
	std::list<Dibujable*>::const_iterator it;
	for (it = vistas.begin(); it != vistas.end(); ++it) {
		(*it)->dibujarse(renderer);
	}

}

Canvas::Canvas(int x, int y, int w, int h, SDL_Texture* textura) :
		View(x, y, w, h) {
	this->imagenCanvas = textura;
	this->border = false;
}

const list<Dibujable*>& Canvas::getVistas() {
	return (this->vistas);
}

void Canvas::resizear() {
//	int wFinal, hFinal, xFinal, yFinal;

this->setW(Resizer::Instance()->resizearDistanciaX(this->getW()));
this->setXc(Resizer::Instance()->resizearDistanciaX(this->getXCentro()));
this->setH(Resizer::Instance()->resizearDistanciaY(this->getH()));
this->setYc((Resizer::Instance()->resizearPosicionY(this->getYCentro())));
//	TODO resizear
}
