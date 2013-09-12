/*
 * zonaToolBar.cpp
 *
 *  Created on: 12/09/2013
 *      Author: ezequiel
 */

#include "zonaToolBar.h"

zonaToolBar::zonaToolBar(int x, int y, int w, int h, SDL_Texture* texture) {
	this->fondo = texture ;

	this->x = x;
	this->y = y;
	this->w = w;
	this->h = h;



	//	render = SDL_
}

zonaToolBar::~zonaToolBar() {
	// TODO Auto-generated destructor stub
}

void zonaToolBar::agregarHerramienta(Herramientas* herramienta) {
	this->herramientas.push_back(herramienta);


}

void zonaToolBar::dibujarse(SDL_Renderer* render) {
	SDL_Rect dst;
	dst.x = this->x;
	dst.y = this->y;
	dst.h = this->h;
	dst.w= this->w;
	SDL_RenderCopy(render,this->fondo,NULL, &dst);
	list<Herramientas* >::iterator iter;
	 for(iter = this->herramientas.begin();iter != this->herramientas.end();iter++)
	{
		 	(*iter)->dibujarse(render);

	}

}
