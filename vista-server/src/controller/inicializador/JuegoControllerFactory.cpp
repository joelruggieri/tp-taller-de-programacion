/*
 * JuegoControllerFactory.cpp
 *
 *  Created on: 08/11/2013
 *      Author: joel
 */

#include "JuegoControllerFactory.h"
#include "../viewFactory/ViewGanchoFactory.h"
#include "../viewFactory/ViewGloboFactory.h"
#include "../viewFactory/ViewMotorFactory.h"
#include "../viewFactory/ViewSogaFactory.h"
#include "../viewFactory/ViewPlataformaFactory.h"
#include "../viewFactory/ViewBalancinFactory.h"
#include "../viewFactory/ViewTijeraFactory.h"
#include "../viewFactory/ViewCarritoFactory.h"
#include "../viewFactory/VistaCintaTransportadoraFactory.h"
#include "../viewFactory/ViewBolaBolicheFactory.h"
#include "../viewFactory/ViewPelotaJuegoFactory.h"
#include "../viewFactory/VistaEngranajeFactory.h"
#include "../viewFactory/ViewCorreaFactory.h"
#include "../viewFactory/ViewYunqueFactory.h"
#include "../viewFactory/viewClavoFactory.h"
#include "../viewFactory/ViewPoleaFactory.h"
#include "../editor/SimpleEditorEstirar.h"
#include "../editor/EditorUnion.h"
#include "../editor/SimpleEditorOrientacionCambiable.h"
#include "../editor/SimpleEditorCambiarRadio.h"

const string KEY_GLOBO = TAG_FACTORY_GLOBO;
const string KEY_PLATAFORMA = TAG_FACTORY_PLATAFORMA;
const string KEY_SOGA = TAG_FACTORY_SOGA;
const string KEY_BALANCIN = TAG_FACTORY_BALANCIN;
const string KEY_TIJERA = TAG_FACTORY_TIJERA;
const string KEY_CARRITO = TAG_FACTORY_CARRITO;
const string KEY_CINTA = TAG_FACTORY_CINTA;
const string KEY_BOLA_BOLICHE = TAG_FACTORY_BOLA;
const string KEY_PELOTA_JUEGO = TAG_FACTORY_PELOTA;
const string KEY_GANCHO = TAG_FACTORY_GANCHO;
const string KEY_ENGRANAJE = TAG_FACTORY_ENGRANAJE;
const string KEY_MOTOR = TAG_FACTORY_MOTOR;
const string KEY_CORREA = TAG_FACTORY_CORREA;
const string KEY_YUNQUE = TAG_FACTORY_YUNQUE;
const string KEY_CLAVO = TAG_FACTORY_CLAVO;
const string KEY_POLEA = TAG_FACTORY_POLEA;
JuegoControllerFactory::JuegoControllerFactory(ZonaTablero* tablero, ModeloController* modeloController) {
	this->tablero = tablero;
	this->modeloController = modeloController;
	this->factory = new FiguraFactory();
	ViewFiguraFactory * viewFactory;
	/////// creo el mapa de todas las factories que va a tener el juego/////
	list<float> angulosPermitidos1;
	list<float> angulosPermitidos2;
	list<float> angulosPermitidos3;
	angulosPermitidos3.push_back(0.0);
	angulosPermitidos3.push_back(90.0);
	angulosPermitidos3.push_back(180.0);
	angulosPermitidos3.push_back(270.0);
	angulosPermitidos2.push_back(-45.0);
	angulosPermitidos2.push_back(0.0);
	angulosPermitidos2.push_back(45.0);
	SimpleEditorCambiarRadio* editorCambiarRadio = new SimpleEditorCambiarRadio(modeloController,tablero,this->factory, 100);
	editores.push_back(editorCambiarRadio);
	SimpleEditorAnguloFijo* editorSimpleAnguloFijo3 = new SimpleEditorAnguloFijo(modeloController,tablero,this->factory, 100,angulosPermitidos3);
	editores.push_back(editorSimpleAnguloFijo3);
	SimpleEditorAnguloFijo * editorSimpleAnguloFijo1 = new SimpleEditorAnguloFijo(modeloController,tablero,this->factory, 100,angulosPermitidos1);
	editores.push_back(editorSimpleAnguloFijo1);
	SimpleEditorAnguloFijo * editorSimpleAnguloFijo2 = new SimpleEditorAnguloFijo(modeloController,tablero,this->factory, 100,angulosPermitidos2);
	editores.push_back(editorSimpleAnguloFijo2);
	SimpleEditorNivel * editorSimple = new SimpleEditorNivel(modeloController,tablero,this->factory, 100);
	SimpleEditorEstirar * editorSimpleEstirar = new SimpleEditorEstirar(modeloController,tablero,this->factory, 100);
//	SimpleEditorEstirar * editorSimpleEstirar2 = (SimpleEditorEstirar *)editorSimpleEstirar->clone();
	editores.push_back(editorSimpleEstirar);
	EditorUnion* editorunion = new EditorUnion(modeloController, tablero, this->factory, 100);
	editores.push_back(editorunion);
	SimpleEditorOrientacionCambiable* editorOrientacionCambiable = new SimpleEditorOrientacionCambiable(modeloController, tablero, this->factory, 100);
	editores.push_back(editorOrientacionCambiable);
	viewFactory = new ViewBalancinFactory(editorSimpleAnguloFijo2,0);
	this->factoriesDelJuego.insert(pair<string, ViewFiguraFactory*>(KEY_BALANCIN,viewFactory));
	viewFactory = new ViewTijeraFactory(editorSimpleAnguloFijo3,0);
	this->factoriesDelJuego.insert(pair<string, ViewFiguraFactory*>(KEY_TIJERA,viewFactory));
	viewFactory = new ViewCarritoFactory(editorSimple,0);
	this->factoriesDelJuego.insert(pair<string, ViewFiguraFactory*>(KEY_CARRITO,viewFactory));
	viewFactory = new ViewPelotaJuegoFactory(editorSimpleAnguloFijo1,0);
	this->factoriesDelJuego.insert(pair<string, ViewFiguraFactory*>(KEY_PELOTA_JUEGO,viewFactory));
	viewFactory = new ViewBolaBolicheFactory(editorSimpleAnguloFijo1,0);
	this->factoriesDelJuego.insert(pair<string, ViewFiguraFactory*>(KEY_BOLA_BOLICHE,viewFactory));
	viewFactory = new ViewGloboFactory(editorSimpleAnguloFijo1,0);
	this->factoriesDelJuego.insert(pair<string, ViewFiguraFactory*>(KEY_GLOBO,viewFactory));
	viewFactory = new ViewGanchoFactory(editorSimpleAnguloFijo1,0);
	this->factoriesDelJuego.insert(pair<string, ViewFiguraFactory*>(KEY_GANCHO,viewFactory));

	viewFactory = new ViewPoleaFactory(editorSimpleAnguloFijo1,0);
	this->factoriesDelJuego.insert(pair<string, ViewFiguraFactory*>(KEY_POLEA,viewFactory));

	viewFactory = new ViewPlataformaFactory(editorSimpleEstirar,0);
	this->factoriesDelJuego.insert(pair<string, ViewFiguraFactory*>(KEY_PLATAFORMA,viewFactory));
	viewFactory = new VistaCintaTransportadoraFactory(editorSimpleEstirar,0);
	this->factoriesDelJuego.insert(pair<string, ViewFiguraFactory*>(KEY_CINTA,viewFactory));
	viewFactory = new ViewSogaFactory(editorunion,0);
	this->factoriesDelJuego.insert(pair<string, ViewFiguraFactory*>(KEY_SOGA,viewFactory));
	viewFactory = new ViewCorreaFactory(editorunion,0);
	this->factoriesDelJuego.insert(pair<string, ViewFiguraFactory*>(KEY_CORREA,viewFactory));
	viewFactory = new VistaEngranajeFactory(editorCambiarRadio,0);
	this->factoriesDelJuego.insert(pair<string, ViewFiguraFactory*>(KEY_ENGRANAJE,viewFactory));
	viewFactory = new ViewMotorFactory(editorOrientacionCambiable,0);
	this->factoriesDelJuego.insert(pair<string, ViewFiguraFactory*>(KEY_MOTOR,viewFactory));
	viewFactory = new ViewYunqueFactory(editorSimpleAnguloFijo1,0);
	this->factoriesDelJuego.insert(pair<string, ViewFiguraFactory*>(KEY_YUNQUE,viewFactory));
	viewFactory = new viewClavoFactory(editorSimpleAnguloFijo3,0);
	this->factoriesDelJuego.insert(pair<string, ViewFiguraFactory*>(KEY_CLAVO,viewFactory));
}

JuegoEventsController* JuegoControllerFactory::crearConfiguracionJugador(Jugador* jugador){
	std::map<std::string,int> configuracionFactories;
	std::list<ViewFiguraFactory*> factories;
	ViewFiguraFactory* viewFiguraClone;
	jugador->recibirMapaConfiguracion(configuracionFactories);
	std::map<std::string,int>::iterator it;
	for(it = configuracionFactories.begin(); it != configuracionFactories.end(); ++it){
		std::map<std::string,ViewFiguraFactory*>::iterator iter = this->factoriesDelJuego.find((*it).first);
		if(iter != this->factoriesDelJuego.end()){
			viewFiguraClone = iter->second->clone((*it).second);
			factories.push_back(viewFiguraClone);
		} else {
		}
	}
	ZonaCreacion* zona = new ZonaCreacion(factories);
	JuegoEventsController* juegoEventsController = new JuegoEventsController(this->tablero,this->modeloController,zona, jugador->getArea(),jugador->getNumero());
	return juegoEventsController;
}

JuegoControllerFactory::~JuegoControllerFactory() {
	std::map<std::string,ViewFiguraFactory*>::iterator itViewFactory;
	for(itViewFactory = this->factoriesDelJuego.begin(); itViewFactory != this->factoriesDelJuego.end(); ++itViewFactory){
		delete(itViewFactory->second);
	}
	std::list<DropController*>::iterator itEditores;
	for(itEditores = this->editores.begin(); itEditores != this->editores.end(); ++itEditores){
		delete (*itEditores);
	}
}


