/*
 * ViewCarritoFactory.h
 *
 *  Created on: 14/11/2013
 *      Author: joel
 */

#ifndef VIEWCARRITOFACTORY_H_
#define VIEWCARRITOFACTORY_H_
#include "ViewFiguraFactory.h"
namespace CLIENTE{

class ViewCarritoFactory: public ViewFiguraFactory {
public:
	ViewCarritoFactory();
	virtual ~ViewCarritoFactory();
	FiguraView * crear(int, int);
};
}
#endif /* VIEWCARRITOFACTORY_H_ */
