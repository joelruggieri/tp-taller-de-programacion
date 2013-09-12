/*
 * zonaToolBar.h
 *
 *  Created on: 12/09/2013
 *      Author: ezequiel
 */

#ifndef ZONATOOLBAR_H_
#define ZONATOOLBAR_H_
#include <list>
#include "../Vista/src/vista/Herramientas.h"
#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"
#include "../Vista/src/vista/Dibujable.h"

using namespace std;

class zonaToolBar  {
private:
	list<Herramientas* > herramientas ;

public:
	zonaToolBar(int x, int y, int w, int h, SDL_Texture* texture);
	virtual ~zonaToolBar();
	void agregarHerramienta(Herramientas* herramienta);

	SDL_Texture* fondo ;
	int x,y,h,w;
	void dibujarse(SDL_Renderer *render);



};

#endif /* ZONATOOLBAR_H_ */
