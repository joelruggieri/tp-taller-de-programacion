/*
 *
 * BotonAgregar.cpp
 *
 *  Created on: 31/08/2013
 *      Author: ezequiel
 */

#include "BotonAgregar.h"

namespace std {

BotonAgregar::BotonAgregar(int x, int y, SDL_Texture* imagen, SDL_Renderer* renderer,int ancho, int alto) {
	// TODO Auto-generated constructor stub
	 this->imagen = imagen ;
	 this->render = renderer;
	 this->x = x;
	 this->y = y;
	 this->w = ancho;
	 this->h = alto ;

	// SDL_QueryTexture(imagen, )

}

BotonAgregar::~BotonAgregar() {
	// TODO Auto-generated destructor stub
}



/*void BotonAgregar::Dibujarse(){
	SDL_Rect dst ;
	dst.x = this->positionX;
	dst.y = this->positionY;
	dst.h = this->alto;
	dst.w = this->ancho;
	SDL_RenderCopy(this->renderer, this->imagenBoton,NULL,&dst);
	return;

}*/

bool BotonAgregar::FueSeleccionado(int x, int y)
{
	if ((x <= this->x + this->w) and ( x >= this->x ) and (y <= this->y + this->h) and ( y>= this->y))
			return true;
	else
		return false;
}



int BotonAgregar::ModificarFondo(Canvas* fondo, char* rutaNueva)
{
fondo->ModificarFondo(rutaNueva);
return 0;
}

void BotonAgregar::Resizear(int x , int y)
{
	this->x = this->x + x;
	this->y = this->y + y;
}






}

