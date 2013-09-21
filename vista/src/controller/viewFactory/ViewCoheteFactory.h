/*
 * ViewCoheteFactory.h
 *
 *  Created on: 21/09/2013
 *      Author: joel
 */

#ifndef VIEWCOHETEFACTORY_H_
#define VIEWCOHETEFACTORY_H_
#include "ViewFiguraFactory.h"

class ViewCoheteFactory: public ViewFiguraFactory {
public:
	ViewCoheteFactory(DropController* controller);
	virtual ~ViewCoheteFactory();
	FiguraView * crear(int,int,int,int);
	FiguraView * crearVistaPropia(int,int,int,int);
};

#endif /* VIEWCOHETEFACTORY_H_ */
