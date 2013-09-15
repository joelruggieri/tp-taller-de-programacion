/*
 * ViewFiguraFactory.cpp
 *
 *  Created on: 05/09/2013
 *      Author: jonathan
 */

#include "ViewFiguraFactory.h"

ViewFiguraFactory::ViewFiguraFactory(string path,SDL_Renderer* ren,DropController * controller) {
	this->textura = this->cargarTexture(path,ren);
	this->controller = controller;

}

//TODO CENTRALIZAR CARGAR TEXTURA
SDL_Texture* ViewFiguraFactory::cargarTexture (const string &file, SDL_Renderer* ren){
	SDL_Texture* texture = IMG_LoadTexture(ren, file.c_str() );
	if (texture == NULL) cout << "IMG_Load error: " << IMG_GetError() <<endl;
	return texture;
}

ViewFiguraFactory::~ViewFiguraFactory() {
	// TODO Auto-generated destructor stub
}

