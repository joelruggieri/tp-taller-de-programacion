/*
 *
 *  Created on: 14/09/2013
 *      Author: jonathan
 */

#include "InicializadorJuego.h"
#include <iostream>
using namespace std;
#include <list>
#include "../../vista/figura/FiguraView.h"
#include "../viewFactory/ViewCirculoFactory.h"
#include "../viewFactory/ViewTrianguloFactory.h"
#include "../viewFactory/ViewRuedaFactory.h"
#include "../viewFactory/ViewGloboFactory.h"
#include "../viewFactory/ViewPelotaFactory.h"
#include "../viewFactory/ViewMotorFactory.h"
#include "../../vista/CargadorDeTextures.h"
#include "../zonaDragAndDrop/ZonaCreacion.h"
#include "../zonaDragAndDrop/ZonaTablero.h"
#include "../RutasArchivos.h"
#include "../Resizer.h"
#include "../PersistenciaEventController.h"
#include "src/figuraFactory/FiguraFactory.h"
#include "../zonaDragAndDrop/ZonaPlay.h"
const string KEY_CIRCULO= "CIRCULO";
const string KEY_TRIANGULO= "TRIANGULO";
const string KEY_RUEDA = "RUEDA";
const string KEY_GLOBO = "GLOBO";
const string KEY_PELOTA = "PELOTA";

InicializadorJuego::InicializadorJuego(GeneralEventController * controllerEventos, ModeloController * modeloController) {
	this->juegoController = NULL;
	this->eventsController = controllerEventos;
	this->bbdd = new PersistenciaManager();
	this->modeloController = modeloController;
	//TODO EL ROTADOR NO SE BORRA, DONDE SE BORRA?
	this->rotador = new RotadorSistemaCoordenadas();
	this->factory = new FiguraFactory(this->rotador);
	this->tablero = NULL;
}

InicializadorJuego::~InicializadorJuego() {
	delete this->bbdd;
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

void InicializadorJuego::agregarFigura(ViewFiguraFactory* factory,
		Figura* modelo) {
	Resizer * r = Resizer::Instance();
	int x = r->resizearDistanciaLogicaX(modelo->getX());
	int y = r->resizearPosicionLogicaY(modelo->getY());
	int w = r->resizearDistanciaLogicaY(10);
	int h = r->resizearDistanciaLogicaY(10);
	FiguraView * view = factory->crear(x,y,w,h);
	view->setModelo(modelo);
	bool exitoVista = tablero->agregarFigura(view);
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
			tablero->removerFigura(view);
		}
		if (exitoModelo) {
			modeloController->removerFigura(modelo);
		}
		delete view;
		delete modelo;
	}
}

JuegoEventsController * InicializadorJuego::crearZonaJuego() {
	if(tablero != NULL){
		return this->juegoController;
	}
	ZonaPlay * zp = new ZonaPlay(110,5);
	this->juegoController = new JuegoEventsController(modeloController, zp,this->factory, 100);
	ViewFiguraFactory * viewFactory = new ViewTrianguloFactory(juegoController);
	figuraFactory.insert(pair<string, ViewFiguraFactory*>(KEY_TRIANGULO,viewFactory));
	viewFactory = new ViewCirculoFactory(juegoController);
	figuraFactory.insert(pair<string, ViewFiguraFactory*>(KEY_CIRCULO,viewFactory));
	viewFactory = new ViewRuedaFactory(juegoController);
	figuraFactory.insert(pair<string, ViewFiguraFactory*>(KEY_RUEDA,viewFactory));
	viewFactory = new ViewGloboFactory(juegoController);
	figuraFactory.insert(pair<string, ViewFiguraFactory*>(KEY_GLOBO,viewFactory));
	viewFactory = new ViewPelotaFactory(juegoController);
	figuraFactory.insert(pair<string, ViewFiguraFactory*>(KEY_PELOTA,viewFactory));

	list<ViewFiguraFactory*> factories;
	CargadorDeTextures* texturas = CargadorDeTextures::Instance();
	SDL_Texture* canvasTexture = texturas->cargarTexture(FONDO_DEFECTO);
	SDL_Texture* herrTextura = texturas->cargarTexture(FONDO_ZONA_CREACION);
	factories.push_back(new ViewMotorFactory(juegoController));
	factories.push_back(new ViewTrianguloFactory(juegoController));
	factories.push_back(new ViewPelotaFactory(juegoController));
	factories.push_back(new ViewGloboFactory(juegoController));
	factories.push_back(new ViewRuedaFactory(juegoController));
	factories.push_back(new ViewMotorFactory(juegoController));
	factories.push_back(new ViewTrianguloFactory(juegoController));
	factories.push_back(new ViewPelotaFactory(juegoController));
	factories.push_back(new ViewGloboFactory(juegoController));
	factories.push_back(new ViewRuedaFactory(juegoController));


	tablero = new ZonaTablero(50,50, canvasTexture);

	ZonaCreacion* zonaCreacion = new ZonaCreacion(&factories, 110, 10,
			herrTextura);

	this->juegoController->setZonas(tablero, zonaCreacion);

	list<Figura*>& figurasPersistidas = this->bbdd->getFiguras();
	list<Figura*>::iterator it;
	for(it = figurasPersistidas.begin() ; it != figurasPersistidas.end() ; ++it){
		(*it)->setRotador(this->rotador);
		(*it)->acept(this);
	}

	CanvasController* canvasController = new CanvasController(tablero->getCanvas());
	canvasController->cambiarFondo(this->bbdd->getImagenFondo());
	PersistenciaEventController * persistenciaController= new PersistenciaEventController (this->modeloController,canvasController, this->bbdd);
	this->eventsController->setCanvasController(canvasController);
	this->eventsController->setGuardarController(persistenciaController);
	this->eventsController->addMouseController(this->juegoController,1,1);

	return this->juegoController;
}

void InicializadorJuego::visit(Motor*) {
}

void InicializadorJuego::visit(Plataforma*) {
}

