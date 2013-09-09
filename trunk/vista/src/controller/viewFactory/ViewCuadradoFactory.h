/*
 * ViewCuadradoFactory.h
 *
 *  Created on: 05/09/2013
 *      Author: jonathan
 */

#ifndef VIEWCUADRADOFACTORY_H_
#define VIEWCUADRADOFACTORY_H_

#include "ViewFiguraFactory.h"
#include "SDL2/SDL.h"
class ViewCuadradoFactory: public ViewFiguraFactory {
public:
	ViewCuadradoFactory(SDL_Renderer * renderer);
	virtual ~ViewCuadradoFactory();
	FiguraView * crear(int, int,int,int);
	FiguraView * crearVistaPropia(int,int,int,int);
};

#endif /* VIEWCUADRADOFACTORY_H_ */
