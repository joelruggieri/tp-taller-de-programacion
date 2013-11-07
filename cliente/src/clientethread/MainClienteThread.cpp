/*
 * MainClienteThread.cpp
 *
 *  Created on: 01/11/2013
 *      Author: ezequiel
 */

#include "MainClienteThread.h"
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <list>
#include "src/mensajes/userEvents/ClickMsj.h"
#include <src/Serializador.h>
#include <list>
#include "src/ConstantesComunicacion.h"
#include "src/Logger.h"
#include "src/SerializacionException.h"
#include "src/ConexionException.h"
#include "src/threading/IOThread.h"
#include "errno.h"
#include "src/controller/MainController.h"
using namespace std;
using namespace CLIENTE;
MainClienteThread::MainClienteThread() {
	colaEntrada = new ColaEventos();
	colaSalida = new ColaEventos();
	thread = 0;
}

MainClienteThread::~MainClienteThread() {
}

void MainClienteThread::run() {
	if (thread == 0) {
		int sockfd;
		RESULTADO_CONEXION result = conectar(sockfd);
		if (SERVIDOR_CONECTADO == result) {
			log.info("Conectado con servidor");
			Status* status = new Status(TIMEOUT);
			thread = new IOThread(colaEntrada, colaSalida, status, sockfd, 0);
			thread->run();
			MainController controller(colaEntrada,colaSalida);
			controller.run();
		}
		if (SERVIDOR_ERROR == result) {
			log.error("No se puede conectar con el servidor, no se ha obtenido respuesta");
		}
		if (SERVIDOR_OCUPADO == result) {
			log.info("No se puede conectar con el servidor, no hay ningun lugar disponible");
		}
//		MainController controller(colaEntrada,colaSalida);
//		controller.run();
	}
}

RESULTADO_CONEXION MainClienteThread::conectar(int &sockfd) {

	//INTENTO CONECTAR 5 VECES y devuelvo a ver que paso.
	int cont = 0;
	string tag;
	RESULTADO_CONEXION resultretry;
	for (cont = 0; cont < 5; ++cont) {
		try {
			string respuesta = tryConnect(sockfd);
			tag = MSJ_JUGADOR_ACEPTADO;
			if (respuesta == tag) {
				return SERVIDOR_CONECTADO;
			}
			tag = MSJ_JUGADOR_RECHAZADO;
			if (respuesta == tag) {
				close(sockfd);
				sockfd = 0;
				log.info("Maxima cantidad de jugadores superada");
				resultretry = SERVIDOR_OCUPADO;
			}
		} catch (ConexionException & e) {
			log.error("No se pudo conectar con el servidor");
			sockfd = 0;
			resultretry = SERVIDOR_ERROR;
		}
		sleep(1);
	}
	return resultretry;
}

string MainClienteThread::tryConnect(int& socketfd) {
	struct sockaddr_in dest_addr;
	log.info("Intentando conectar con servidor");
	// Guardará la dirección de destino
	socketfd = socket(AF_INET, SOCK_STREAM, 0); // ¡Comprueba errores!
	dest_addr.sin_family = AF_INET;
	// Ordenación de máquina
	dest_addr.sin_port = htons(6000);
	// short, Ordenación de la red
	dest_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
	memset(&(dest_addr.sin_zero), '\0', 8); // Poner a cero el resto de la estructura
	int st = connect(socketfd, (struct sockaddr *) &dest_addr, sizeof(struct sockaddr));
	if (st == -1) {
		//ENTREGA3 CHEQUEAR TIPOS DE ERROR
//		cout << strerror(errno) << endl;
		if (ManejadorErrores::manejarConectError(errno) < 0 )
		throw ConexionException("No se pudo conectar con el servidor");
	}

	Logger log;
	Serializador ser(0);
	std::list<NetworkMensaje*> leer;
	try {
		ser.leer(socketfd, leer);
	} catch (SerializacionException & e) {
		throw ConexionException("No se pudo conectar con el servidor");
	}

	if (leer.size() != 1) {
		log.error("El server no contesto de la forma esperada");
		throw ConexionException("El server no contesto de la forma esperada");
	}

	MensajePlano * msj = (MensajePlano*) leer.front();
	string tag = msj->getMensaje();
	delete msj;
	return tag;
}
