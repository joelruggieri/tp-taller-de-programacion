/*
 * ViewTrianguloFactory.h
 *
 *  Created on: 05/09/2013
 *      Author: jonathan
 */

#ifndef VIEWTRIANGULOFACTORY_H_
#define VIEWTRIANGULOFACTORY_H_

#include "ViewFiguraFactory.h"

class ViewTrianguloFactory: public ViewFiguraFactory {
public:
	ViewTrianguloFactory(SDL_Renderer * renderer,DropController * controller);
	virtual ~ViewTrianguloFactory();
	FiguraView * crear(int, int, int, int);
	FiguraView * crearVistaPropia(int,int,int,int);
};

#endif /* VIEWTRIANGULOFACTORY_H_ */
