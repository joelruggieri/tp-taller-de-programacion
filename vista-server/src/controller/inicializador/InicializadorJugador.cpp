/*
 *
 *  Created on: 14/09/2013
 *      Author: jonathan
 */

#include "InicializadorJugador.h"

#include <string>

using namespace std;
#include <list>
#include "../zonaDragAndDrop/ZonaCreacion.h"
#include "../zonaDragAndDrop/ZonaTablero.h"
#include "src/figuraFactory/FiguraFactory.h"
#include "../zonaDragAndDrop/ZonaPlay.h"

InicializadorJugador::InicializadorJugador(ZonaTablero * tablero, ModeloController * modeloController) {
	this->modeloController = modeloController;
	this->tablero = tablero;
}

InicializadorJugador::~InicializadorJugador() {
}

//JuegoEventsController * InicializadorJuegador::crearZonaJuego() {
//	if(tablero != NULL){
//		return this->juegoController;
//	}
//	ZonaPlay * zp = new ZonaPlay(110,5);
//	CargadorDeTextures* texturas = CargadorDeTextures::Instance();
//	SDL_Texture* canvasTexture = texturas->cargarTexture(FONDO_DEFECTO);
//	tablero = new ZonaTablero(50,50, canvasTexture);
//
//
//
//	list<float> angulosPermitidos1;
//	list<float> angulosPermitidos2;
//	angulosPermitidos2.push_back(-45.0);
//	angulosPermitidos2.push_back(0.0);
//	angulosPermitidos2.push_back(45.0);
//	SimpleEditorCambiarRadio* editorCambiarRadio = new SimpleEditorCambiarRadio(modeloController,tablero,this->factory, 100);
//	SimpleEditorAnguloFijo * editorSimpleAnguloFijo1 = new SimpleEditorAnguloFijo(modeloController,tablero,this->factory, 100,angulosPermitidos1);
//	SimpleEditorAnguloFijo * editorSimpleAnguloFijo2 = new SimpleEditorAnguloFijo(modeloController,tablero,this->factory, 100,angulosPermitidos2);
//	SimpleEditorEstirar * editorSimpleEstirar = new SimpleEditorEstirar(modeloController,tablero,this->factory, 100);
//	EditorUnion* editorunion = new EditorUnion(modeloController, tablero, this->factory, 100);
//	SimpleEditorOrientacionCambiable* editorOrientacionCambiable = new SimpleEditorOrientacionCambiable(modeloController, tablero, this->factory, 100);
//	this->juegoController = new JuegoEventsController(modeloController, zp);
//
//	list<ViewFiguraFactory*> factories;
//
//	SDL_Texture* herrTextura = texturas->cargarTexture(FONDO_ZONA_CREACION);
//	ViewFiguraFactory * viewFactory;
//
//
//	viewFactory = new ViewGloboFactory(editorSimpleAnguloFijo1);
//	figuraFactory.insert(pair<string, ViewFiguraFactory*>(KEY_GLOBO,viewFactory));
//	factories.push_back(viewFactory);
//	viewFactory = new ViewPlataformaFactory(editorSimpleEstirar);
//	figuraFactory.insert(pair<string, ViewFiguraFactory*>(KEY_PLATAFORMA,viewFactory));
//	factories.push_back(viewFactory);
//	viewFactory = new ViewBolaBolicheFactory(editorSimpleAnguloFijo1);
//	figuraFactory.insert(pair<string, ViewFiguraFactory*>(KEY_BOLA_BOLICHE,viewFactory));
//	factories.push_back(viewFactory);
//	viewFactory = new ViewPelotaJuegoFactory(editorSimpleAnguloFijo1);
//	figuraFactory.insert(pair<string, ViewFiguraFactory*>(KEY_PELOTA_JUEGO,viewFactory));
//	factories.push_back(viewFactory);
//	viewFactory = new ViewBalancinFactory(editorSimpleAnguloFijo2);
//	figuraFactory.insert(pair<string, ViewFiguraFactory*>(KEY_BALANCIN,viewFactory));
//	factories.push_back(viewFactory);
//	viewFactory = new VistaCintaTransportadoraFactory(editorSimpleEstirar);
//	figuraFactory.insert(pair<string, ViewFiguraFactory*>(KEY_CINTA,viewFactory));
//	factories.push_back(viewFactory);
//	viewFactory = new VistaEngranajeFactory(editorCambiarRadio);
//	figuraFactory.insert(pair<string, ViewFiguraFactory*>(KEY_ENGRANAJE,viewFactory));
//	factories.push_back(viewFactory);
//	viewFactory = new ViewMotorFactory(editorOrientacionCambiable);
//	figuraFactory.insert(pair<string, ViewFiguraFactory*>(KEY_MOTOR,viewFactory));
//	factories.push_back(viewFactory);
//
//
//	viewFactory = new ViewSogaFactory(editorunion);
//	factories.push_back(viewFactory);
//
//	viewFactory = new ViewSogaDinamicaFactory(editorunion);
//	figuraFactory.insert(pair<string, ViewFiguraFactory*>(KEY_SOGA,viewFactory));
//
//
//	viewFactory = new ViewCorreaFactory(editorunion);
//	factories.push_back(viewFactory);
//	viewFactory = new ViewCorreaDinamicaFactory(editorunion);
//	figuraFactory.insert(pair<string, ViewFiguraFactory*>(KEY_CORREA,viewFactory));
//
//
//
//	ZonaCreacion* zonaCreacion = new ZonaCreacion(&factories, 110, 10,
//			herrTextura);
//
//	this->juegoController->setZonas(tablero, zonaCreacion);
//
//	list<Figura*>& figurasPersistidas = this->bbdd->getFiguras();
//	list<Figura*>::iterator it;
//	for(it = figurasPersistidas.begin() ; it != figurasPersistidas.end() ; ++it){
//		(*it)->acept(this);
//	}
//
//	return this->juegoController;
//}

JuegoEventsController* InicializadorJugador::crearController(Jugador*) {
//	ZonaPlay * zp = new ZonaPlay(110, 5);
//	JuegoEventsController* juegoEventsController = new JuegoEventsController(this->modeloController, zp);

//	ZonaCreacion* zonaCreacion = new ZonaCreacion(&factories, 110, 10, herrTextura);
//	juegoEventsController->setZonas(tablero, zonaCreacion);
	return NULL;

}
