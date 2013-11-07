/*
 * Canvas.cpp
 *
 *  Created on: 31/08/2013
 *      Author: ezequiel
 */

#include "Canvas.h"
#include "SDL2/SDL.h"
#include "LayerDibujablesComparator.h"

namespace CLIENTE {
//SDL_Texture* cargarTexture (char* file, SDL_Renderer* ren){
////	SDL_Texture* texture = IMG_LoadTexture(ren, file );
//
////	if (texture == NULL) cout << "IMG_Load error: " << IMG_GetError() <<endl;
//
//	return texture;
//}

Canvas::~Canvas() {
}

void Canvas::ModificarFondo(SDL_Texture* nuevaImagen) {
	this->imagenCanvas = nuevaImagen;
}


void Canvas::generarSinBorde(SDL_Rect & dest) {
//	dest.h = this->getH();
//	dest.w = this->getW();
//	dest.x = this->getX();
//	dest.y = this->getY();
}


void Canvas::dibujarse(SDL_Renderer * renderer) {
	SDL_Rect dest;

	generarSinBorde(dest);
	this->dibujarse(renderer, dest);

}
void Canvas::dibujarse(SDL_Renderer * renderer, SDL_Rect& dest) {

	SDL_RenderCopy(renderer, this->imagenCanvas, NULL, &dest);

}

Canvas::Canvas(int x, int y, int w, int h, SDL_Texture* textura) :
		View(x, y, w, h) {
	this->imagenCanvas = textura;
	this->border = false;
}

void Canvas::resizear() {
////	int wFinal, hFinal, xFinal, yFinal;
// ENTREGA3 USAR GETTL
//this->setW(Resizer::Instance()->resizearDistanciaX(this->getW()));
//this->setXc(Resizer::Instance()->resizearDistanciaX(this->getXCentro()));
//this->setH(Resizer::Instance()->resizearDistanciaY(this->getH()));
//this->setYc((Resizer::Instance()->resizearPosicionY(this->getYCentro())));

//	TODO resizear
}

void Canvas::update(ViewMsj*) {
}

}
