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
MainServerThread::MainServerThread() {
	PersistenciaManager bbdd;
	n = bbdd.getNivel();
	bbdd.liberarNivel();

}

void MainServerThread::run() {


	while(true){
		//ENTREGA3 EZE:

		// socket espera nueva conexion, borrar sleep
		sleep(1);
		log.info("Nuevo cliente conectado");
		// responder partida creada
		// cerrar conexion del cliente
		log.info("Nueva partida creada");
		Partida partida(this->n);
		partida.run();
	}

}

MainServerThread::~MainServerThread() {
	delete n;
}

