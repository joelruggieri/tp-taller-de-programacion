/*
 * ViewCuadradoFactory.cpp
 *
 *  Created on: 05/09/2013
 *      Author: jonathan
 */

#include "ViewCuadradoFactory.h"
#include "../../vista/figura/CuadradoView.h"

ViewCuadradoFactory::ViewCuadradoFactory(): ViewFiguraFactory(10,10) {
	// TODO Auto-generated constructor stub

}

ViewCuadradoFactory::~ViewCuadradoFactory() {
	// TODO Auto-generated destructor stub
}

FiguraView* ViewCuadradoFactory::crear(float float1, float float2) {

	return new CuadradoView();
}
