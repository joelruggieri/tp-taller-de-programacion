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
#include "Herramientas.h"
namespace std {

class Boton: public Herramientas {
public:
	Boton(int x, int y, int h, int w, SDL_Texture* textura);
	void dibujarse(SDL_Renderer *);
	void Resizear(int x, int y);
	virtual void ejecutar() = 0 ;
	int x,y,h,w;
	SDL_Texture* textura;


};

class BotonAgregar : public Boton {


public:
	BotonAgregar(int x, int y, int h, int w, SDL_Texture* textura) : Boton(x,y,h,w,textura)
	{

	}
	void ejecutar();
	//virtual ~BotonAgregar();
	int ModificarFondo(Canvas* fondo,char* rutaNueva);

};

class BotonSalir: public Boton {
public:
	BotonSalir(int x, int y, int h, int w, SDL_Texture* textura) : Boton(x,y,h,w,textura)
	{
		//constructor del boton salir
	}
	void ejecutar();

};

class BotonGuardar: public Boton
{
	BotonGuardar(int x, int y, int h, int w, SDL_Texture* textura) : Boton(x,y,h,w,textura)
	{

	}
	//TODO implementar la conexion con la persistencia
	void ejecutar();
};

} /* namespace std */
#endif /* BOTONAGREGAR_H_ */
