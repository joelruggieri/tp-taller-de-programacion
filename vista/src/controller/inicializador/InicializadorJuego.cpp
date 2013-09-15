/*
 * InicializadorJuego.cpp
 *
 *  Created on: 14/09/2013
 *      Author: jonathan
 */

#include "InicializadorJuego.h"
#include <iostream>
using namespace std;
#include <list>
#include "../../vista/figura/FiguraView.h"
#include "../viewFactory/ViewCuadradoFactory.h"
#include "../viewFactory/ViewCirculoFactory.h"
#include "../viewFactory/ViewTrianguloFactory.h"
#include "../../vista/CargadorDeTextures.h"
#include "../zonaDragAndDrop/ZonaCreacion.h"
#include "../zonaDragAndDrop/ZonaJuego.h"
#include "../zonaDragAndDrop/ZonaTablero.h"
#include "../RutasArchivos.h"
#include "../Resizer.h"
const string KEY_CUADRADO = "CUADRADO";
const string KEY_CIRCULO= "CIRCULO";
const string KEY_TRIANGULO= "TRIANGULO";

InicializadorJuego::InicializadorJuego(SDL_Renderer * renderer, DropController * dropController) {
	this->zonaJuego = NULL;
	ViewFiguraFactory * factory = new ViewCuadradoFactory(renderer, dropController);
	figuraFactory.insert(pair<string, ViewFiguraFactory*>(KEY_CUADRADO,factory));

	factory = new ViewTrianguloFactory(renderer, dropController);
	figuraFactory.insert(pair<string, ViewFiguraFactory*>(KEY_TRIANGULO,factory));

	factory = new ViewCirculoFactory(renderer, dropController);
	figuraFactory.insert(pair<string, ViewFiguraFactory*>(KEY_CIRCULO,factory));
	this->dropController =dropController;
	this->renderer = renderer;
	this->bbdd = new PersistenciaManager();
}

InicializadorJuego::~InicializadorJuego() {
	delete this->bbdd;
}

void InicializadorJuego::visit(Cuadrado* c) {
	map<string, ViewFiguraFactory*>::iterator iter = this->figuraFactory.find(KEY_CUADRADO);
	ViewFiguraFactory* second = iter->second;
	this->agregarFigura(second, c);
}

void InicializadorJuego::visit(Triangulo * t) {
	map<string, ViewFiguraFactory*>::iterator iter = this->figuraFactory.find(KEY_TRIANGULO);
	ViewFiguraFactory* second = iter->second;
	this->agregarFigura(second, t);
}

void InicializadorJuego::visit(Circulo* c) {
	map<string, ViewFiguraFactory*>::iterator iter = this->figuraFactory.find(KEY_CIRCULO);
	this->agregarFigura(iter->second, c);
}

void InicializadorJuego::agregarFigura(ViewFiguraFactory* factory,
		Figura* modelo) {
	Resizer * r = Resizer::Instance();
	int x = r->resizearDistanciaLogicaX(modelo->getX());
	int y = r->resizearDistanciaLogicaY(modelo->getY());
	int w = r->resizearDistanciaLogicaY(modelo->getAncho());
	int h = r->resizearDistanciaLogicaY(modelo->getAlto());
	//TODO HABRIA QUE VALIDAR QUE LA POSICION CAIGA BIEN, SINO BORRARLO
	FiguraView * view = factory->crear(x,y,w,h);
	view->setModelo(modelo);
	this->zonaJuego->agregarFigura(view);
}

Zona* InicializadorJuego::crearZonaJuego() {
	if(zonaJuego != NULL){
		return zonaJuego;
	}
	//TODO VER DONDE ENCAPSULAR ESTA LOGICA.
	// 5 margen izq
	// 100 tablero
	// 10 entre los dos paneles
	// 20 la zona creacion
	// 5 margen izquierdo

	list<ViewFiguraFactory*> factories;
	CargadorDeTextures* texturas = CargadorDeTextures::Instance();
	SDL_Texture* canvasTexture = texturas->cargarTexture(FONDO_DEFECTO);
	SDL_Texture* herrTextura = texturas->cargarTexture(FONDO_ZONA_CREACION);
	factories.push_back(new ViewCuadradoFactory(renderer, dropController));
	factories.push_back(new ViewTrianguloFactory(renderer, dropController));
	factories.push_back(new ViewCuadradoFactory(renderer, dropController));
	factories.push_back(new ViewCirculoFactory(renderer, dropController));
	factories.push_back(new ViewCuadradoFactory(renderer, dropController));
	factories.push_back(new ViewTrianguloFactory(renderer, dropController));
	factories.push_back(new ViewCirculoFactory(renderer, dropController));
	factories.push_back(new ViewCuadradoFactory(renderer, dropController));
	factories.push_back(new ViewCirculoFactory(renderer, dropController));
	factories.push_back(new ViewCuadradoFactory(renderer, dropController));
	factories.push_back(new ViewTrianguloFactory(renderer, dropController));
	factories.push_back(new ViewCirculoFactory(renderer, dropController));
	Zona* zonaCreacion = new ZonaCreacion(&factories, 110, 0,
			herrTextura);
	Zona* zonaTablero = new ZonaTablero(new Mapa(),50,50, canvasTexture);
	this->zonaJuego=  new ZonaJuego(zonaCreacion, zonaTablero,
			new Cuadrado(75, 50, 150, 100));

	list<Figura*> figurasPersistidas = this->bbdd->getFiguras();
	list<Figura*>::iterator it;
	for(it = figurasPersistidas.begin() ; it != figurasPersistidas.end() ; ++it){
		(*it)->acept(this);
	}

	return this->zonaJuego;
}
