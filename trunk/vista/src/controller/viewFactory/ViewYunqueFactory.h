/*
 * ViewYunqueFactory.h
 *
 *  Created on: 13/11/2013
 *      Author: ezequiel
 */

#ifndef VIEWYUNQUEFACTORY_H_
#define VIEWYUNQUEFACTORY_H_
#include "ViewFiguraFactory.h"
namespace CLIENTE {

class ViewYunqueFactory : public ViewFiguraFactory {
public:
	ViewYunqueFactory();
	virtual ~ViewYunqueFactory();
	FiguraView * crear(int,int);
};

} /* namespace CLIENTE */
#endif /* VIEWYUNQUEFACTORY_H_ */
