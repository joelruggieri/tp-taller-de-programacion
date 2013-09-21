/*
 * ViewCarritoFactory.h
 *
 *  Created on: 21/09/2013
 *      Author: joel
 */

#ifndef VIEWCARRITOFACTORY_H_
#define VIEWCARRITOFACTORY_H_
#include"ViewFiguraFactory.h"

class ViewCarritoFactory: public ViewFiguraFactory {
public:
	ViewCarritoFactory(DropController* controller);
	virtual ~ViewCarritoFactory();
	FiguraView * crear(int,int,int,int);
	FiguraView * crearVistaPropia(int,int,int,int);
};

#endif /* VIEWCARRITOFACTORY_H_ */
