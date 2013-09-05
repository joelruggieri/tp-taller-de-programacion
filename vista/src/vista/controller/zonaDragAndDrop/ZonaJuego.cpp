/*
 * ZonaJuego.cpp
 *
 *  Created on: 30/08/2013
 *      Author: jonathan
 */

#include "ZonaJuego.h"
#include "ZonaTablero.h"
#include "ZonaCreacion.h"
#include <list>
using namespace std;



ZonaJuego::ZonaJuego() :
//		ZonaDragAndDrop(Cuerpo(0, 0, 140, 100,0)) {
		ZonaDragAndDrop(new Cuadrado()) { //TODO UN CUADRADO INMENSO PONDRIA ACA.
//	this->zonaTablero = new ZonaTablero(Cuerpo(10, 0, 100, 100, 0));
//	this->zonaCreacion = new ZonaCreacion(Cuerpo(120, 0, 20, 100, 0));
	this->zonaTablero = new ZonaTablero(new Mapa(),60,60);
	list <ViewFiguraFactory*> *factories = new list<ViewFiguraFactory*>();
	this->zonaCreacion = new ZonaCreacion(factories);
	delete factories;
}

bool ZonaJuego::dropTemplate(FiguraView* dropeable) {
	//SI ALGUNO DE LOS DOS PANELES DE LA ZONA PUEDE ATENDER SE ATIENDE.
	bool result = this->zonaCreacion->drop(dropeable);
	if (!result) {
		result = this->zonaTablero->drop(dropeable);
	}
	return result;
}

FiguraView* ZonaJuego::dragTemplate(float x, float y) {
	//SI ALGUNO DE LOS DOS PANELES DE LA ZONA PUEDE ATENDER SE ATIENDE.
	FiguraView * result = this->zonaCreacion->drag(x, y);
	if (result == NULL) {
		result = this->zonaTablero->drag(x, y);
	}
	return result;
}

ZonaJuego::~ZonaJuego() {
	delete this->zonaCreacion;
	delete this->zonaTablero;
}

float ZonaJuego::getScrollY() const {
	return this->zonaCreacion->getScrollY();
}

void ZonaJuego::setScrollY(float scrollY) {
	this->zonaCreacion->setScrollY(scrollY);
}
