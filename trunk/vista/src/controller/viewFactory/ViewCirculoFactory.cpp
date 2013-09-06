/*
 * ViewCirculoFactory.cpp
 *
 *  Created on: 05/09/2013
 *      Author: jonathan
 */

#include "ViewCirculoFactory.h"

ViewCirculoFactory::ViewCirculoFactory(): ViewFiguraFactory(10,10) {

}

ViewCirculoFactory::~ViewCirculoFactory() {
	// TODO Auto-generated destructor stub
}

FiguraView* ViewCirculoFactory::crear(float x, float y) {
	return new CirculoView();
}
