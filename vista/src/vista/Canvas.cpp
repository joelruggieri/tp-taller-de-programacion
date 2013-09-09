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

//Canvas::Canvas(int x, int y, int h, int w, SDL_Texture* textura, SDL_Renderer* render) {
//	this->x = x;
//	this->y = y;
//	this->w = w;
//	this->h = h;
//	this->render = render;
//	this->imagen = textura;
//
//}

Canvas::~Canvas() {
	// TODO Auto-generated destructor stub
}

int CalcularNuevaCoordenada(int newCoord, int oldCoord)
{

return newCoord + oldCoord;
}


/*void Canvas::Dibujarse()
{
	SDL_Rect dst ;
	dst.x = this->x;
	dst.y = this->y;
	dst.h = this->h;
	dst.w = this->w;
	SDL_RenderCopy(this->render, this->imagenCanvas,NULL,&dst);
	return;

}*/

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
}

Canvas::Canvas(int x, int y, int w, int h, SDL_Texture* textura): View(x,y,w,h) {
	this->imagenCanvas = textura;
}
