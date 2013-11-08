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
#include "src/mensajes/ConfiguracionNivelMsj.h"
#include "src/Serializador.h"
#include "src/ManejadorErrores.h"
#include "src/controller/DrawController.h"
using namespace std;

Partida::Partida(Nivel* n, int socket) {
	nivel = n;
	//ENTREGA3 dispo = new Disponibilidad(n->getNumeroJugadores());
	dispo = new Disponibilidad(n->getJugadores());
	colaIn = new ColaEventos();
	colaOut = new ColaEventos();
	this->socket = socket;
	cleaner = new ThreadCleaner(dispo);
	drawingService = new DrawThread(colaIn);
	generalController = new GeneralEventController(n->getJugadores(), new DrawController(colaOut));
	receiver = new EventReceptorThread(colaIn, generalController, NULL, NULL, generalController);
	dispatcher = new EventDispatcherThread(colaOut,dispo);
}

Partida::~Partida() {
	receiver->cancel();
	cleaner->cancel();
	drawingService->cancel();
	dispatcher->cancel();
	delete dispo;
	delete colaIn;
	delete colaOut;
	delete generalController;
	delete cleaner;
	delete drawingService;
	delete receiver;
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
		status->lock(); //TODO ENTREGA3 VER SI EL LOCK VA ACA O MAS ABAJO
		mensaje->setXArea(status->getJugador()->getArea()->getX());
		mensaje->setYArea(status->getJugador()->getArea()->getY());
		mensaje->setAnchoArea(status->getJugador()->getArea()->getAncho());
		mensaje->setAltoArea(status->getJugador()->getArea()->getAlto());
		std::list<std::string> tags;
		status->getJugador()->recibirTags(tags);
		std::list<std::string>::iterator it;
		for (it = tags.begin(); it != tags.end(); it++) {
			mensaje->agregarTagFactory(*it);
		}
		serializador.escribir(mensaje, socketDesc);
		//status->lock();
		IOThread* jugadorNuevo = new IOThread(this->colaIn, status->getColaSalida(), status, socketDesc,
				status->getNroJugador());
		status->setThread(jugadorNuevo);
		status->unlock();
		jugadorNuevo->run();
	}

}

void Partida::run(int fdJugador1) {
	Serializador serializador(0);
	cleaner->run(5);
	dispatcher->run();
	receiver->run();
	drawingService->run();

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
