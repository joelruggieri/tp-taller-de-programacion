/*
 * ZonaJuego.cpp
 *
 *  Created on: 30/08/2013
 *      Author: jonathan
 */

#include "ZonaJuego.h"
#include "ZonaDragAndDrop.h"
#include "../Resizer.h"
using namespace std;


ZonaJuego::ZonaJuego(Zona* zonaCreacion, Zona * zonaTablero, Cuadrado * dimensiones) : Zona(dimensiones) {
	this->zonaTablero = zonaTablero;
	this->zonaCreacion = zonaCreacion;
}

bool ZonaJuego::agregarTemplate(FiguraView* dropeable) {
	//SI ALGUNO DE LOS DOS PANELES DE LA ZONA PUEDE ATENDER SE ATIENDE.
	bool result = this->zonaCreacion->agregarFigura(dropeable);
	if (!result) {
		result = this->zonaTablero->agregarFigura(dropeable);
	}
	return result;
}

bool ZonaJuego::clickTemplate(float x, float y) {
	//SI ALGUNO DE LOS DOS PANELES DE LA ZONA PUEDE ATENDER SE ATIENDE.
	bool result = this->zonaCreacion->click(x, y);
	if (result == false) {
		result = this->zonaTablero->click(x, y);
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

void ZonaJuego::dibujarse(SDL_Renderer* renderer) {
	this->zonaTablero->dibujarse(renderer);
	this->zonaCreacion->dibujarse(renderer);
}

bool ZonaJuego::click(float x, float y) {
	Resizer* r = Resizer::Instance();
	//LO QUE SE HACE ES CAPTURAR LA PROPAGACION DE CLICKS Y CAMBIAR A
	return this->clickTemplate(r->resizearDistanciaPixelX(x),r->resizearDistanciaPixelY(y));
}

bool ZonaJuego::removerFigura(FiguraView* figura) {
	return this->zonaCreacion->removerFigura(figura) || this->zonaTablero->removerFigura(figura);
}
