/*
 * ViewCarritoFactory.cpp
 *
 *  Created on: 14/11/2013
 *      Author: joel
 */

#include "ViewCarritoFactory.h"
namespace CLIENTE{
ViewCarritoFactory::ViewCarritoFactory(): ViewFiguraFactory(PATH_VISTA_CARRITO) {

}

ViewCarritoFactory::~ViewCarritoFactory() {
	// TODO Auto-generated destructor stub
}

FiguraView* ViewCarritoFactory::crear(int x, int Y) {

	return NULL;
}

}
