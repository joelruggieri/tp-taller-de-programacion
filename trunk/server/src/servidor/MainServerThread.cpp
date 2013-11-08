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
#include <src/Serializador.h>
#include "yaml-cpp/yaml.h"
#include "src/mensajes/MensajePlano.h"
#include <string>
#include <unistd.h>
#include "src/ConexionException.h"
#include "errno.h"
using namespace std;

//#define PUERTO 6005
//#define PUERTO 6006
#define PUERTO 6000
MainServerThread::MainServerThread() {
	PersistenciaManager bbdd;
	//n = bbdd.getNivel();
	//bbdd.liberarNivel();*/
	NivelDAO* dao = new NivelDAO();
	n = dao->leerNivel("nivelPruebaCorrecto.yaml");

}

void MainServerThread::run() {
//	Serializador serializador;
	int fd1, fd2, puerto;
	unsigned int clilen;
	struct sockaddr_in serv_addr, cli_addr;
//    int  n;
	log.info("Iniciando servidor...");

	/* First call to socket() function */
	fd1 = socket(AF_INET, SOCK_STREAM, 0);
	if (fd1 < 0) {
		perror("ERROR abriendo socket.\n");
		throw ConexionException("No se pudo generar socket");
	}

	/* Initialize socket structure */
	bzero((char *) &serv_addr, sizeof(serv_addr));
	puerto = PUERTO;
	serv_addr.sin_family = AF_INET;
	serv_addr.sin_addr.s_addr = INADDR_ANY;
	serv_addr.sin_port = htons(puerto);
	memset(&(serv_addr.sin_zero), '\0', 8);

	/* Now bind the host address using bind() call.*/
	if (bind(fd1, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
		perror("ERROR on binding");
		printf("ERROR");
//         return(1);
		if(ManejadorErrores::manejarBindError(errno) < 0)
		{
			throw ConexionException("No se realiza conexion, problema de bindeo");
		}
	}

	if (listen(fd1, 10) < 0)
		{
		perror("ERROR on listening");
		printf("ERROR");
		if (ManejadorErrores::manejarListenError(errno) < 0)
			throw ConexionException("No se realiza conexion, problema al escuchar clientes");
		}
	clilen = sizeof(cli_addr);
//    char auxBuffer[1024];
	string msj = "Servidor escuchando pedidos en el puerto ";
	log.concatenar(msj, puerto);
	log.info(msj);
	while (true) {
		//ENTREGA3 ESTO SE PUEDE COLGAR, LOS ACEPTS PODRÍAN IR EN OTRO THREAD.

		fd2 = accept(fd1, (struct sockaddr *) &cli_addr, &clilen);
		if (fd2 < 0) {
			perror("ERROR on accept");
			 if (ManejadorErrores::manejarAceptError(errno) < 0)
			 throw ConexionException("No se realiza conexion, aceptar cliente");



		}
		log.info("Nuevo cliente conectado");
		log.info("Nueva partida creada");
		Partida partida(this->n, fd1);
		partida.run(fd2);
	}

}

MainServerThread::~MainServerThread() {
	delete n;
}

