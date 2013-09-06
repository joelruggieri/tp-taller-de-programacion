/*
 * ViewTrianguloFactory.cpp
 *
 *  Created on: 05/09/2013
 *      Author: jonathan
 */

#include "ViewTrianguloFactory.h"

ViewTrianguloFactory::ViewTrianguloFactory(): ViewFiguraFactory(10,10) {
	// TODO Auto-generated constructor stub

}

ViewTrianguloFactory::~ViewTrianguloFactory() {
	// TODO Auto-generated destructor stub
}

FiguraView* ViewTrianguloFactory::crear(float float1, float float2) {
	return new TrianguloView();
}
