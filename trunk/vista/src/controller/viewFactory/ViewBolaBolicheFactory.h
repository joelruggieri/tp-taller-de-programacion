/*
 * ViewBolaBolicheFactory.h
 *
 *  Created on: 06/10/2013
 *      Author: ezequiel
 */

#ifndef VIEWBOLABOLICHEFACTORY_H_
#define VIEWBOLABOLICHEFACTORY_H_
#include "ViewFiguraFactory.h"

namespace CLIENTE {

class ViewBolaBolicheFactory : public ViewFiguraFactory {
public:
	ViewBolaBolicheFactory();
	virtual ~ViewBolaBolicheFactory();
	FiguraView * crear(int,int);
};

#endif /* VIEWBOLABOLICHEFACTORY_H_ */

}
