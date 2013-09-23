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

void InicializadorJuego::visit(Rueda* c) {
	map<string, ViewFiguraFactory*>::iterator iter = this->figuraFactory.find(KEY_RUEDA);
	this->agregarFigura(iter->second, c);
}

void InicializadorJuego::visit(Globo* c) {
	map<string, ViewFiguraFactory*>::iterator iter = this->figuraFactory.find(KEY_GLOBO);
	this->agregarFigura(iter->second, c);
}

void InicializadorJuego::visit(Pelota* c) {
	map<string, ViewFiguraFactory*>::iterator iter = this->figuraFactory.find(KEY_PELOTA);
	this->agregarFigura(iter->second, c);
}

void InicializadorJuego::visit(Resorte* c) {
	map<string, ViewFiguraFactory*>::iterator iter = this->figuraFactory.find(KEY_RESORTE);
	this->agregarFigura(iter->second, c);
}

void InicializadorJuego::visit(Martillo* c) {
	map<string, ViewFiguraFactory*>::iterator iter = this->figuraFactory.find(KEY_MARTILLO);
	this->agregarFigura(iter->second, c);
}

void InicializadorJuego::visit(Bloque* c) {
	map<string, ViewFiguraFactory*>::iterator iter = this->figuraFactory.find(KEY_BLOQUE);
	this->agregarFigura(iter->second, c);
}

void InicializadorJuego::visit(Cohete* c) {
	map<string, ViewFiguraFactory*>::iterator iter = this->figuraFactory.find(KEY_COHETE);
	this->agregarFigura(iter->second, c);
}

void InicializadorJuego::visit(Carrito* c) {
	map<string, ViewFiguraFactory*>::iterator iter = this->figuraFactory.find(KEY_CARRITO);
	this->agregarFigura(iter->second, c);
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
		string msj = "Figura con posicion invalida, es omitida (";
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
	}
}

JuegoEventsController * InicializadorJuego::crearZonaJuego() {
	if(zonaJuego != NULL){
		return this->juegoController;
	}

	this->juegoController = new JuegoEventsController(modeloController,new FiguraFactory(this->rotador), 20);
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
		unsigned int size = this->modeloController->getFiguras().size();
		(*it)->acept(this);
		cout<< (*it)->getRotacion()<< endl;
		//TODO HACER LA PRUEBA CON ESTO, Y VER QUE ONDA.
		if(size == this->modeloController->getFiguras().size()){
			delete (*it);
		}
	}

	CanvasController* canvasController = new CanvasController(zonaTablero->getCanvas());
	PersistenciaEventController * persistenciaController= new PersistenciaEventController (this->modeloController, this->bbdd);
	this->eventsController->setCanvasController(canvasController);
	this->eventsController->setGuardarController(persistenciaController);
	this->eventsController->addMouseController(this->juegoController,1,1);

	return this->juegoController;
}

