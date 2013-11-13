/*
 * ViewGanchoFactory.cpp
 *
 *  Created on: 13/11/2013
 *      Author: joel
 */

#include "ViewGanchoFactory.h"
#include "ViewFiguraFactory.h"
#include "../../ConstantesVista.h"


namespace CLIENTE{

ViewGanchoFactory::ViewGanchoFactory(): ViewFiguraFactory(PATH_VISTA_GANCHO) {
	// TODO Auto-generated constructor stub

}

ViewGanchoFactory::~ViewGanchoFactory() {
	// TODO Auto-generated destructor stub
}

FiguraView* ViewGanchoFactory::crear(int x , int y) {
	return NULL;
}


}

