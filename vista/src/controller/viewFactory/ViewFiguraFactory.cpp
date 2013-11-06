/*
 * ViewFiguraFactory.cpp
 *
 *  Created on: 05/09/2013
 *      Author: jonathan
 */

#include "ViewFiguraFactory.h"
#include "../../vista/CargadorDeTextures.h"

namespace CLIENTE {

ViewFiguraFactory::ViewFiguraFactory(string path) {
	CargadorDeTextures* texturas = CargadorDeTextures::Instance();
	this->textura = texturas->cargarTexture(path);
}


ViewFiguraFactory::~ViewFiguraFactory() {
	// TODO Auto-generated destructor stub
}

}
