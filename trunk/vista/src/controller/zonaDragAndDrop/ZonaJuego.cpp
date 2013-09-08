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
#include <iostream>
#include "../viewFactory/ViewCirculoFactory.h"
#include "../viewFactory/ViewCuadradoFactory.h"
#include "../viewFactory/ViewTrianguloFactory.h"
#include "../../vista/Canvas.h"
using namespace std;



ZonaJuego::ZonaJuego(SDL_Texture * fondoCanvas) : ZonaDragAndDrop(new Cuadrado(75,50,150,100)) {
	// 5 margen izq
	// 100 tablero
	// 10 entre los dos paneles
	// 20 la zona creacion
	// 5 margen izquierdo


	this->zonaTablero = new ZonaTablero(new Mapa(),55,55, new Canvas(0,0, 300, 300,fondoCanvas));
	list <ViewFiguraFactory*> *factories = new list<ViewFiguraFactory*>();
	factories->push_back(new ViewCirculoFactory());
	factories->push_back(new ViewCuadradoFactory());
	factories->push_back(new ViewTrianguloFactory());
	this->zonaCreacion = new ZonaCreacion(factories,135,5,new Canvas(300,0,300,100,fondoCanvas));
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

void ZonaJuego::dibujarse(SDL_Renderer* renderer) {
	this->zonaTablero->dibujarse(renderer);
	this->zonaCreacion->dibujarse(renderer);
}

FiguraView* ZonaJuego::drag(float x, float y) {
	return this->dragTemplate(x,y);
}
