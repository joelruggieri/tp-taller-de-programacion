/*
 * Background.cpp
 *
 *  Created on: 31/08/2013
 *      Author: ezequiel
 */

#include "Background.h"
using namespace std;


namespace std {



//Background::Background(int x, int y, int h, int w, SDL_Texture* textura, SDL_Renderer* render) {
//this->x = x;
//this->y = y;
//this->w = w;
//this->h = h;
//this->render = render;
//this->imagen = textura;
//
//}

Background::~Background() {
	// TODO Auto-generated destructor stub
}




/*void Background::Dibujarse()
{
	SDL_Rect dst ;
	dst.x = this->x;
	dst.y = this->y;
	dst.h = this->h;
	dst.w = this->w;
	SDL_RenderCopy(this->render, this->imagen,NULL,&dst);
	return;
}*/



void Background::Resizear(int x, int y)
{
	this->w = x;
	this->h = y;
}


}

