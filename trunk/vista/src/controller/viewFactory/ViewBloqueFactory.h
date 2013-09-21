/*
 * ViewBloqueFactory.h
 *
 *  Created on: 21/09/2013
 *      Author: joel
 */

#ifndef VIEWBLOQUEFACTORY_H_
#define VIEWBLOQUEFACTORY_H_
#include "ViewFiguraFactory.h"

class ViewBloqueFactory: public ViewFiguraFactory {
public:
	ViewBloqueFactory(DropController* controller);
	virtual ~ViewBloqueFactory();
	FiguraView * crear(int,int,int,int);
	FiguraView * crearVistaPropia(int,int,int,int);
};

#endif /* VIEWBLOQUEFACTORY_H_ */
