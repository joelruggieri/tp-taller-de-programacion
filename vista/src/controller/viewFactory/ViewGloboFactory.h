/*
 * ViewGloboFactory.h
 *
 *  Created on: 20/09/2013
 *      Author: joel
 */

#ifndef VIEWGLOBOFACTORY_H_
#define VIEWGLOBOFACTORY_H_

#include "ViewFiguraFactory.h"
namespace CLIENTE {

class ViewGloboFactory: public ViewFiguraFactory{
public:
	ViewGloboFactory();
	virtual ~ViewGloboFactory();
	FiguraView * crear(int,int);
};
}
#endif /* VIEWGLOBOFACTORY_H_ */
