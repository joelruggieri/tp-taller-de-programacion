/*
 * ViewCorreaFactory.h
 *
 *  Created on: 15/10/2013
 *      Author: joel
 */

#ifndef VIEWCORREAFACTORY_H_
#define VIEWCORREAFACTORY_H_
#include "ViewFiguraFactory.h"

class ViewCorreaFactory: public ViewFiguraFactory{

public:
	ViewCorreaFactory();
	virtual ~ViewCorreaFactory();
	FiguraView * crear(int, int);
};

#endif /* VIEWCORREAFACTORY_H_ */
