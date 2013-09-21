/*
 * ViewMartilloFactory.h
 *
 *  Created on: 20/09/2013
 *      Author: joel
 */

#ifndef VIEWMARTILLOFACTORY_H_
#define VIEWMARTILLOFACTORY_H_
#include "ViewFiguraFactory.h"

class ViewMartilloFactory: public ViewFiguraFactory {
public:
	ViewMartilloFactory(DropController* controller);
	virtual ~ViewMartilloFactory();
	FiguraView * crear(int, int,int,int);
	FiguraView * crearVistaPropia(int,int,int,int);
};

#endif /* VIEWMARTILLOFACTORY_H_ */
