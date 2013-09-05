/*
 * ViewFiguraFactory.h
 *
 *  Created on: 05/09/2013
 *      Author: jonathan
 */

#ifndef VIEWFIGURAFACTORY_H_
#define VIEWFIGURAFACTORY_H_
#include "../../vista/figura/FiguraView.h"

class ViewFiguraFactory {
public:
	ViewFiguraFactory();
	virtual ~ViewFiguraFactory();
	virtual FiguraView * crear(float, float);
};

#endif /* VIEWFIGURAFACTORY_H_ */
