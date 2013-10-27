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
using namespace std;

#define PUERTO 5001

Partida::Partida(Nivel* n) {
	nivel = n;
	dispo = new Disponibilidad(n->getJugadores());
	cola = new ColaEntrada();
}

Partida::~Partida() {
	// TODO Auto-generated destructor stub
}

void Partida::run() {
	int fd1, puerto;
	struct sockaddr_in serv_addr;
	fd1 = socket(AF_INET, SOCK_STREAM, 0);
	 if (fd1 < 0)
	    {
	        perror("ERROR abriendo socket.\n");	//TODO loguear errores
	        exit(1);
	    }
	  bzero((char *) &serv_addr, sizeof(serv_addr));
	    puerto = PUERTO;
	    serv_addr.sin_family = AF_INET;
	    serv_addr.sin_addr.s_addr = INADDR_ANY;
	    serv_addr.sin_port = htons(puerto);

//	    if (bind(fd1, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0)
//	        {
//	             perror("ERROR on binding");
//	             exit(1);		//TODO loguear errores
//	        }

//	    	    listen(fd1,nivel->getJugadores);
	    //Ciclo para aceptar jugadores va aca ?  ->>>>> SI


}
