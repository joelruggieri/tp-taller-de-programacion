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
#include "../viewFactory/ViewGloboFactory.h"
#include "../viewFactory/ViewPelotaFactory.h"
#include "../viewFactory/ViewResorteFactory.h"
#include "../viewFactory/ViewMartilloFactory.h"
#include "../viewFactory/ViewBloqueFactory.h"
#include "../viewFactory/ViewCoheteFactory.h"
#include "../viewFactory/ViewCarritoFactory.h"
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
const string KEY_RUEDA = "RUEDA";
const string KEY_GLOBO = "GLOBO";
const string KEY_PELOTA = "PELOTA";
const string KEY_RESORTE = "RESORTE";
const string KEY_MARTILLO = "MARTILLO";
const string KEY_BLOQUE = "BLOQUE";
const string KEY_COHETE = "COHETE";
const string KEY_CARRITO = "CARRITO";

InicializadorJuego::InicializadorJuego(GeneralEventController * controllerEventos, ModeloController * modeloController) {
	this->zonaJuego = NULL;
	this->juegoController = NULL;
	this->eventsController = controllerEventos;
	this->bbdd = new PersistenciaManager();
	this->modeloController = modeloController;
	//TODO EL ROTADOR NO SE BORRA, DONDE SE BORRA?
	this->rotador = new RotadorSistemaCoordenadas();
	this->factory = new FiguraFactory(this->rotador);
}

InicializadorJuego::~InicializadorJuego() {
	delete this->bbdd;
}

void InicializadorJuego::visit(Cuadrado* c) {
	Figura * fig = this->factory->crear(c);
	map<string, ViewFiguraFactory*>::iterator iter = this->figuraFactory.find(KEY_CUADRADO);
	ViewFiguraFactory* second = iter->second;
	this->agregarFigura(second, fig);
}

void InicializadorJuego::visit(Triangulo * t) {
	Figura * fig = this->factory->crear(t);
	map<string, ViewFiguraFactory*>::iterator iter = this->figuraFactory.find(KEY_TRIANGULO);
	ViewFiguraFactory* second = iter->second;
	this->agregarFigura(second, fig);
}

void InicializadorJuego::visit(Circulo* c) {
	Figura * fig = this->factory->crear(c);
	map<string, ViewFiguraFactory*>::iterator iter = this->figuraFactory.find(KEY_CIRCULO);
	this->agregarFigura(iter->second, fig);
}

void InicializadorJuego::visit(Rueda* c) {
	Figura * fig = this->factory->crear(c);
	map<string, ViewFiguraFactory*>::iterator iter = this->figuraFactory.find(KEY_RUEDA);
	this->agregarFigura(iter->second, fig);
}

void InicializadorJuego::visit(Globo* c) {
	Figura * fig = this->factory->crear(c);
	map<string, ViewFiguraFactory*>::iterator iter = this->figuraFactory.find(KEY_GLOBO);
	this->agregarFigura(iter->second, fig);
}

void InicializadorJuego::visit(Pelota* c) {
	Figura * fig = this->factory->crear(c);
	map<string, ViewFiguraFactory*>::iterator iter = this->figuraFactory.find(KEY_PELOTA);
	this->agregarFigura(iter->second, fig);
}

void InicializadorJuego::visit(Resorte* c) {
	Figura * fig = this->factory->crear(c);
	map<string, ViewFiguraFactory*>::iterator iter = this->figuraFactory.find(KEY_RESORTE);
	this->agregarFigura(iter->second, fig);
}

void InicializadorJuego::visit(Martillo* c) {
	Figura * fig = this->factory->crear(c);
	map<string, ViewFiguraFactory*>::iterator iter = this->figuraFactory.find(KEY_MARTILLO);
	this->agregarFigura(iter->second, fig);
}

void InicializadorJuego::visit(Bloque* c) {
	Figura * fig = this->factory->crear(c);
	map<string, ViewFiguraFactory*>::iterator iter = this->figuraFactory.find(KEY_BLOQUE);
	this->agregarFigura(iter->second, fig);
}

void InicializadorJuego::visit(Cohete* c) {
	Figura * fig = this->factory->crear(c);
	map<string, ViewFiguraFactory*>::iterator iter = this->figuraFactory.find(KEY_COHETE);
	this->agregarFigura(iter->second, fig);
}

void InicializadorJuego::visit(Carrito* c) {
	Figura * fig = this->factory->crear(c);
	map<string, ViewFiguraFactory*>::iterator iter = this->figuraFactory.find(KEY_CARRITO);
	this->agregarFigura(iter->second, fig);
}

void InicializadorJuego::agregarFigura(ViewFiguraFactory* factory,
		Figura* modelo) {
	Resizer * r = Resizer::Instance();
	int x = r->resizearDistanciaLogicaX(modelo->getX());
	int y = r->resizearPosicionLogicaY(modelo->getY());
	int w = r->resizearDistanciaLogicaY(10);
	int h = r->resizearDistanciaLogicaY(10);
	//TODO HABRIA QUE VALIDAR QUE LA POSICION CAIGA BIEN, SINO BORRARLO
	FiguraView * view = factory->crear(x,y,w,h);
	view->setModelo(modelo);
	bool exitoVista = zonaJuego->agregarFigura(view);
	bool exitoModelo = this->modeloController->crearFigura(modelo);
	if (!exitoVista || !exitoModelo) {
		Logger log;
		string msj = "Objeto con posicion invalida, es omitido (";
		log.concatenar(msj, modelo->getX());
		msj = msj + ";";
		log.concatenar(msj,modelo->getY());
		msj = msj + ")";
		log.warning(msj);

		if (exitoVista) {
			zonaJuego->removerFigura(view);
		}
		if (exitoModelo) {
			modeloController->removerFigura(modelo);
		}
		delete view;
		delete modelo;
	}
}

JuegoEventsController * InicializadorJuego::crearZonaJuego() {
	if(zonaJuego != NULL){
		return this->juegoController;
	}

	this->juegoController = new JuegoEventsController(modeloController, this->factory, 20);
	ViewFiguraFactory * factory = new ViewCuadradoFactory(juegoController);
	figuraFactory.insert(pair<string, ViewFiguraFactory*>(KEY_CUADRADO,factory));
	factory = new ViewTrianguloFactory(juegoController);
	figuraFactory.insert(pair<string, ViewFiguraFactory*>(KEY_TRIANGULO,factory));
	factory = new ViewCirculoFactory(juegoController);
	figuraFactory.insert(pair<string, ViewFiguraFactory*>(KEY_CIRCULO,factory));
	factory = new ViewRuedaFactory(juegoController);
	figuraFactory.insert(pair<string, ViewFiguraFactory*>(KEY_RUEDA,factory));
	factory = new ViewGloboFactory(juegoController);
	figuraFactory.insert(pair<string, ViewFiguraFactory*>(KEY_GLOBO,factory));
	factory = new ViewPelotaFactory(juegoController);
	figuraFactory.insert(pair<string, ViewFiguraFactory*>(KEY_PELOTA,factory));
	factory = new ViewResorteFactory(juegoController);
	figuraFactory.insert(pair<string, ViewFiguraFactory*>(KEY_RESORTE,factory));
	factory = new ViewMartilloFactory(juegoController);
	figuraFactory.insert(pair<string, ViewFiguraFactory*>(KEY_MARTILLO,factory));
	factory = new ViewBloqueFactory(juegoController);
	figuraFactory.insert(pair<string, ViewFiguraFactory*>(KEY_BLOQUE,factory));
	factory = new ViewCoheteFactory(juegoController);
	figuraFactory.insert(pair<string, ViewFiguraFactory*>(KEY_COHETE,factory));
	factory = new ViewCarritoFactory(juegoController);
	figuraFactory.insert(pair<string, ViewFiguraFactory*>(KEY_CARRITO,factory));

	list<ViewFiguraFactory*> factories;
	CargadorDeTextures* texturas = CargadorDeTextures::Instance();
	SDL_Texture* canvasTexture = texturas->cargarTexture(FONDO_DEFECTO);
	SDL_Texture* herrTextura = texturas->cargarTexture(FONDO_ZONA_CREACION);
	factories.push_back(new ViewMartilloFactory(juegoController));
	factories.push_back(new ViewBloqueFactory(juegoController));
	factories.push_back(new ViewPelotaFactory(juegoController));
	factories.push_back(new ViewGloboFactory(juegoController));
	factories.push_back(new ViewResorteFactory(juegoController));
	factories.push_back(new ViewRuedaFactory(juegoController));
	factories.push_back(new ViewCoheteFactory(juegoController));
	factories.push_back(new ViewCarritoFactory(juegoController));
	Zona* zonaCreacion = new ZonaCreacion(&factories, 110, 120,
			herrTextura);
	ZonaTablero* zonaTablero = new ZonaTablero(50,70, canvasTexture);
	this->zonaJuego=  new ZonaJuego(zonaCreacion, zonaTablero,
			new Cuadrado(75, 70,0, 150, 100));

	this->juegoController->setZona(this->zonaJuego);

	list<Figura*>& figurasPersistidas = this->bbdd->getFiguras();
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

	return this->juegoController;
}

