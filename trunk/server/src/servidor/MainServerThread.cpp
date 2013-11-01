/*
 * MainServerThread.cpp
 *
 *  Created on: 26/10/2013
 *      Author: jonathan
 */

#include "MainServerThread.h"
#include "src/Logger.h"
#include "src/controller/PersistenciaManager.h"
#include "Partida.h"
#include <sys/socket.h>
#include <netinet/in.h>

#define PUERTO 6005


MainServerThread::MainServerThread() {
	PersistenciaManager bbdd;
	n = bbdd.getNivel();
	bbdd.liberarNivel();

}

void MainServerThread::run() {

    int fd1, fd2, puerto ;
    unsigned int clilen;
    struct sockaddr_in serv_addr, cli_addr;
//    int  n;

    printf("Iniciando servidor...\n");


    /* First call to socket() function */
    fd1 = socket(AF_INET, SOCK_STREAM, 0);
    if (fd1 < 0)
    {
        perror("ERROR abriendo socket.\n");

    }

    /* Initialize socket structure */
    bzero((char *) &serv_addr, sizeof(serv_addr));
    puerto = 5001;
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(puerto);

        /* Now bind the host address using bind() call.*/
    if (bind(fd1, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0)
    {
         perror("ERROR on binding");
                 printf("ERROR");
//         return(1);
    }

    listen(fd1,10);
    clilen = sizeof(cli_addr);
//    char auxBuffer[1024];

    while (true)
        {
            fd2 = accept(fd1, (struct sockaddr *) &cli_addr, &clilen);
            if (fd2 < 0)
            {
                perror("ERROR on accept");
                break;
            }

		log.info("Nuevo cliente conectado");
		// responder partida creada
		// cerrar conexion del cliente
		log.info("Nueva partida creada");
//		Partida partida(this->n);
//		partida.run();
	}

}

MainServerThread::~MainServerThread() {
	delete n;
}

