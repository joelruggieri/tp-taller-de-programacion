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
#include "JugadorThread.h"
#include "ThreadStatus.h"
using namespace std;
#define PUERTO 5001

Partida::Partida(Nivel* n) {
	nivel = n;
	dispo = new Disponibilidad(n->getJugadores());
	cola = new ColaEventos();

}

Partida::~Partida() {
	// TODO Auto-generated destructor stub
}

void Partida::run() {
	int fd1, puerto;
	unsigned int clilen;
	struct sockaddr_in serv_addr, cli_addr;
	fd1 = socket(AF_INET, SOCK_STREAM, 0);
	if (fd1 < 0) {
		perror("ERROR abriendo socket.\n");	//TODO loguear errores
		exit(1);
	}
	bzero((char *) &serv_addr, sizeof(serv_addr));
	puerto = PUERTO;
	serv_addr.sin_family = AF_INET;
	serv_addr.sin_addr.s_addr = INADDR_ANY;
	serv_addr.sin_port = htons(puerto);

//	if (bind(fd1, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
//		perror("ERROR on binding");
//		exit(1);		//TODO loguear errores
//	}

	listen(fd1, nivel->getJugadores());
	clilen = sizeof(cli_addr);
	//Ciclo para aceptar jugadores va aca ?

	while (true) {

		ThreadStatus* status = this->dispo->getNextFree();
		if (status == NULL) {
			//abortar conexion
		} else {
			int fd2 = accept(fd1, (struct sockaddr *) &cli_addr, &clilen);
			status->lock();
			status->setSocketDesc(fd2);
			JugadorThread* jugadorNuevo = new JugadorThread(this->cola, status);
			status->setThread(jugadorNuevo);
			status->unlock();
			jugadorNuevo->run();

		}

	}

}
