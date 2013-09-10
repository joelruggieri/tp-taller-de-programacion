/*
 * Canvas.h
 *
 *  Created on: 31/08/2013
 *      Author: ezequiel
 */

#ifndef CANVAS_H_
#define CANVAS_H_
#include "SDL2/SDL_image.h"
#include "SDL2/SDL.h"
#include <iostream>
#include "View.h"
#include "Resizeable.h"
#include <list>
using namespace std;


class Canvas: public View{
	 SDL_Texture* imagenCanvas;
	 list<Dibujable*> vistas;
public:
	Canvas(int x, int y, int h, int w, SDL_Texture* textura);
	void dibujarse(SDL_Renderer *);
	virtual ~Canvas();
	int ModificarFondo(char* rutaNueva);
	void agregar(Dibujable *);
	void remover(Dibujable *);
	//void Resizear(int x, int y);
	const list<Dibujable*>& getDibujables() const;
};

#endif /* CANVAS_H_ */
