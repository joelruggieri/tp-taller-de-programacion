/*
 * ViewResorteFactory.h
 *
 *  Created on: 20/09/2013
 *      Author: joel
 */

#ifndef VIEWRESORTEFACTORY_H_
#define VIEWRESORTEFACTORY_H_
#include "ViewFiguraFactory.h"

class ViewResorteFactory: public ViewFiguraFactory{
public:
	ViewResorteFactory(DropController* controller);
	virtual ~ViewResorteFactory();
	FiguraView * crear(int, int,int,int);
	FiguraView * crearVistaPropia(int,int,int,int);
};

#endif /* VIEWRESORTEFACTORY_H_ */
