/*
 * ViewSogaFactory.cpp
 *
 *  Created on: Oct 5, 2013
 *      Author: matias
 */

#include "ViewSogaFactory.h"
#include "../../vista/objeto/SogaEstaticaView.h"
#include "../../ConstantesVista.h"
namespace CLIENTE {

ViewSogaFactory::ViewSogaFactory():ViewFiguraFactory(PATH_VISTA_CUERDA) {

}

ViewSogaFactory::~ViewSogaFactory() {
	// TODO Auto-generated destructor stub
}

FiguraView* ViewSogaFactory::crear(int x, int y, int w, int h) {
	return new SogaEstaticaView(x, y, w, h, this->textura);
}

}
