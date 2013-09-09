/*
 * ZonaJuego.cpp
 *
 *  Created on: 30/08/2013
 *      Author: jonathan
 */

#include "ZonaJuego.h"

#include <src/figura/Cuadrado.h>
#include <src/figura/Mapa.h>
#include <list>
#include <new>

#include "../DragAndDropController.h"
#include "../viewFactory/ViewCirculoFactory.h"
#include "../viewFactory/ViewCuadradoFactory.h"
#include "../viewFactory/ViewTrianguloFactory.h"
#include "ZonaCreacion.h"
#include "ZonaDragAndDrop.h"
#include "ZonaTablero.h"

class FiguraView;
class ViewFiguraFactory;
struct SDL_Renderer;
struct SDL_Texture;

using namespace std;



ZonaJuego::ZonaJuego(SDL_Texture * fondoCanvas, SDL_Renderer * renderer) : Zona(new Cuadrado(75,50,150,100)) {
	// 5 margen izq
	// 100 tablero
	// 10 entre los dos paneles
	// 20 la zona creacion
	// 5 margen izquierdo


	this->zonaTablero = new ZonaTablero(new Mapa(),50,50, fondoCanvas);
	list <ViewFiguraFactory*> factories;
	//TODO VER DONDE ELIMINAR ESTE CONTROLLER, CAPAZ TIENE QUE VENIR COMO PARAMETRO CON LAS FACTORIES
	DragAndDropController* dragAndDropController = new DragAndDropController(this);
	factories.push_back(new ViewCuadradoFactory(renderer,dragAndDropController));
	factories.push_back(new ViewTrianguloFactory(renderer,dragAndDropController));
	factories.push_back(new ViewCirculoFactory(renderer,dragAndDropController));
	factories.push_back(new ViewCuadradoFactory(renderer,dragAndDropController));
	factories.push_back(new ViewCuadradoFactory(renderer,dragAndDropController));
	factories.push_back(new ViewTrianguloFactory(renderer,dragAndDropController));
	factories.push_back(new ViewCuadradoFactory(renderer,dragAndDropController));
	factories.push_back(new ViewCirculoFactory(renderer,dragAndDropController));
	this->zonaCreacion = new ZonaCreacion(&factories,110,0,fondoCanvas);
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

bool ZonaJuego::click(int x, int y) {
	return this->clickTemplate(x,y);
}

bool ZonaJuego::removerFigura(FiguraView* figura) {
	return this->zonaCreacion->removerFigura(figura) || this->zonaTablero->removerFigura(figura);
}
