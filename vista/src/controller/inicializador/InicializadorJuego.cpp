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
#include "../viewFactory/ViewRuedaFactory.h"
#include "../viewFactory/ViewGloboFactory.h"
#include "../viewFactory/ViewPelotaFactory.h"
#include "../viewFactory/ViewMotorFactory.h"
#include "../viewFactory/ViewSogaFactory.h"
#include "../viewFactory/ViewPlataformaFactory.h"
#include "../viewFactory/ViewBalancinFactory.h"
#include "../viewFactory/ViewBolaBolicheFactory.h"
#include "../../vista/CargadorDeTextures.h"
#include "../zonaDragAndDrop/ZonaCreacion.h"
#include "../zonaDragAndDrop/ZonaTablero.h"
#include "../RutasArchivos.h"
#include "../Resizer.h"
#include "../PersistenciaEventController.h"
#include "src/figuraFactory/FiguraFactory.h"
#include "../zonaDragAndDrop/ZonaPlay.h"
#include "../editor/SimpleEditorNivel.h"
#include "../editor/SimpleEditorAnguloFijo.h"
#include "../editor/SimpleEditorEstirar.h"
#include "../editor/SimpleEditorSoga.h"
const string KEY_CIRCULO= "CIRCULO";
const string KEY_TRIANGULO= "TRIANGULO";
const string KEY_RUEDA = "RUEDA";
const string KEY_GLOBO = "GLOBO";
const string KEY_PELOTA = "PELOTA";
const string KEY_PLATAFORMA = "PLATAFORMA";
const string KEY_SOGA = "SOGA";
const string KEY_BALANCIN = "BALANCIN";

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

void InicializadorJuego::visit(Pelota* c) {
	Figura * fig = this->factory->crear(c);
	map<string, ViewFiguraFactory*>::iterator iter = this->figuraFactory.find(KEY_PELOTA);
	this->agregarFigura(iter->second, fig);
}

void InicializadorJuego::visit(Plataforma* c) {
	Figura * fig = this->factory->crear(c);
	map<string, ViewFiguraFactory*>::iterator iter = this->figuraFactory.find(KEY_PLATAFORMA);
	this->agregarFigura(iter->second, fig);
}

void InicializadorJuego::visit(Balancin* c) {
	Figura * fig = this->factory->crear(c);
	map<string, ViewFiguraFactory*>::iterator iter = this->figuraFactory.find(KEY_BALANCIN);
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

void InicializadorJuego::visit(BolaBoliche* c) {
	Figura * fig = this->factory->crear(c);
	map<string, ViewFiguraFactory*>::iterator iter = this->figuraFactory.find(KEY_PLATAFORMA);
	this->agregarFigura(iter->second, fig);
}

JuegoEventsController * InicializadorJuego::crearZonaJuego() {
	if(tablero != NULL){
		return this->juegoController;
	}
	ZonaPlay * zp = new ZonaPlay(110,5);
	CargadorDeTextures* texturas = CargadorDeTextures::Instance();
	SDL_Texture* canvasTexture = texturas->cargarTexture(FONDO_DEFECTO);
	tablero = new ZonaTablero(50,50, canvasTexture);

	SimpleEditorNivel * editorSimple = new SimpleEditorNivel(modeloController,tablero,this->factory, 100);
	SimpleEditorAnguloFijo * editorSimpleAnguloFijo = new SimpleEditorAnguloFijo(modeloController,tablero,this->factory, 100);
	SimpleEditorEstirar * editorSimpleEstirar = new SimpleEditorEstirar(modeloController,tablero,this->factory, 100);
	SimpleEditorSoga* editorSogas = new SimpleEditorSoga(modeloController, tablero, this->factory, 100);
	this->juegoController = new JuegoEventsController(modeloController, zp);
	ViewFiguraFactory * viewFactory = new ViewCirculoFactory(editorSimple,editorSimple);
	figuraFactory.insert(pair<string, ViewFiguraFactory*>(KEY_CIRCULO,viewFactory));
	viewFactory = new ViewRuedaFactory(editorSimple,editorSimple);
	figuraFactory.insert(pair<string, ViewFiguraFactory*>(KEY_RUEDA,viewFactory));
	viewFactory = new ViewGloboFactory(editorSimpleAnguloFijo);
	figuraFactory.insert(pair<string, ViewFiguraFactory*>(KEY_GLOBO,viewFactory));
	viewFactory = new ViewPelotaFactory(editorSimple,editorSimple);
	figuraFactory.insert(pair<string, ViewFiguraFactory*>(KEY_PELOTA,viewFactory));
	viewFactory = new ViewPlataformaFactory(editorSimpleEstirar);
	figuraFactory.insert(pair<string, ViewFiguraFactory*>(KEY_PLATAFORMA,viewFactory));

	list<ViewFiguraFactory*> factories;
	SDL_Texture* herrTextura = texturas->cargarTexture(FONDO_ZONA_CREACION);
	factories.push_back(new ViewMotorFactory(editorSimpleAnguloFijo));
	factories.push_back(new ViewPelotaFactory(editorSimple,editorSimple));
	factories.push_back(new ViewGloboFactory(editorSimpleAnguloFijo));
	factories.push_back(new ViewRuedaFactory(editorSimple,editorSimple));
	factories.push_back(new ViewMotorFactory(editorSimpleAnguloFijo));
	factories.push_back(new ViewPelotaFactory(editorSimple,editorSimple));
	factories.push_back(new ViewGloboFactory(editorSimpleAnguloFijo));
	factories.push_back(new ViewRuedaFactory(editorSimple,editorSimple));
	factories.push_back(new ViewPlataformaFactory(editorSimpleEstirar));
	factories.push_back(new ViewBalancinFactory(editorSimpleAnguloFijo));
	factories.push_back(new ViewSogaFactory(editorSogas));
	factories.push_back(new ViewBolaBolicheFactory(editorSimpleAnguloFijo));


	ZonaCreacion* zonaCreacion = new ZonaCreacion(&factories, 110, 10,
			herrTextura);

	this->juegoController->setZonas(tablero, zonaCreacion);

	list<Figura*>& figurasPersistidas = this->bbdd->getFiguras();
	list<Figura*>::iterator it;
	for(it = figurasPersistidas.begin() ; it != figurasPersistidas.end() ; ++it){
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



