/*
 * ZonaJuego.cpp
 *
 *  Created on: 30/08/2013
 *      Author: jonathan
 */

#include "ZonaJuego.h"

ZonaJuego::ZonaJuego(Cuerpo cuerpo):ZonaDragAndDrop(cuerpo) {

}

ZonaJuego::~ZonaJuego() {

	delete this->zonaCreacion;
	delete this->zonaTablero;
}

