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
	dest.h = hp;
	dest.w = wp;
	dest.x = xp;
	dest.y = yp;
}


void Canvas::dibujarse(SDL_Renderer * renderer) {
	SDL_Rect dest;

	generarSinBorde(dest);
	this->dibujarse(renderer, dest);

}
void Canvas::dibujarse(SDL_Renderer * renderer, SDL_Rect& dest) {

	SDL_RenderCopy(renderer, this->imagenCanvas, NULL, &dest);

}

Canvas::Canvas(float x, float y, float w, float h, int layer, SDL_Texture* textura) :
		View(x, y, w, h,layer) {
	this->imagenCanvas = textura;
	this->border = false;
}

void Canvas::update(ViewMsj*) {
}


bool Canvas::isUpdated() {
	return true;
}
}
