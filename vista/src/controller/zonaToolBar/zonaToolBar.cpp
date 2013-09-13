/*
 * zonaToolBar.cpp
 *
 *  Created on: 12/09/2013
 *      Author: ezequiel
 */

#include "zonaToolBar.h"
#define anchoBoton 10
#define altoBoton 10

zonaToolBar::zonaToolBar(int x, int y, int w, int h, SDL_Texture* texture) {
	this->fondo = texture ;

	this->x = x;
	this->y = y;
	this->w = w;
	this->h = h;
	CargadorDeTextures *p1 = CargadorDeTextures::Instance();
	BotonAgregar* bAgregar = new BotonAgregar(x+100, y+20, anchoBoton, altoBoton, p1->cargarTexture("botonAgregar.jpg") );
	BotonSalir* bSalir = new BotonSalir(x+130, y + 20, anchoBoton, altoBoton, p1->cargarTexture("botonSalir.jpg"));
	this->agregarHerramienta(bAgregar);
	this->agregarHerramienta(bSalir);


//	this->agregarHerramienta(new



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
