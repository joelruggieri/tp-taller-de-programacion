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


ZonaJuego::ZonaJuego(Zona* zonaCreacion, ZonaTablero * zonaTablero, Cuadrado * dimensiones) : Zona(dimensiones) {
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

FiguraView * ZonaJuego::getFiguraTemplate(float x, float y) {
	//SI ALGUNO DE LOS DOS PANELES DE LA ZONA PUEDE ATENDER SE ATIENDE.
	FiguraView * result = this->zonaCreacion->getVista(x, y);
	if (result == NULL) {
		result = this->zonaTablero->getVista(x, y);
	}
	return result;
}

Canvas* ZonaJuego::getCanvas(){
	return this->zonaTablero->getCanvas();
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

FiguraView * ZonaJuego::getVista(float x, float y) {
	return this->getFiguraTemplate(x,y);
}

bool ZonaJuego::removerFigura(FiguraView* figura) {
	return this->zonaCreacion->removerFigura(figura) || this->zonaTablero->removerFigura(figura);
}

bool ZonaJuego::click(float x, float y) {
	return this->zonaCreacion->click(x,y);
}
