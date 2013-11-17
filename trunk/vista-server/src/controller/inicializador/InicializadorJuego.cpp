/*
 *
 *  Created on: 14/09/2013
 *      Author: jonathan
 */

#include "InicializadorJuego.h"

#include <src/figura/Figura.h>
#include <src/Logger.h>
#include <src/ModeloController.h>
#include <map>
#include <string>
#include "../viewFactory/ViewFiguraFactory.h"
#include "../zonaDragAndDrop/ZonaDragAndDrop.h"

using namespace std;
#include <list>
#include "../../vista/figura/FiguraView.h"
#include "../viewFactory/ViewGanchoFactory.h"
#include "../viewFactory/ViewPoleaFactory.h"
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
#include "../viewFactory/ViewCorreaDinamicaFactory.h"
#include "../viewFactory/ViewSogaDinamicaFactory.h"
#include "../viewFactory/ViewYunqueFactory.h"
#include "../viewFactory/viewClavoFactory.h"
#include "../zonaDragAndDrop/ZonaCreacion.h"
#include "../zonaDragAndDrop/ZonaTablero.h"
#include "../RutasArchivos.h"
#include "src/figuraFactory/FiguraFactory.h"
const string KEY_GLOBO = "GLOBO";
const string KEY_PLATAFORMA = "PLATAFORMA";
const string KEY_SOGA = "SOGA";
const string KEY_BALANCIN = "BALANCIN";
const string KEY_TIJERA = "TIJERA";
const string KEY_CARRITO = "CARRITO";
const string KEY_CINTA = "CINTA";
const string KEY_BOLA_BOLICHE = "BOLABOLICHE";
const string KEY_PELOTA_JUEGO = "PELOTA";
const string KEY_ENGRANAJE = "ENGRANAJE";
const string KEY_MOTOR = "MOTOR";
const string KEY_CORREA = "CORREA";
const string KEY_GANCHO = "GANCHO";
const string KEY_YUNQUE = "YUNQUE";
const string KEY_CLAVO = "CLAVO";
const string KEY_POLEA = "POLEA";
InicializadorJuego::InicializadorJuego(Nivel* nivel, ModeloController * modeloController) {
	this->modeloController = modeloController;
	this->factory = new FiguraFactory();
	this->nivel = nivel;
	this->tablero = NULL;
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

void InicializadorJuego::visit(Tijera* c) {
	Figura * fig = this->factory->crear(c);
	map<string, ViewFiguraFactory*>::iterator iter = this->figuraFactory.find(KEY_TIJERA);
	this->agregarFigura(iter->second, fig);
}

void InicializadorJuego::visit(Carrito* c) {
	Figura * fig = this->factory->crear(c);
	map<string, ViewFiguraFactory*>::iterator iter = this->figuraFactory.find(KEY_CARRITO);
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
	FiguraView * view = factory->crear(modelo->getX(),modelo->getY());
	view->setModelo(modelo);
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
	ViewFiguraFactory * viewFactory;

	viewFactory = new ViewGanchoFactory(NULL,0);
	figuraFactory.insert(pair<string, ViewFiguraFactory*>(KEY_GANCHO,viewFactory));

	viewFactory = new ViewPoleaFactory(NULL,0);
	figuraFactory.insert(pair<string, ViewFiguraFactory*>(KEY_POLEA,viewFactory));

	viewFactory = new ViewGloboFactory(NULL,0);
	figuraFactory.insert(pair<string, ViewFiguraFactory*>(KEY_GLOBO,viewFactory));
	viewFactory = new ViewPlataformaFactory(NULL,0);
	figuraFactory.insert(pair<string, ViewFiguraFactory*>(KEY_PLATAFORMA,viewFactory));
	viewFactory = new ViewBolaBolicheFactory(NULL,0);
	figuraFactory.insert(pair<string, ViewFiguraFactory*>(KEY_BOLA_BOLICHE,viewFactory));
	viewFactory = new ViewPelotaJuegoFactory(NULL,0);
	figuraFactory.insert(pair<string, ViewFiguraFactory*>(KEY_PELOTA_JUEGO,viewFactory));
	viewFactory = new ViewBalancinFactory(NULL,0);
	figuraFactory.insert(pair<string, ViewFiguraFactory*>(KEY_BALANCIN,viewFactory));
	viewFactory = new ViewTijeraFactory(NULL,0);
	figuraFactory.insert(pair<string, ViewFiguraFactory*>(KEY_TIJERA,viewFactory));
	viewFactory = new ViewCarritoFactory(NULL,0);
	figuraFactory.insert(pair<string, ViewFiguraFactory*>(KEY_CARRITO,viewFactory));
	viewFactory = new VistaCintaTransportadoraFactory(NULL,0);
	figuraFactory.insert(pair<string, ViewFiguraFactory*>(KEY_CINTA,viewFactory));
	viewFactory = new VistaEngranajeFactory(NULL,0);
	figuraFactory.insert(pair<string, ViewFiguraFactory*>(KEY_ENGRANAJE,viewFactory));
	viewFactory = new ViewMotorFactory(NULL,0);
	figuraFactory.insert(pair<string, ViewFiguraFactory*>(KEY_MOTOR,viewFactory));

	viewFactory = new ViewSogaDinamicaFactory(NULL,0);
	figuraFactory.insert(pair<string, ViewFiguraFactory*>(KEY_SOGA,viewFactory));
	viewFactory = new ViewCorreaDinamicaFactory(NULL,0);
	figuraFactory.insert(pair<string, ViewFiguraFactory*>(KEY_CORREA,viewFactory));
	viewFactory = new ViewYunqueFactory(NULL,0);
	figuraFactory.insert(pair<string, ViewFiguraFactory*>(KEY_YUNQUE,viewFactory));
	viewFactory = new viewClavoFactory(NULL,0);
	figuraFactory.insert(pair<string, ViewFiguraFactory*>(KEY_CLAVO,viewFactory));


	list<Figura*>& figurasNivel = this->nivel->getFiguras();
	list<Figura*>::iterator it;
	for(it = figurasNivel.begin() ; it != figurasNivel.end() ; ++it){
		(*it)->acept(this);
	}

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

void InicializadorJuego::visit(Gancho* c) {
	Figura * fig = this->factory->crear(c);
	map<string, ViewFiguraFactory*>::iterator iter = this->figuraFactory.find(KEY_GANCHO);
	this->agregarFigura(iter->second, fig);
}

void InicializadorJuego::visit(Yunque* c) {
	Figura * fig = this->factory->crear(c);
		map<string, ViewFiguraFactory*>::iterator iter = this->figuraFactory.find(KEY_YUNQUE);
		this->agregarFigura(iter->second, fig);
}

void InicializadorJuego::visit(Clavo* c) {
	Figura * fig = this->factory->crear(c);
		map<string, ViewFiguraFactory*>::iterator iter = this->figuraFactory.find(KEY_CLAVO);
		this->agregarFigura(iter->second, fig);
}

void InicializadorJuego::visit(Polea* c) {
	Figura * fig = this->factory->crear(c);
		map<string, ViewFiguraFactory*>::iterator iter = this->figuraFactory.find(KEY_POLEA);
		this->agregarFigura(iter->second, fig);
}
