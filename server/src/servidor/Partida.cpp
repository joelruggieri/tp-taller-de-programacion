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
#include "threading/JugadorThread.h"
#include "threading/ThreadStatus.h"
#include "src/mensajes/MensajePlano.h"
#include "src/Serializador.h"
using namespace std;

Partida::Partida(Nivel* n, int socket) {
	nivel = n;
	dispo = new Disponibilidad(n->getJugadores());
	cola = new ColaEventos();
	this->socket = socket;

}

Partida::~Partida() {
	// TODO Auto-generated destructor stub
}

void Partida::run() {
	Logger log;
	Serializador serializador;
	while (true) {
		sleep(2);
		struct sockaddr_in cli_addr;
		unsigned int clilen;
		clilen = sizeof(cli_addr);
		int fd2 = accept(socket, (struct sockaddr *) &cli_addr, &clilen);
		log.info("cliente conectado");
		ThreadStatus* status = this->dispo->getNextFree();
		if (status == NULL) {
	         MensajePlano msj("PARTIDA_CREADA");
	         serializador.escribir(&msj,fd2);
			close(fd2);
		} else {
	        MensajePlano msj("JUGADOR_ACEPTADO");
	        serializador.escribir(&msj,fd2);
			status->lock();
			status->setSocketDesc(fd2);
			JugadorThread* jugadorNuevo = new JugadorThread(this->cola, status);
			status->setThread(jugadorNuevo);
			status->unlock();
			jugadorNuevo->run();

		}

	}

}
