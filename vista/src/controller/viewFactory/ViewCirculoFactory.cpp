/*
 * ViewCirculoFactory.cpp
 *
 *  Created on: 05/09/2013
 *      Author: jonathan
 */

#include "ViewCirculoFactory.h"
#include "../../vista/figura/CirculoView.h"

ViewCirculoFactory::ViewCirculoFactory() {

}

ViewCirculoFactory::~ViewCirculoFactory() {
	// TODO Auto-generated destructor stub
}

FiguraView* ViewCirculoFactory::crear(int x, int y, int w, int h) {
	return new CirculoView(x, y, w, h);
}

FiguraView* ViewCirculoFactory::crearVistaPropia(int x, int y, int w,
		int h) {
	return new CirculoView(x,y,w,h);
}
