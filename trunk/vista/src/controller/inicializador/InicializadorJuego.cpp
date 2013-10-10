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
#include <memory>
#include <new>
#include <string>
#include <utility>

#include "../../vista/Canvas.h"
#include "../CanvasController.h"
#include "../GeneralEventController.h"
#include "../JuegoEventsController.h"
#include "../PersistenciaManager.h"
#include "../RotadorSistemaCoordenadas.h"
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
#include "../editor/SimpleEditorOrientacionCambiable.h"

const string KEY_GLOBO = "GLOBO";
const string KEY_PLATAFORMA = "PLATAFORMA";
const string KEY_SOGA = "SOGA";
const string KEY_BALANCIN = "BALANCIN";
const string KEY_CINTA = "CINTA";
const string KEY_BOLA_BOLICHE = "BOLABOLICHE";
const string KEY_PELOTA_JUEGO = "PELOTA";
InicializadorJuego::InicializadorJuego(GeneralEventController * controllerEventos, ModeloController * modeloController) {
	this->juegoController = NULL;
	this->eventsController = controllerEventos;
	this->bbdd = new PersistenciaManager();
	this->modeloController = modeloController;
	//TODO EL ROTADOR NO SE BORRA, DONDE SE BORRA?
	this->rotador = new RotadorSistemaCoordenadas();
	this->factory = new FiguraFactory(this->rotador);
	this->tablero = NULL;
	this->validador= new ValidadorEstatico (0,100,0,100);
}

InicializadorJuego::~InicializadorJuego() {
	delete this->bbdd;
	delete validador;
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

void InicializadorJuego::agregarFigura(ViewFiguraFactory* factory,
		Figura* modelo) {
	Resizer * r = Resizer::Instance();
	Logger log;
	validador->validar(modelo);
	if(! validador->isValido()){
		string msj = "Se omite figura de tipo '" + modelo->getReg().getEtiqueta() +"' error en la linea ";
		log.concatenar(msj, modelo->getReg().getLinea());
		msj = msj + ". Error: " + validador->getErrorValidacion();
		log.warning(msj);
		return;
	}


	Transformacion trans;
	trans.traslacion(0, 100);
	trans.escalar(r->getRelacionX(), r->getRelacionY());
	trans.invertir(false, true);
	float x,y;
	int w,h;
	trans.setVector(modelo->getX(), modelo->getY());
	trans.getResultadoInverso(x,y);
	w = r->resizearDistanciaLogicaY(10);
	h = r->resizearDistanciaLogicaY(10);
	FiguraView * view = factory->crear(x,y,w,h);
	view->setModelo(modelo);
	modelo->setVista(view);
	bool exitoVista = tablero->agregarFigura(view);
	bool exitoModelo = this->modeloController->crearFigura(modelo);
	if (!exitoVista || !exitoModelo) {
		string msj = "La figura de tipo '"+ modelo->getReg().getEtiqueta() +"' en la linea ";
		log.concatenar(msj, modelo->getReg().getLinea());
		msj = msj + " Posee un error de solapamiento o de union y es omitida";
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
	map<string, ViewFiguraFactory*>::iterator iter = this->figuraFactory.find(KEY_BOLA_BOLICHE);
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



	list<float> angulosPermitidos1;
	list<float> angulosPermitidos2;
	angulosPermitidos2.push_back(-45.0);
	angulosPermitidos2.push_back(0.0);
	angulosPermitidos2.push_back(45.0);
	SimpleEditorAnguloFijo * editorSimpleAnguloFijo1 = new SimpleEditorAnguloFijo(modeloController,tablero,this->factory, 100,angulosPermitidos1);
	SimpleEditorAnguloFijo * editorSimpleAnguloFijo2 = new SimpleEditorAnguloFijo(modeloController,tablero,this->factory, 100,angulosPermitidos2);
//	SimpleEditorNivel * editorSimple = new SimpleEditorNivel(modeloController,tablero,this->factory, 100);
	SimpleEditorEstirar * editorSimpleEstirar = new SimpleEditorEstirar(modeloController,tablero,this->factory, 100);
	SimpleEditorSoga* editorSogas = new SimpleEditorSoga(modeloController, tablero, this->factory, 100);
	SimpleEditorOrientacionCambiable* editorOrientacionCambiable = new SimpleEditorOrientacionCambiable(modeloController, tablero, this->factory, 100);
	this->juegoController = new JuegoEventsController(modeloController, zp);

	list<ViewFiguraFactory*> factories;

	SDL_Texture* herrTextura = texturas->cargarTexture(FONDO_ZONA_CREACION);
	ViewFiguraFactory * viewFactory;


	viewFactory = new ViewGloboFactory(editorSimpleAnguloFijo1);
	figuraFactory.insert(pair<string, ViewFiguraFactory*>(KEY_GLOBO,viewFactory));
	factories.push_back(viewFactory);
	viewFactory = new ViewPlataformaFactory(editorSimpleEstirar);
	figuraFactory.insert(pair<string, ViewFiguraFactory*>(KEY_PLATAFORMA,viewFactory));
	factories.push_back(viewFactory);
	viewFactory = new ViewBolaBolicheFactory(editorSimpleAnguloFijo1);
	figuraFactory.insert(pair<string, ViewFiguraFactory*>(KEY_BOLA_BOLICHE,viewFactory));
	factories.push_back(viewFactory);
	viewFactory = new ViewPelotaJuegoFactory(editorSimpleAnguloFijo1);
	figuraFactory.insert(pair<string, ViewFiguraFactory*>(KEY_PELOTA_JUEGO,viewFactory));
	factories.push_back(viewFactory);
	viewFactory = new ViewBalancinFactory(editorSimpleAnguloFijo2);
	figuraFactory.insert(pair<string, ViewFiguraFactory*>(KEY_BALANCIN,viewFactory));
	factories.push_back(viewFactory);
	viewFactory = new VistaCintaTransportadoraFactory(editorSimpleAnguloFijo1);
	figuraFactory.insert(pair<string, ViewFiguraFactory*>(KEY_CINTA,viewFactory));
	factories.push_back(viewFactory);


//TODO como todavía no vienen de la persistencia no se las coloca para levantar de la persistencia
//	factories.push_back(new ViewMotorFactory(editorSimpleAnguloFijo1));
	factories.push_back(new ViewMotorFactory(editorOrientacionCambiable));
	factories.push_back(new ViewSogaFactory(editorSogas));

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
	//TODO IMPLEMENTAR PERSISTENCIA
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
