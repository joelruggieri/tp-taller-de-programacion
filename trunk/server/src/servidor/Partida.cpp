/*
 * Partida.cpp
 *
 *  Created on: 24/10/2013
 *      Author: jonathan
 */

#include "Partida.h"
#include "src/threading/IOThread.h"
#include "threading/ThreadStatus.h"
#include "src/mensajes/MensajePlano.h"
#include "src/mensajes/internos/ConexionUsuario.h"
#include "src/mensajes/ConfiguracionNivelMsj.h"
#include "src/Serializador.h"
#include "src/ManejadorErrores.h"
#include "src/controller/DrawController.h"
#include "src/controller/FlujoDeJuegoController.h"
using namespace std;

Partida::Partida(Nivel* n, int socket) {
	nivel = n;
	dispo = new Disponibilidad(n->getJugadores());
	colaIn = new ColaEventos();
	colaOut = new ColaEventos();
	cleaner = new ThreadCleaner(dispo, colaIn);
	iniciarGeneralEventController();
	drawingService = new DrawThread(colaIn);
	receiver = new EventReceptorThread(colaIn, generalController, NULL, NULL, generalController);
	dispatcher = new EventDispatcherThread(colaOut, dispo);
	fisicaService = new StepModeloThread(colaIn);
	recepcionThread = new RecepcionClientesThread(socket, colaIn, dispo);
}

Partida::~Partida() {
	delete recepcionThread;
	delete dispo;
	delete colaIn;
	delete colaOut;
	delete generalController;
	delete cleaner;
	delete drawingService;
	delete receiver;
	delete modeloController;
	delete tablero;
	delete controllersFactory;
	delete objetivo;
}

void Partida::iniciarGeneralEventController() {
	this->modeloController = new ModeloController();
	this->inicializadorJuego = new InicializadorJuego(this->nivel, this->modeloController);
	this->objetivo = inicializadorJuego->crearObjetivo();
	this->tablero = this->inicializadorJuego->crearTablero(objetivo);
	this->controllersFactory = new JuegoControllerFactory(tablero, modeloController);
	DrawController * dc = new DrawController(colaOut);
	dc->setTablero(tablero);
	FlujoDeJuegoController * fcontroller = new FlujoDeJuegoController(modeloController, objetivo);
	generalController = new GeneralEventController(dc, fcontroller);
	list<Jugador*>::iterator it;
	JuegoEventsController * jugador;
	for (it = nivel->getJugadores().begin(); it != nivel->getJugadores().end(); ++it) {
		jugador = controllersFactory->crearConfiguracionJugador((*it));
		generalController->addJugador(jugador);
		fcontroller->addJugador(jugador);
		//ENTREGA3 VERIFICAR ESTO.
		modeloController->addArea((*it)->getArea(), (*it)->getNumero());
	}
}

void Partida::run(int fdJugador1) {
	cleaner->run(5);
	dispatcher->run();
	receiver->run();
	drawingService->run();
	fisicaService->run();
	recepcionThread->procesarRequest(fdJugador1);
	recepcionThread->run();
	while (!objetivo->isCumplido()) {
		sleep(2);
	}
	recepcionThread->cancel();
	receiver->cancel();
	cleaner->cancel();
	fisicaService->cancel();
	sleep(1);
	drawingService->cancel();
	sleep(1);
	dispatcher->cancel();
}
