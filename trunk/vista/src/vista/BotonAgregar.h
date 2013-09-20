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
#include "TextBox.h"
#include <iostream>
#include "Dibujable.h"
#include "Resizeable.h"
#include "Herramientas.h"
#include "View.h"

namespace std {

class Boton: public Herramientas {
protected:
	void cambiarASeleccion();
	void cambiarANormal();
	int seleccionado ;
	int cantDibujados;
public:
	Boton(int x, int y, int h, int w, SDL_Texture* textura, SDL_Texture* texturaSeleccionada) : Herramientas(x,y,h,w)
{
		 this->textura = textura ;
		 this->texturaCurrent = textura ;
		 this->texturaSeleccionada = texturaSeleccionada ;

		 this->seleccionado = false;
		 this->cantDibujados = 0;
}
	void dibujarse(SDL_Renderer *);
	void Resizear(int x, int y);
	virtual void presionarMouse() = 0 ;
	bool fueSeleccionado(int x, int y);
	void desPresionarMouse();
	void clickeoFueraDeHerramienta();
	void desEjecutarTecla() ;
	void resizear();
//	int x,y,h,w;
	SDL_Texture* textura;
	SDL_Texture* texturaCurrent;
	SDL_Texture* texturaSeleccionada;
	void ejecutarTecla(char key);



};

class BotonAgregar : public Boton {


public:
	BotonAgregar(int x, int y, int h, int w, SDL_Texture* textura, SDL_Texture* texturaSeleccionada) : Boton(x,y,h,w,textura, texturaSeleccionada)
	{

	}
	void presionarMouse();
	TextBox* campo;
	//virtual ~BotonAgregar();

};

class BotonSalir: public Boton {
public:
	BotonSalir(int x, int y, int h, int w, SDL_Texture* textura, SDL_Texture* texturaSeleccionada) : Boton(x,y,h,w,textura, texturaSeleccionada)
	{
		//constructor del boton salir
	}
	void presionarMouse();

};

class BotonGuardar: public Boton
{

public:
	BotonGuardar(int x, int y, int h, int w, SDL_Texture* textura, SDL_Texture* texturaSeleccionada) : Boton(x,y,h,w,textura, texturaSeleccionada)
	{

	}
	//TODO implementar la conexion con la persistencia
	void presionarMouse();

};

} /* namespace std */
#endif /* BOTONAGREGAR_H_ */
