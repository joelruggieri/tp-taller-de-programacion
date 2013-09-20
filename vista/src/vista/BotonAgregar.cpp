/*
 *
 * BotonAgregar.cpp
 *
 *  Created on: 31/08/2013
 *      Author: ezequiel
 */

#include "BotonAgregar.h"
#include "../controller/UserEventCreator.h"
#include "SDL2/SDL.h"

namespace std {

void BotonAgregar::presionarMouse() {
	if (this->seleccionado == false)
	{
	this->seleccionado = true;
	this->cambiarASeleccion();
	SDL_Event evento = crearEvento(USREVENT_CHANGEBACKGROUND, this->campo->getTexto(), NULL);
	SDL_PushEvent(&evento);
	return;
	}

}

//Boton::Boton(int x, int y, int h, int w, SDL_Texture* textura, SDL_Texture* texturaSeleccionada) {
//	// TODO Auto-generated constructor stub
//	 this->textura = textura ;
//	 this->texturaCurrent = textura ;
//	 this->texturaSeleccionada = texturaSeleccionada ;
//
//	 this->seleccionado = false;
//	 this->cantDibujados = 0;
//
//
//
//}


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


//void Boton::Resizear(int x , int y)
//{
////	this->x = this->x + x;
//	this->y = this->y + y;
//}


void std::BotonSalir::presionarMouse() {
	if (this->seleccionado == false)
	{
	this->seleccionado = true;
	this->cambiarASeleccion();
	SDL_Event evento = crearEvento(USREVENT_QUIT, NULL, NULL);
	SDL_PushEvent(&evento);
	//cout << "se ha ejecutado el boton salir" << endl;
	return;
	}

}

void std::BotonGuardar::presionarMouse() {
	if (this->seleccionado == false)
	{
	this->seleccionado = true;
	this->cambiarASeleccion();
	SDL_Event evento = crearEvento(USREVENT_SAVEGAME, NULL, NULL);
	SDL_PushEvent(&evento);
	//cout << "se ha ejecutado el boton guardar" << endl;
	return;
	}

}

void Boton::dibujarse(SDL_Renderer* render) {

SDL_Rect dst ;
dst.x = this->getX();
dst.y = this->getY();
dst.h = this->getH();
dst.w = this->getW();
SDL_RenderCopy(render, this->texturaCurrent,NULL,&dst);
return;

}

bool Boton::fueSeleccionado(int x, int y) {
	//TODO calcular la seleccion con el radio, por ser redondos
	int radio = this->getH() / 2 ;
	int xc = this->getXCentro();
	int yc = this->getYCentro();
	int xe = this->getX();
	int ye = this->getY();
	int w = this->getW();
	int h = this->getH();
	if (xe <= x && xe + w > x && ye <= y && ye + h > y && sqrt((x-xc)*(x-xc)+(y-yc)*(y-yc)) <= radio)
	{
		//&& sqrt((x-xc)*(x-xc)+(y-yc)*(y-yc) < radio)
	//out << sqrt((x-xc)*(x-xc)+(y-yc)*(y-yc)) << " " << radio <<  endl  ;

		return true;
	}

	else
		return false;
}

void Boton::cambiarASeleccion()
{
	if (this->texturaCurrent == this->textura)
	this->texturaCurrent = this->texturaSeleccionada ;

}



void std::Boton::cambiarANormal() {
	if (this->texturaCurrent == this->texturaSeleccionada)
		this->texturaCurrent = this->textura ;
}

void Boton::desPresionarMouse() {
	if (this->seleccionado)
	{
		this->seleccionado = false;
		this->cambiarANormal();
	}
}

void Boton::ejecutarTecla(char key) {
	//NADA
}

}

void Boton::clickeoFueraDeHerramienta() {
}

void Boton::desEjecutarTecla() {
}

void Boton::resizear() {
	this->setYc(Resizer::Instance()->resizearDistanciaY(this->getYCentro()));
	this->setXc(Resizer::Instance()->resizearDistanciaX(this->getXCentro()));
//	this->setW(Resizer::Instance()->resizearDistanciaX(this->getW()));
//	this->setH(Resizer::Instance()->resizearDistanciaY(this->getH()));
}
