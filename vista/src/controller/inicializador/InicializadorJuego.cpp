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
#include "../viewFactory/ViewRuedaFactory.h"
#include "../../vista/CargadorDeTextures.h"
#include "../zonaDragAndDrop/ZonaCreacion.h"
#include "../zonaDragAndDrop/ZonaTablero.h"
#include "../RutasArchivos.h"
#include "../Resizer.h"
#include "../PersistenciaEventController.h"
#include "src/figuraFactory/FiguraFactory.h"
const string KEY_CUADRADO = "CUADRADO";
const string KEY_CIRCULO= "CIRCULO";
const string KEY_TRIANGULO= "TRIANGULO";

InicializadorJuego::InicializadorJuego(SDL_Renderer * renderer, GeneralEventController * controllerEventos, ModeloController * modeloController) {
	this->zonaJuego = NULL;
	this->juegoController = NULL;
	this->renderer = renderer;
	this->eventsController = controllerEventos;
	this->bbdd = new PersistenciaManager();
	this->modeloController = modeloController;
	//TODO EL ROTADOR NO SE BORRA, DONDE SE BORRA?
	this->rotador = new RotadorSistemaCoordenadas();
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
	int y = r->resizearPosicionLogicaY(modelo->getY());
	int w = r->resizearDistanciaLogicaY(modelo->getAncho());
	int h = r->resizearDistanciaLogicaY(modelo->getAlto());
	//TODO HABRIA QUE VALIDAR QUE LA POSICION CAIGA BIEN, SINO BORRARLO
	FiguraView * view = factory->crear(x,y,w,h);
	view->setModelo(modelo);
	this->zonaJuego->agregarFigura(view);
}

JuegoEventsController * InicializadorJuego::crearZonaJuego() {
	if(zonaJuego != NULL){
		return this->juegoController;
	}

	this->juegoController = new JuegoEventsController(modeloController,new FiguraFactory(this->rotador), 20);
	ViewFiguraFactory * factory = new ViewCuadradoFactory(renderer, juegoController);
	figuraFactory.insert(pair<string, ViewFiguraFactory*>(KEY_CUADRADO,factory));
	factory = new ViewTrianguloFactory(renderer, juegoController);
	figuraFactory.insert(pair<string, ViewFiguraFactory*>(KEY_TRIANGULO,factory));
	factory = new ViewCirculoFactory(renderer, juegoController);
	figuraFactory.insert(pair<string, ViewFiguraFactory*>(KEY_CIRCULO,factory));


	list<ViewFiguraFactory*> factories;
	CargadorDeTextures* texturas = CargadorDeTextures::Instance();
	SDL_Texture* canvasTexture = texturas->cargarTexture(FONDO_DEFECTO);
	SDL_Texture* herrTextura = texturas->cargarTexture(FONDO_ZONA_CREACION);
	factories.push_back(new ViewCuadradoFactory(renderer, juegoController));
	factories.push_back(new ViewTrianguloFactory(renderer, juegoController));
	factories.push_back(new ViewCuadradoFactory(renderer, juegoController));
	factories.push_back(new ViewCirculoFactory(renderer, juegoController));
	factories.push_back(new ViewCuadradoFactory(renderer, juegoController));
	factories.push_back(new ViewRuedaFactory(renderer, juegoController));
	factories.push_back(new ViewTrianguloFactory(renderer, juegoController));
	factories.push_back(new ViewCirculoFactory(renderer, juegoController));
	factories.push_back(new ViewCuadradoFactory(renderer, juegoController));
	factories.push_back(new ViewRuedaFactory(renderer, juegoController));
	factories.push_back(new ViewCirculoFactory(renderer, juegoController));
	factories.push_back(new ViewCuadradoFactory(renderer, juegoController));
	factories.push_back(new ViewTrianguloFactory(renderer, juegoController));
	factories.push_back(new ViewCirculoFactory(renderer, juegoController));
	Zona* zonaCreacion = new ZonaCreacion(&factories, 110, 120,
			herrTextura);
	ZonaTablero* zonaTablero = new ZonaTablero(50,70, canvasTexture);
	this->zonaJuego=  new ZonaJuego(zonaCreacion, zonaTablero,
			new Cuadrado(75, 70,0, 150, 100));

	list<Figura*> figurasPersistidas = this->bbdd->getFiguras();
	list<Figura*>::iterator it;
	for(it = figurasPersistidas.begin() ; it != figurasPersistidas.end() ; ++it){
		(*it)->setRotador(this->rotador);
		(*it)->acept(this);
	}

	CanvasController* canvasController = new CanvasController(zonaTablero->getCanvas());
	PersistenciaEventController * persistenciaController= new PersistenciaEventController (this->modeloController, this->bbdd);
	this->eventsController->setCanvasController(canvasController);
	this->eventsController->setGuardarController(persistenciaController);
	this->eventsController->addMouseController(this->juegoController,1,1);
	this->juegoController->setZona(this->zonaJuego);

	return this->juegoController;
}

