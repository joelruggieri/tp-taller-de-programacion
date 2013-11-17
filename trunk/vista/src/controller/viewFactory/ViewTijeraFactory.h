/*
 * ViewTijeraFactory.h
 *
 *  Created on: 16/11/2013
 *      Author: joel
 */

#ifndef VIEWTIJERAFACTORY_H_
#define VIEWTIJERAFACTORY_H_
#include "ViewFiguraFactory.h"

namespace CLIENTE {

class ViewTijeraFactory: public ViewFiguraFactory {
public:
	ViewTijeraFactory();
	virtual ~ViewTijeraFactory();
	FiguraView * crear(int, int);
};

} /* namespace CLIENTE */
#endif /* VIEWTIJERAFACTORY_H_ */
