/*
 * ZonaTablero.cpp
 *
 *  Created on: 30/08/2013
 *      Author: jonathan
 */

#include "ZonaTablero.h"

ZonaTablero::ZonaTablero(Cuerpo cuerpo):ZonaDragAndDrop(cuerpo) {

}

bool ZonaTablero::dropTemplate(Dropeable* dragueable) {
	return true;
}

Dropeable* ZonaTablero::dragTemplate(float x, float y) {
	return NULL;
}

ZonaTablero::~ZonaTablero() {
	// TODO Auto-generated destructor stub
}

