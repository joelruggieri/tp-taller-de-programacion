/*
 * FiguraFactory.h
 *
 *  Created on: 04/09/2013
 *      Author: jonathan
 */

#ifndef FIGURAFACTORY_H_
#define FIGURAFACTORY_H_
#include "../figura/Figura.h"

class FiguraFactory {
public:
	FiguraFactory();
	virtual ~FiguraFactory();
	Figura * crearCuadrado(float x,float y);
	Figura * crearCirculo();
	Figura * crearTriangulo();
};

#endif /* FIGURAFACTORY_H_ */
