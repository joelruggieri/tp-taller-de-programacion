/*
 * ViewSogaFactory.h
 *
 *  Created on: Oct 5, 2013
 *      Author: matias
 */

#ifndef VIEWSOGAFACTORY_H_
#define VIEWSOGAFACTORY_H_
#include "ViewFiguraFactory.h"

namespace std {

class ViewSogaFactory: public ViewFiguraFactory {

public:
	ViewSogaFactory();
	virtual ~ViewSogaFactory();
	FiguraView * crear(int, int, int, int);
};

} /* namespace std */
#endif /* VIEWSOGAFACTORY_H_ */
