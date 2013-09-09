/*
 * ViewCirculoFactory.h
 *
 *  Created on: 05/09/2013
 *      Author: jonathan
 */

#ifndef VIEWCIRCULOFACTORY_H_
#define VIEWCIRCULOFACTORY_H_

#include "ViewFiguraFactory.h"
#include "SDL2/SDL.h"
class ViewCirculoFactory: public ViewFiguraFactory {
public:
	ViewCirculoFactory(SDL_Renderer * renderer,DropController * controller);
	virtual ~ViewCirculoFactory();
	FiguraView * crear(int,int,int,int);
	FiguraView * crearVistaPropia(int,int,int,int);
};

#endif /* VIEWCIRCULOFACTORY_H_ */
