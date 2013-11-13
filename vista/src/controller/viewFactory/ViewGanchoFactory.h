/*
 * ViewGanchoFactory.h
 *
 *  Created on: 13/11/2013
 *      Author: joel
 */

#ifndef VIEWGANCHOFACTORY_H_
#define VIEWGANCHOFACTORY_H_
#include "ViewFiguraFactory.h"
namespace CLIENTE{

class ViewGanchoFactory: public ViewFiguraFactory{
public:
	ViewGanchoFactory();
	virtual ~ViewGanchoFactory();
	FiguraView * crear(int,int);
};

}

#endif /* VIEWGANCHOFACTORY_H_ */
