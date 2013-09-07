/*
 * ViewTrianguloFactory.h
 *
 *  Created on: 05/09/2013
 *      Author: jonathan
 */

#ifndef VIEWTRIANGULOFACTORY_H_
#define VIEWTRIANGULOFACTORY_H_

#include "ViewFiguraFactory.h"

class ViewTrianguloFactory: public ViewFiguraFactory {
public:
	ViewTrianguloFactory();
	virtual ~ViewTrianguloFactory();
	FiguraView * crear(float, float);
};

#endif /* VIEWTRIANGULOFACTORY_H_ */