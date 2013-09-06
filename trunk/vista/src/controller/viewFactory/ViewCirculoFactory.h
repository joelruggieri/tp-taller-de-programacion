/*
 * ViewCirculoFactory.h
 *
 *  Created on: 05/09/2013
 *      Author: jonathan
 */

#ifndef VIEWCIRCULOFACTORY_H_
#define VIEWCIRCULOFACTORY_H_

#include "ViewFiguraFactory.h"

class ViewCirculoFactory: public ViewFiguraFactory {
public:
	ViewCirculoFactory();
	virtual ~ViewCirculoFactory();
	FiguraView * crear(float, float);
};

#endif /* VIEWCIRCULOFACTORY_H_ */
