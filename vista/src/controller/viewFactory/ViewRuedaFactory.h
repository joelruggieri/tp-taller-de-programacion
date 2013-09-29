/*
 * ViewRuedaFactory.h
 *
 *  Created on: 19/09/2013
 *      Author: joel
 */

#ifndef VIEWRUEDAFACTORY_H_
#define VIEWRUEDAFACTORY_H_

#include "ViewFiguraFactory.h"
class ViewRuedaFactory: public ViewFiguraFactory {
public:
	ViewRuedaFactory(DropController * controller);
	virtual ~ViewRuedaFactory();
	FiguraView * crear(int,int,int,int);
	View * crearVistaPropia(int,int,int,int);
};

#endif /* VIEWRUEDAFACTORY_H_ */
