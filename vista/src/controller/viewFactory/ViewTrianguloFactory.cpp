/*
 * ViewTrianguloFactory.cpp
 *
 *  Created on: 05/09/2013
 *      Author: jonathan
 */

#include "ViewTrianguloFactory.h"
#include "../../vista/figura/TrianguloView.h"
ViewTrianguloFactory::ViewTrianguloFactory() {
	// TODO Auto-generated constructor stub

}

ViewTrianguloFactory::~ViewTrianguloFactory() {
	// TODO Auto-generated destructor stub
}

FiguraView* ViewTrianguloFactory::crear(int x, int y, int w, int h) {
	return new TrianguloView(x,y,w,h);
}

FiguraView* ViewTrianguloFactory::crearVistaPropia(int x, int y, int w,
		int h) {
	return new TrianguloView(x,y,w,h);
}
