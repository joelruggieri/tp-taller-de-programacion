/*
 * ObjetivoDesdeHasta.cpp
 *
 *  Created on: 23/11/2013
 *      Author: ezequiel
 */

#include "ObjetivoDesdeHasta.h"

ObjetivoDesdeHasta::ObjetivoDesdeHasta(float xD, float yD, float xH, float yH, int numObj):Objetivo(xD,yD,numObj) {
this->xH = xH;
this->yH = yH;
}

ObjetivoDesdeHasta::~ObjetivoDesdeHasta() {
	// TODO Auto-generated destructor stub
}

