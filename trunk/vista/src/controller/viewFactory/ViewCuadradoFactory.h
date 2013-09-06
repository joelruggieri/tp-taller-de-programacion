/*
 * ViewCuadradoFactory.h
 *
 *  Created on: 05/09/2013
 *      Author: jonathan
 */

#ifndef VIEWCUADRADOFACTORY_H_
#define VIEWCUADRADOFACTORY_H_

#include "ViewFiguraFactory.h"

class ViewCuadradoFactory: public ViewFiguraFactory {
public:
	ViewCuadradoFactory();
	virtual ~ViewCuadradoFactory();
	FiguraView * crear(float, float);
};

#endif /* VIEWCUADRADOFACTORY_H_ */
