/*
 * BotonAgregar.h
 *
 *  Created on: 31/08/2013
 *      Author: ezequiel
 */

#ifndef BOTONAGREGAR_H_
#define BOTONAGREGAR_H_
#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"
#include "Canvas.h"
#include <iostream>
#include "Dibujable.h"
#include "Resizeable.h"
#include"Seleccionable.h"
#include "Herramientas.h"
namespace std {

class Boton: public Herramientas {
public:
	Boton(int x, int y, int h, int w, SDL_Texture* textura, SDL_Renderer* render);

	void Resizear(int x, int y);
	virtual void ejecutar() = 0 ;


};

class BotonAgregar : public Boton {


public:
	BotonAgregar(int x, int y, int h, int w, SDL_Texture* textura, SDL_Renderer* render) : Boton(x,y,h,w,textura, render)
	{

	}
	//virtual ~BotonAgregar();
	int ModificarFondo(Canvas* fondo,char* rutaNueva);

};

class BotonSalir: public Boton {
public:
	BotonSalir(int x, int y, int h, int w, SDL_Texture* textura, SDL_Renderer* render) : Boton(x,y,h,w,textura, render)
	{
		//constructor del boton salir
	}


};

class BotonGuardar: public Boton
{
	BotonGuardar(int x, int y, int h, int w, SDL_Texture* textura, SDL_Renderer* render) : Boton(x,y,h,w,textura, render)
	{

	}
	//TODO implementar la conexion con la persistencia

};

} /* namespace std */
#endif /* BOTONAGREGAR_H_ */
