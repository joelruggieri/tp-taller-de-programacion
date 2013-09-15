/*
 *
 * BotonAgregar.cpp
 *
 *  Created on: 31/08/2013
 *      Author: ezequiel
 */

#include "BotonAgregar.h"

namespace std {

void BotonAgregar::ejecutar() {
	//TODO ejecutar del boton agregar
	cout << "se ha ejecutado el boton Agregar" << endl;
}

Boton::Boton(int x, int y, int h, int w, SDL_Texture* textura) {
	// TODO Auto-generated constructor stub
	 this->textura = textura ;
	 this->x = x;
	 this->y = y;
	 this->w = w;
	 this->h = h ;



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

//bool BotonAgregar::FueSeleccionado(int x, int y)
//{
//	if ((x <= this->x + this->w) and ( x >= this->x ) and (y <= this->y + this->h) and ( y>= this->y))
//			return true;
//	else
//		return false;
//}



int BotonAgregar::ModificarFondo(Canvas* fondo, char* rutaNueva)
{
fondo->ModificarFondo(rutaNueva);
return 0;
}

//void Boton::Resizear(int x , int y)
//{
////	this->x = this->x + x;
//	this->y = this->y + y;
//}








void std::BotonSalir::ejecutar() {
	//TODO ejecutar del boton salir
	cout << "se ha ejecutado el boton salir" << endl;
}

void std::BotonGuardar::ejecutar() {
	//TODO ejecutar del boton guardar
	cout << "se ha ejecutado el boton guardar" << endl;
}

void Boton::dibujarse(SDL_Renderer* render) {

SDL_Rect dst ;
dst.x = this->x;
dst.y = this->y;
dst.h = this->h;
dst.w = this->w;
SDL_RenderCopy(render, this->textura,NULL,&dst);
return;
}

bool Boton::fueSeleccionado(int x, int y) {
	if (this->x <= x && this->x + this->w > x && this->y <= y && this->y + this->y > y )
			return true;
	else
		return false;
}

}
