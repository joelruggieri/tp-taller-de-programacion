/*
 * JuegoControllerFactory.cpp
 *
 *  Created on: 08/11/2013
 *      Author: joel
 */

#include "JuegoControllerFactory.h"
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
#include "../editor/SimpleEditorEstirar.h"
#include "../editor/EditorUnion.h"
#include "../editor/SimpleEditorOrientacionCambiable.h"
#include "../editor/SimpleEditorCambiarRadio.h"

const string KEY_GLOBO = TAG_FACTORY_GLOBO;
const string KEY_PLATAFORMA = TAG_FACTORY_PLATAFORMA;
const string KEY_SOGA = TAG_FACTORY_SOGA;
const string KEY_BALANCIN = TAG_FACTORY_BALANCIN;
const string KEY_CINTA = TAG_FACTORY_CINTA;
const string KEY_BOLA_BOLICHE = TAG_FACTORY_BOLA;
const string KEY_PELOTA_JUEGO = TAG_FACTORY_PELOTA;
const string KEY_ENGRANAJE = TAG_FACTORY_ENGRANAJE;
const string KEY_MOTOR = TAG_FACTORY_MOTOR;
const string KEY_CORREA = TAG_FACTORY_CORREA;

JuegoControllerFactory::JuegoControllerFactory(ZonaTablero* tablero, ModeloController* modeloController) {
	this->tablero = tablero;
	this->modeloController = modeloController;
	this->factory = new FiguraFactory();
	ViewFiguraFactory * viewFactory;
	/////// creo el mapa de todas las factories que va a tener el juego/////
	list<float> angulosPermitidos1;
	list<float> angulosPermitidos2;
	angulosPermitidos2.push_back(-45.0);
	angulosPermitidos2.push_back(0.0);
	angulosPermitidos2.push_back(45.0);
	SimpleEditorCambiarRadio* editorCambiarRadio = new SimpleEditorCambiarRadio(modeloController,tablero,this->factory, 100);
	SimpleEditorAnguloFijo * editorSimpleAnguloFijo1 = new SimpleEditorAnguloFijo(modeloController,tablero,this->factory, 100,angulosPermitidos1);
	SimpleEditorAnguloFijo * editorSimpleAnguloFijo2 = new SimpleEditorAnguloFijo(modeloController,tablero,this->factory, 100,angulosPermitidos2);
	//SimpleEditorNivel * editorSimple = new SimpleEditorNivel(modeloController,tablero,this->factory, 100);
	SimpleEditorEstirar * editorSimpleEstirar = new SimpleEditorEstirar(modeloController,tablero,this->factory, 100);
	EditorUnion* editorunion = new EditorUnion(modeloController, tablero, this->factory, 100);
	SimpleEditorOrientacionCambiable* editorOrientacionCambiable = new SimpleEditorOrientacionCambiable(modeloController, tablero, this->factory, 100);
	//EditorDeEstiramientoDeCinta* editorCinta = new EditorDeEstiramientoDeCinta(modeloController, tablero, this->factory, 100);
	viewFactory = new ViewBalancinFactory(editorSimpleAnguloFijo2,0);
	this->factoriesDelJuego.insert(pair<string, ViewFiguraFactory*>(KEY_BALANCIN,viewFactory));
	viewFactory = new ViewPelotaJuegoFactory(editorSimpleAnguloFijo1,0);
	this->factoriesDelJuego.insert(pair<string, ViewFiguraFactory*>(KEY_PELOTA_JUEGO,viewFactory));
	viewFactory = new ViewBolaBolicheFactory(editorSimpleAnguloFijo1,0);
	this->factoriesDelJuego.insert(pair<string, ViewFiguraFactory*>(KEY_BOLA_BOLICHE,viewFactory));
	viewFactory = new ViewGloboFactory(editorSimpleAnguloFijo1,0);
	this->factoriesDelJuego.insert(pair<string, ViewFiguraFactory*>(KEY_GLOBO,viewFactory));
	viewFactory = new ViewPlataformaFactory(editorSimpleEstirar,0);
	this->factoriesDelJuego.insert(pair<string, ViewFiguraFactory*>(KEY_PLATAFORMA,viewFactory));
	viewFactory = new VistaCintaTransportadoraFactory(editorSimpleEstirar,0);
	this->factoriesDelJuego.insert(pair<string, ViewFiguraFactory*>(KEY_CINTA,viewFactory));
	viewFactory = new ViewSogaFactory(editorunion,0);
	this->factoriesDelJuego.insert(pair<string, ViewFiguraFactory*>(KEY_SOGA,viewFactory));
	viewFactory = new ViewCorreaFactory(editorunion,0);
	this->factoriesDelJuego.insert(pair<string, ViewFiguraFactory*>(KEY_CORREA,viewFactory));
	// ENTREGA3 NO SE SI VAN ESTAS DOS.
	/*viewFactory = new ViewSogaFactory(editorunion,0);
	this->factoriesDelJuego.insert(pair<string, ViewFiguraFactory*>(OBJ_UNION_S_SOGA,viewFactory));
	viewFactory = new ViewCorreaFactory(editorunion,0);
	this->factoriesDelJuego.insert(pair<string, ViewFiguraFactory*>(OBJ_UNION_S_CORREA,viewFactory));*/
	viewFactory = new VistaEngranajeFactory(editorCambiarRadio,0);
	this->factoriesDelJuego.insert(pair<string, ViewFiguraFactory*>(KEY_ENGRANAJE,viewFactory));
	viewFactory = new ViewMotorFactory(editorOrientacionCambiable,0);
	this->factoriesDelJuego.insert(pair<string, ViewFiguraFactory*>(KEY_MOTOR,viewFactory));

}

JuegoEventsController* JuegoControllerFactory::crearConfiguracionJugador(Jugador* jugador){
	std::map<std::string,int> configuracionFactories;
	std::list<ViewFiguraFactory*> factories;
	ViewFiguraFactory* viewFigura;
	ViewFiguraFactory* viewFiguraClone;
	jugador->recibirMapaConfiguracion(configuracionFactories);
	std::map<std::string,int>::iterator it;
	for(it = configuracionFactories.begin(); it != configuracionFactories.end(); ++it){
		std::map<std::string,ViewFiguraFactory*>::iterator iter = this->factoriesDelJuego.find((*it).first);
		viewFiguraClone = iter->second->clone((*it).second);
		factories.push_back(viewFiguraClone);
	}
	ZonaCreacion* zona = new ZonaCreacion(factories);
	JuegoEventsController* juegoEventsController = new JuegoEventsController(this->tablero,this->modeloController,zona);
	return juegoEventsController;
}

JuegoControllerFactory::~JuegoControllerFactory() {
	// TODO Auto-generated destructor stub
}

