/*
 *
 *  Created on: 14/09/2013
 *      Author: jonathan
 */

#include "InicializadorJuego.h"

#include <src/figura/Figura.h>
#include <src/Logger.h>
#include <src/ModeloController.h>
//#include <iostream>
#include <map>
#include <string>

//#include "../GeneralEventController.h"
//#include "../JuegoEventsController.h"
//#include "../PersistenciaManager.h"
#include "../viewFactory/ViewFiguraFactory.h"
#include "../zonaDragAndDrop/ZonaDragAndDrop.h"

using namespace std;
#include <list>
#include "../../vista/figura/FiguraView.h"
#include "../viewFactory/ViewGloboFactory.h"
#include "../viewFactory/ViewMotorFactory.h"
#include "../viewFactory/ViewSogaFactory.h"
#include "../viewFactory/ViewPlataformaFactory.h"
#include "../viewFactory/ViewBalancinFactory.h"
#include "../viewFactory/VistaCintaTransportadoraFactory.h"
#include "../viewFactory/ViewBolaBolicheFactory.h"
#include "../viewFactory/ViewPelotaJuegoFactory.h"
#include "../viewFactory/VistaEngranajeFactory.h"
#include "../viewFactory/ViewCorreaFactory.h"
#include "../viewFactory/ViewCorreaDinamicaFactory.h"
#include "../viewFactory/ViewSogaDinamicaFactory.h"
#include "../zonaDragAndDrop/ZonaCreacion.h"
#include "../zonaDragAndDrop/ZonaTablero.h"
#include "../RutasArchivos.h"
#include "src/figuraFactory/FiguraFactory.h"
const string KEY_GLOBO = "GLOBO";
const string KEY_PLATAFORMA = "PLATAFORMA";
const string KEY_SOGA = "SOGA";
const string KEY_BALANCIN = "BALANCIN";
const string KEY_CINTA = "CINTA";
const string KEY_BOLA_BOLICHE = "BOLABOLICHE";
const string KEY_PELOTA_JUEGO = "PELOTA";
const string KEY_ENGRANAJE = "ENGRANAJE";
const string KEY_MOTOR = "MOTOR";
const string KEY_CORREA = "CORREA";

InicializadorJuego::InicializadorJuego(Nivel* nivel, ModeloController * modeloController) {
	//this->juegoController = NULL;
	//this->eventsController = controllerEventos;
	//this->bbdd = new PersistenciaManager();
	this->modeloController = modeloController;
	this->factory = new FiguraFactory();
	this->nivel = nivel;
	this->tablero = NULL;
	//this->tablero = new ZonaTablero(100,100);
	//this->validador= new ValidadorEstatico (0,100,0,100);
}

InicializadorJuego::~InicializadorJuego() {
	//ENTREGA3 VER QUÈ MAS HAY QUE DELETEAR.
	delete this->factory;

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

void InicializadorJuego::visit(CintaTransportadora* c) {
	Figura * fig = this->factory->crear(c);
	map<string, ViewFiguraFactory*>::iterator iter = this->figuraFactory.find(KEY_CINTA);
	this->agregarFigura(iter->second, fig);
}

void InicializadorJuego::visit(Correa* c) {
	Figura * fig = this->factory->crear(c);
	map<string, ViewFiguraFactory*>::iterator iter = this->figuraFactory.find(KEY_CORREA);
	this->agregarUnion(iter->second, (Correa*)fig);
}

void InicializadorJuego::agregarFigura(ViewFiguraFactory* factory,Figura* modelo) {
	/*Resizer * r = Resizer::Instance();
	Logger log;
	validador->validar(modelo);
	if(! validador->isValido()){
		string msj = "Se omite figura de tipo '" + modelo->getReg().getEtiqueta() +"' error en la linea ";
		log.concatenar(msj, modelo->getReg().getLinea());
		msj = msj + ". Error: " + validador->getErrorValidacion();
		log.warning(msj);
		return;
	}


	Transformacion & trans = r>getTransformacionToModelo();
	float x,y;
	int w,h;
	trans.setVector(modelo->getX(), modelo->getY());
	trans.getResultadoInverso(x,y);
	w = r->resizearDistanciaLogicaX(10);
	h = r->resizearDistanciaLogicaY(10);*/
	FiguraView * view = factory->crear(modelo->getX(),modelo->getY());
	view->setModelo(modelo);
	//view->update();
	modelo->setVista(view);
	bool exitoVista = tablero->agregarFigura(view);
	bool exitoModelo = this->modeloController->crearFigura(modelo);
	if (!exitoVista || !exitoModelo) {
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


void InicializadorJuego::agregarUnion(ViewFiguraFactory* factory,Union* modelo) {
	/*Resizer * r = Resizer::Instance();
	Logger log;
	validador->validar(modelo);
	if(! validador->isValido()){
		string msj = "Se omite figura de tipo '" + modelo->getReg().getEtiqueta() +"' error en la linea ";
		log.concatenar(msj, modelo->getReg().getLinea());
		msj = msj + ". Error: " + validador->getErrorValidacion();
		log.warning(msj);
		return;
	}


	Transformacion & trans = Resizer::Instance()->getTransformacionToModelo();
	float x,y;
	int w,h;
	trans.setVector(modelo->getX(), modelo->getY());
	trans.getResultadoInverso(x,y);
	w = r->resizearDistanciaLogicaX(10);
	h = r->resizearDistanciaLogicaY(10);*/
	FiguraView * view = factory->crear(modelo->getX(),modelo->getY());
	view->setModelo(modelo);
	modelo->setVista(view);
	//view->update();
	bool exitoVista = tablero->agregarFigura(view);
	bool exitoModelo = this->modeloController->crearUnion(modelo);
	if (!exitoVista || !exitoModelo) {
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
	map<string, ViewFiguraFactory*>::iterator iter = this->figuraFactory.find(KEY_BOLA_BOLICHE);
	this->agregarFigura(iter->second, fig);
}

ZonaTablero* InicializadorJuego::crearTablero() {
	if(tablero == NULL){
		tablero = new ZonaTablero(50,50);
	}



	/*list<float> angulosPermitidos1;
	list<float> angulosPermitidos2;
	angulosPermitidos2.push_back(-45.0);
	angulosPermitidos2.push_back(0.0);
	angulosPermitidos2.push_back(45.0);
	SimpleEditorCambiarRadio* editorCambiarRadio = new SimpleEditorCambiarRadio(modeloController,tablero,this->factory, 100);
	SimpleEditorAnguloFijo * editorSimpleAnguloFijo1 = new SimpleEditorAnguloFijo(modeloController,tablero,this->factory, 100,angulosPermitidos1);
	SimpleEditorAnguloFijo * editorSimpleAnguloFijo2 = new SimpleEditorAnguloFijo(modeloController,tablero,this->factory, 100,angulosPermitidos2);	SimpleEditorNivel * editorSimple = new SimpleEditorNivel(modeloController,tablero,this->factory, 100);
	SimpleEditorEstirar * editorSimpleEstirar = new SimpleEditorEstirar(modeloController,tablero,this->factory, 100);
	EditorUnion* editorunion = new EditorUnion(modeloController, tablero, this->factory, 100);
	SimpleEditorOrientacionCambiable* editorOrientacionCambiable = new SimpleEditorOrientacionCambiable(modeloController, tablero, this->factory, 100);
	EditorDeEstiramientoDeCinta* editorCinta = new EditorDeEstiramientoDeCinta(modeloController, tablero, this->factory, 100);
	this->juegoController = new JuegoEventsController(modeloController, zp);
	list<ViewFiguraFactory*> factories;

	//SDL_Texture* herrTextura = texturas->cargarTexture(FONDO_ZONA_CREACION);*/
	ViewFiguraFactory * viewFactory;


	viewFactory = new ViewGloboFactory(NULL,0);
	figuraFactory.insert(pair<string, ViewFiguraFactory*>(KEY_GLOBO,viewFactory));
	//factories.push_back(viewFactory);
	viewFactory = new ViewPlataformaFactory(NULL,0);
	figuraFactory.insert(pair<string, ViewFiguraFactory*>(KEY_PLATAFORMA,viewFactory));
	//factories.push_back(viewFactory);
	viewFactory = new ViewBolaBolicheFactory(NULL,0);
	figuraFactory.insert(pair<string, ViewFiguraFactory*>(KEY_BOLA_BOLICHE,viewFactory));
	//factories.push_back(viewFactory);
	viewFactory = new ViewPelotaJuegoFactory(NULL,0);
	figuraFactory.insert(pair<string, ViewFiguraFactory*>(KEY_PELOTA_JUEGO,viewFactory));
	//factories.push_back(viewFactory);
	viewFactory = new ViewBalancinFactory(NULL,0);
	figuraFactory.insert(pair<string, ViewFiguraFactory*>(KEY_BALANCIN,viewFactory));
	//factories.push_back(viewFactory);
	viewFactory = new VistaCintaTransportadoraFactory(NULL,0);
	figuraFactory.insert(pair<string, ViewFiguraFactory*>(KEY_CINTA,viewFactory));
	//factories.push_back(viewFactory);
	viewFactory = new VistaEngranajeFactory(NULL,0);
	figuraFactory.insert(pair<string, ViewFiguraFactory*>(KEY_ENGRANAJE,viewFactory));
	//factories.push_back(viewFactory);
	viewFactory = new ViewMotorFactory(NULL,0);
	figuraFactory.insert(pair<string, ViewFiguraFactory*>(KEY_MOTOR,viewFactory));
	//factories.push_back(viewFactory);

	/*viewFactory = new ViewSogaFactory(NULL);
	factories.push_back(viewFactory);*/
	viewFactory = new ViewSogaDinamicaFactory(NULL,0);
	figuraFactory.insert(pair<string, ViewFiguraFactory*>(KEY_SOGA,viewFactory));
	/*viewFactory = new ViewCorreaFactory(NULL);
	factories.push_back(viewFactory);*/
	viewFactory = new ViewCorreaDinamicaFactory(NULL,0);
	figuraFactory.insert(pair<string, ViewFiguraFactory*>(KEY_CORREA,viewFactory));

	list<Figura*>& figurasNivel = this->nivel->getFiguras();
	list<Figura*>::iterator it;
	for(it = figurasNivel.begin() ; it != figurasNivel.end() ; ++it){
		(*it)->acept(this);
	}

	/*CanvasController* canvasController = new CanvasController(tablero->getCanvas());
	canvasController->cambiarFondo(this->bbdd->getImagenFondo());
	PersistenciaEventController * persistenciaController= new PersistenciaEventController (this->modeloController,canvasController, this->bbdd);
	this->eventsController->setCanvasController(canvasController);
	this->eventsController->setGuardarController(persistenciaController);
	this->eventsController->addMouseController(this->juegoController,1,1);*/
	ZonaTablero* unTablero = this->tablero;
	this->tablero = NULL;
	return unTablero;

}

void InicializadorJuego::visit(Motor* c) {
	Figura * fig = this->factory->crear(c);
	map<string, ViewFiguraFactory*>::iterator iter = this->figuraFactory.find(KEY_MOTOR);
	this->agregarFigura(iter->second, fig);
}

void InicializadorJuego::visit(PelotaJuego* c) {

		Figura * fig = this->factory->crear(c);
		map<string, ViewFiguraFactory*>::iterator iter = this->figuraFactory.find(KEY_PELOTA_JUEGO);
		this->agregarFigura(iter->second, fig);

}

void InicializadorJuego::visit(GloboHelio*c) {
	Figura * fig = this->factory->crear(c);
	map<string, ViewFiguraFactory*>::iterator iter = this->figuraFactory.find(KEY_GLOBO);
	this->agregarFigura(iter->second, fig);
}

void InicializadorJuego::visit(Engranaje* c) {
	Figura * fig = this->factory->crear(c);
	map<string, ViewFiguraFactory*>::iterator iter = this->figuraFactory.find(KEY_ENGRANAJE);
	this->agregarFigura(iter->second, fig);
}

void InicializadorJuego::visit(Soga* c) {
		Figura * fig = this->factory->crear(c);
		map<string, ViewFiguraFactory*>::iterator iter = this->figuraFactory.find(KEY_SOGA);
		this->agregarUnion(iter->second, (Soga*)fig);
}
