/*
 * Dragueable.cpp
 *
 *  Created on: 06/09/2013
 *      Author: ezequiel
 */

#include "Dragueable.h"

namespace std {

//Dragueable::Dragueable(int x, int y, int h, int w, SDL_Texture* textura, SDL_Renderer* render) {
//	// TODO En realidad aca no se haria el constructor pero va como prueba
//
//		this->x = x;
//		this->y = y;
//		this->w = w;
//		this->h = h;
//		this->render = render;
//		this->imagen = textura;
//
//
//
//}

Dragueable::~Dragueable() {
	// TODO Auto-generated destructor stub
}



bool Dragueable::Draguear(int nuevoX, int nuevoY)	//nuevoX = posicionInicialMouseX - posicionFinalMouseX (idemY)
//chequear los limites del dragueo y los lugares lícitos para dejar el dragueable
{
	this->x -= nuevoX;
	this->y -= nuevoY;

	return true;
}

//bool Dragueable::FueSeleccionado(int x, int y)
//{
//	if ((x <= this->x + this->w) and ( x >= this->x ) and (y <= this->y + this->h) and ( y>= this->y))
//			return true;
//	else
//		return false;
//}

}
