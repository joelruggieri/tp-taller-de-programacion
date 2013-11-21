/*
 * Partida.cpp
 *
 *  Created on: 24/10/2013
 *      Author: jonathan
 */

#include "Partida.h"
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <errno.h>
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
	//ENTREGA3 dispo = new Disponibilidad(n->getNumeroJugadores());
	dispo = new Disponibilidad(n->getJugadores());
	colaIn = new ColaEventos();
	colaOut = new ColaEventos();
	this->socket = socket;
	cleaner = new ThreadCleaner(dispo,colaIn);
	iniciarGeneralEventController();
	drawingService = new DrawThread(colaIn);
	receiver = new EventReceptorThread(colaIn, generalController, NULL, NULL, generalController);
	dispatcher = new EventDispatcherThread(colaOut, dispo);
	fisicaService = new StepModeloThread(colaIn);
}

Partida::~Partida() {
	receiver->cancel();
	cleaner->cancel();
	drawingService->cancel();
	dispatcher->cancel();
	fisicaService->cancel();
	delete dispo;
	delete colaIn;
	delete colaOut;
	delete generalController;
	delete cleaner;
	delete drawingService;
	delete receiver;
	delete generalController;
	delete modeloController;
	delete tablero;
	delete controllersFactory;
}

void Partida::procesarRequest(int socketDesc, Serializador& serializador) {
	ThreadStatus* status = this->dispo->getNextFree();
	if (status == NULL) {
		log.info("Se rechaza cliente por maximo de conexiones");
		MensajePlano msj(MSJ_JUGADOR_RECHAZADO);
		serializador.escribir(&msj, socketDesc);
		close(socketDesc);
	} else {
		log.info("Se acepta nuevo cliente");
		//creo el mensaje de configuracion del nivel para ese jugador
		ConfiguracionNivelMsj* mensaje = new ConfiguracionNivelMsj();
		status->lock();
		mensaje->setXArea(status->getJugador()->getArea()->getX());
		mensaje->setYArea(status->getJugador()->getArea()->getY());
		mensaje->setAnchoArea(status->getJugador()->getArea()->getAncho());
		mensaje->setAltoArea(status->getJugador()->getArea()->getAlto());
		mensaje->setObjetivo("Incredible Machine");
		std::list<std::string> tags;
		status->getJugador()->recibirTags(tags);
		std::list<std::string>::iterator it;
		for (it = tags.begin(); it != tags.end(); it++) {
			mensaje->agregarTagFactory(*it);
		}
		MensajePlano msj(MSJ_JUGADOR_ACEPTADO);
		list<NetworkMensaje *> msjs;
		msjs.push_back(&msj);
		msjs.push_back(mensaje);
		serializador.escribir(msjs, socketDesc);
		//status->lock();
		IOThread* jugadorNuevo = new IOThread(this->colaIn, status->getColaSalida(), status, socketDesc,
				status->getNroJugador(),false);
		status->setThread(jugadorNuevo);
		ConexionUsuario * aceptado = new ConexionUsuario(true);
		aceptado->setDestinatario(status->getNroJugador());
		colaIn->push(aceptado);
		status->unlock();
		jugadorNuevo->run();
		usleep(10000);
		delete mensaje;
	}

}

void Partida::iniciarGeneralEventController() {
	this->modeloController = new ModeloController();
	this->inicializadorJuego = new InicializadorJuego(this->nivel,this->modeloController);
	this->tablero = this->inicializadorJuego->crearTablero();
	this->controllersFactory = new JuegoControllerFactory(tablero, modeloController);
	DrawController * dc = new DrawController(colaOut);
	dc->setTablero(tablero);
	FlujoDeJuegoController * fcontroller = new FlujoDeJuegoController(modeloController);
	generalController = new GeneralEventController(dc,fcontroller);
	list<Jugador*>::iterator it;
	JuegoEventsController * jugador;
	for(it= nivel->getJugadores().begin(); it != nivel->getJugadores().end(); ++it){
		jugador = controllersFactory->crearConfiguracionJugador((*it));
		generalController->addJugador(jugador);
		fcontroller->addJugador(jugador);
		//ENTREGA3 VERIFICAR ESTO.
		modeloController->addArea((*it)->getArea(),(*it)->getNumero());
	}
}

void Partida::run(int fdJugador1) {
	Serializador serializador(0);
	cleaner->run(5);
	dispatcher->run();
	receiver->run();
	drawingService->run();
	fisicaService->run();
	procesarRequest(fdJugador1, serializador);
	while (true) {
		sleep(2);
		struct sockaddr_in cli_addr;
		unsigned int clilen;
		clilen = sizeof(cli_addr);
		int fd2 = accept(socket, (struct sockaddr *) &cli_addr, &clilen);
		if (fd2 < 0) { //ENTREGA3 si no conecta no procesa pedido , esta bien ?
			ManejadorErrores::manejarAceptError(errno);
		} else {
			log.info("Cliente intentado conectar");
			procesarRequest(fd2, serializador);
		}
	}

}
