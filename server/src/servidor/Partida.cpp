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
	dispo = new Disponibilidad(n->getJugadores());
	cola = new ColaEventos();
	this->socket = socket;
	cleaner = new ThreadCleaner (dispo);
}

Partida::~Partida() {
	// TODO Auto-generated destructor stub
}

void Partida::run() {
	Logger log;
	Serializador serializador;
	cleaner->run(5);
	while (true) {
		sleep(2);
		struct sockaddr_in cli_addr;
		unsigned int clilen;
		clilen = sizeof(cli_addr);
		int fd2 = accept(socket, (struct sockaddr *) &cli_addr, &clilen);
		log.info("Cliente intentado conectar");

		ThreadStatus* status = this->dispo->getNextFree();
		if (status == NULL) {
	         MensajePlano msj("REBOTE");
	         serializador.escribir(&msj,fd2);
	         log.info("Se rechaza cliente por maximo de conexiones");
			close(fd2);
		} else {
			log.info("Se acepta nuevo cliente");
	        MensajePlano msj("JUGADOR_ACEPTADO");
	        serializador.escribir(&msj,fd2);
			status->lock();
			IOThread* jugadorNuevo = new IOThread(this->cola, status->getColaSalida(),status,fd2);
			status->setThread(jugadorNuevo);
			status->unlock();
			jugadorNuevo->run();

		}

	}

}
