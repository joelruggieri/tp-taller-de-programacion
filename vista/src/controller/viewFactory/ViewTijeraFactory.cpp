/*
 * ViewTijeraFactory.cpp
 *
 *  Created on: 16/11/2013
 *      Author: joel
 */

#include "ViewTijeraFactory.h"
#include "../../ConstantesVista.h"

namespace CLIENTE {

ViewTijeraFactory::ViewTijeraFactory(): ViewFiguraFactory(PATH_VISTA_TIJERA_ABIERTA) {


}

ViewTijeraFactory::~ViewTijeraFactory() {
	// TODO Auto-generated destructor stub
}

FiguraView * ViewTijeraFactory::crear(int x, int y){
	return NULL;
}

} /* namespace CLIENTE */
