/*
 * ViewFiguraFactory.cpp
 *
 *  Created on: 05/09/2013
 *      Author: jonathan
 */

#include "ViewFiguraFactory.h"
#include "../../vista/CargadorDeTextures.h"
ViewFiguraFactory::ViewFiguraFactory(string path,DropController * controller) {
	CargadorDeTextures* texturas = CargadorDeTextures::Instance();
	this->textura = texturas->cargarTexture(path);
	this->controller = controller;

}


ViewFiguraFactory::~ViewFiguraFactory() {
	// TODO Auto-generated destructor stub
}

