/*
 * ZonaJuego.cpp
 *
 *  Created on: 30/08/2013
 *      Author: jonathan
 */

#include "ZonaJuego.h"
#include "ZonaTablero.h"
#include "ZonaCreacion.h"
ZonaJuego::ZonaJuego() :
		ZonaDragAndDrop(Cuerpo(0, 0, 140, 100)) {
	this->zonaTablero = new ZonaTablero(Cuerpo(10, 0, 100, 100));
	this->zonaCreacion = new ZonaCreacion(Cuerpo(120, 0, 20, 100));
}

bool ZonaJuego::dropTemplate(Dropeable* dropeable) {
	//SI ALGUNO DE LOS DOS PANELES DE LA ZONA PUEDE ATENDER SE ATIENDE.
	bool result = this->zonaCreacion->drop(dropeable);
	if(!result){
		result = this->zonaTablero->drop(dropeable);
	}
	return result;
}

Dropeable* ZonaJuego::dragTemplate(float x, float y) {
	//SI ALGUNO DE LOS DOS PANELES DE LA ZONA PUEDE ATENDER SE ATIENDE.
	Dropeable * result = this->zonaCreacion->drag(x,y);
	if(result == NULL){
		result = this->zonaTablero->drag(x,y);
	}
	return result;
}

ZonaJuego::~ZonaJuego() {
	delete this->zonaCreacion;
	delete this->zonaTablero;
}

