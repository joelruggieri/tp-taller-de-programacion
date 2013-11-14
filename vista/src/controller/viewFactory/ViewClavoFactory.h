/*
 * ViewClavoFactory.h
 *
 *  Created on: 14/11/2013
 *      Author: ezequiel
 */

#ifndef VIEWCLAVOFACTORY_H_
#define VIEWCLAVOFACTORY_H_
#include "ViewFiguraFactory.h"
namespace CLIENTE {

class ViewClavoFactory : public ViewFiguraFactory {
public:
	ViewClavoFactory();
	virtual ~ViewClavoFactory();
	FiguraView * crear(int, int);
};

} /* namespace CLIENTE */
#endif /* VIEWCLAVOFACTORY_H_ */
