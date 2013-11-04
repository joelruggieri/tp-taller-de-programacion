/*
 * ViewBalancinFactory.h
 *
 *  Created on: 05/10/2013
 *      Author: joel
 */

#ifndef VIEWBALANCINFACTORY_H_
#define VIEWBALANCINFACTORY_H_
#include "ViewFiguraFactory.h"

class ViewBalancinFactory: public ViewFiguraFactory {

public:
	ViewBalancinFactory();
	virtual ~ViewBalancinFactory();
	FiguraView * crear(int, int);
};

#endif /* VIEWBALANCINFACTORY_H_ */
