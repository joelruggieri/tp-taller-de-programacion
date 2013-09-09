/*
 * ViewCuadradoFactory.cpp
 *
 *  Created on: 05/09/2013
 *      Author: jonathan
 */

#include "ViewCuadradoFactory.h"
#include "../../vista/figura/CuadradoView.h"

ViewCuadradoFactory::ViewCuadradoFactory(SDL_Renderer * renderer): ViewFiguraFactory("resource/cuadrado.jpg", renderer){
	// TODO Auto-generated constructor stub

}

ViewCuadradoFactory::~ViewCuadradoFactory() {
	// TODO Auto-generated destructor stub
}

FiguraView* ViewCuadradoFactory::crear(int x, int y, int w, int h) {

	return new CuadradoView(x,y,w,h, this->textura);
}

FiguraView* ViewCuadradoFactory::crearVistaPropia(int x, int y,
		int w, int h) {
	return new CuadradoView(x,y,w,h, this->textura);
}
