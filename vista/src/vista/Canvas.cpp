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

int Canvas::ModificarFondo(char* rutaNueva)
{
//	this->imagen = cargarTexture(rutaNueva,this->render);
	return 0;
}


void Canvas::dibujarse(SDL_Renderer * renderer){
	SDL_Rect dest;
	dest.h = this->getH();
	dest.w = this->getW();
	dest.x = this->getX();
	dest.y = this->getY();
	SDL_RenderCopy(renderer,this->imagenCanvas,NULL,&dest);
	std::list<Dibujable*>::const_iterator it;
	for (it = vistas.begin(); it != vistas.end(); ++it) {
		(*it)->dibujarse(renderer);
	}

}

Canvas::Canvas(int x, int y, int w, int h, SDL_Texture* textura): View(x,y,w,h) {
	this->imagenCanvas = textura;
}
