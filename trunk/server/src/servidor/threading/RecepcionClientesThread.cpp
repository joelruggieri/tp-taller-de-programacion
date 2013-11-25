/*
 * RecepcionClientesThread.cpp
 *
 *  Created on: 07/11/2013
 *      Author: jonathan
 */

#include "RecepcionClientesThread.h"
#include "src/SerializacionException.h"
#include "src/mensajes/ConfiguracionNivelMsj.h"
#include "ThreadStatus.h"
#include "src/mensajes/internos/ConexionUsuario.h"
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <errno.h>
#include "src/ManejadorErrores.h"
void procesarRequestFunc(int socketDesc, Serializador* serializador, Disponibilidad * dispo, ColaEventos * colaIn, string desc){
	ThreadStatus* status = dispo->getNextFree();
	Logger log;
	if (status == NULL) {
		log.info("Se rechaza cliente por maximo de conexiones");
		MensajePlano msj(MSJ_JUGADOR_RECHAZADO);
		try {
			serializador->escribir(&msj, socketDesc);
		} catch (SerializacionException& e) {
			log.error("No se pudo enviar mensajes al cliente");
		}
		close(socketDesc);
	} else {
		log.info("Se acepta nuevo cliente");
		//creo el mensaje de configuracion del nivel para ese jugador
		ConfiguracionNivelMsj* mensaje = new ConfiguracionNivelMsj();
		status->lock();
		mensaje->setXArea(status->getJugador()->getArea()->getX());
		mensaje->setYArea(status->getJugador()->getArea()->getY());
		mensaje->setAnchoArea(status->getJugador()->getArea()->getAncho());
		mensaje->setAltoArea(status->getJugador()->getArea()->getAlto());
		mensaje->setObjetivo(desc);
		std::list<std::string> tags;
		status->getJugador()->recibirTags(tags);
		std::list<std::string>::iterator it;
		for (it = tags.begin(); it != tags.end(); it++) {
			mensaje->agregarTagFactory(*it);
		}
		MensajePlano msj(MSJ_JUGADOR_ACEPTADO);
		list<NetworkMensaje *> msjs;
		msjs.push_back(&msj);
		msjs.push_back(mensaje);
		try {
			serializador->escribir(msjs, socketDesc);
			//status->lock();
			IOThread* jugadorNuevo = new IOThread(colaIn,
					status->getColaSalida(), status, socketDesc,
					status->getNroJugador(), false);
			status->setThread(jugadorNuevo);
			ConexionUsuario * aceptado = new ConexionUsuario(true);
			aceptado->setDestinatario(status->getNroJugador());
			colaIn->push(aceptado);
			status->unlock();
			jugadorNuevo->run();
			usleep(10000);
		} catch (SerializacionException& e) {
			log.error("No se pudo completar la recepcion del jugador");
		}
		delete mensaje;
	}

}

void * recepcionClientesThread(void * arg) {
	ZonaSeguraMemoria * zonaSegura = (ZonaSeguraMemoria *) arg;
	RecepcionClientesThreadParams * params = (RecepcionClientesThreadParams*)zonaSegura->getParams();
	Disponibilidad * dispo = params->getDisponibilidad();
	int socket = params->getSocketServer();
	Serializador * serializador = params->getSerializador();
	ColaEventos * colaIn = params->getCola();
	string desc= params->getDescripcion();
	Logger log;
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
			procesarRequestFunc(fd2, serializador, dispo,colaIn, desc);
		}
	}
	pthread_exit(NULL);
}


RecepcionClientesThread::RecepcionClientesThread(int serverSocket,ColaEventos * colaEntrada, Disponibilidad * d, string descripcion) {
	colaIn = colaEntrada;
	th = NULL;
	dispo = d;
	this->socket = serverSocket;
	params = NULL;
	serializador = new Serializador(-1);
	this->descripcion = descripcion;

}

RecepcionClientesThread::~RecepcionClientesThread() {
	if (th != NULL) {
		deleteAll();
	}
	delete serializador;
}

void RecepcionClientesThread::deleteAll() {
 	delete th;
	delete params;
	th = NULL;
	params = NULL;
}

void RecepcionClientesThread::run() {
	if (th == NULL) {
		params = new RecepcionClientesThreadParams(socket,dispo,colaIn,serializador,descripcion);
		th = new ThreadPTM(recepcionClientesThread, NULL, params);
	}
}

void RecepcionClientesThread::procesarRequest(int socketCliente) {
	if(th== NULL){
		procesarRequestFunc(socketCliente,serializador,dispo,colaIn,descripcion);
	}
}

void RecepcionClientesThread::cancel() {
	if (this->th != NULL) {
		this->th->cancel();
		deleteAll();
	}
}


RecepcionClientesThreadParams::RecepcionClientesThreadParams(int socketServer, Disponibilidad*d, ColaEventos* cola,
		Serializador* ser, string desc) {
	this->socketServer = socketServer;
	this->disponibilidad = d;
	this->cola = cola;
	this->serializador=ser;
	this->descripcion = desc;
}

RecepcionClientesThreadParams::~RecepcionClientesThreadParams() {
}

ColaEventos* RecepcionClientesThreadParams::getCola() {
	return cola;
}

Disponibilidad* RecepcionClientesThreadParams::getDisponibilidad() {
	return disponibilidad;
}

Serializador* RecepcionClientesThreadParams::getSerializador()  {
	return serializador;
}

int RecepcionClientesThreadParams::getSocketServer() {
	return socketServer;
}

string RecepcionClientesThreadParams::getDescripcion() {
	return descripcion;
}
