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
#include "src/Serializador.h"
using namespace std;

Partida::Partida(Nivel* n, int socket) {
	nivel = n;
	//ENTREGA3 dispo = new Disponibilidad(n->getNumeroJugadores());
	dispo = new Disponibilidad(3);
	colaIn = new ColaEventos();
	colaOut = new ColaEventos();
	this->socket = socket;
	cleaner = new ThreadCleaner (dispo);
	generalController = new GeneralEventController();
	//ENTREGA3 VER QUIEN RECIBE LOS MSJS DEL CLIENTE.
	receiver = new EventReceptorThread(colaIn,generalController,NULL, NULL);
}

Partida::~Partida() {
	// TODO Auto-generated destructor stub
}

void Partida::procesarRequest(int socketDesc, Serializador& serializador) {
	ThreadStatus* status = this->dispo->getNextFree();
	if (status == NULL) {
         log.info("Se rechaza cliente por maximo de conexiones");
         MensajePlano msj(MSJ_JUGADOR_RECHAZADO);
         serializador.escribir(&msj,socketDesc);
         close(socketDesc);
	} else {
		log.info("Se acepta nuevo cliente");
        MensajePlano msj(MSJ_JUGADOR_ACEPTADO);
        serializador.escribir(&msj,socketDesc);
		status->lock();
		IOThread* jugadorNuevo = new IOThread(this->colaIn, status->getColaSalida(),status,socketDesc,status->getNroJugador());
		status->setThread(jugadorNuevo);
		status->unlock();
		jugadorNuevo->run();
	}

}

void Partida::run(int fdJugador1) {
	Serializador serializador(0);
	cleaner->run(5);
	procesarRequest(fdJugador1,serializador);
	while (true) {
		receiver->run();
		sleep(2);
		struct sockaddr_in cli_addr;
		unsigned int clilen;
		clilen = sizeof(cli_addr);
		int fd2 = accept(socket, (struct sockaddr *) &cli_addr, &clilen);
		log.info("Cliente intentado conectar");
		procesarRequest(fd2,serializador);
	}

}
