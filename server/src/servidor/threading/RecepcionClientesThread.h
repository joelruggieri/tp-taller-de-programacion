/*
 * RecepcionClientesThread.h
 *
 *  Created on: 07/11/2013
 *      Author: jonathan
 */

#ifndef RECEPCIONISTACLIENTESTHREAD_H_
#define RECEPCIONISTACLIENTESTHREAD_H_
#include "src/threading/ColaEventos.h"
#include "src/threading/ThreadPTM.h"
#include "Disponibilidad.h"
#include <src/Serializador.h>

class RecepcionClientesThreadParams {
private:
	ColaEventos * cola;
	int socketServer;
	Disponibilidad * disponibilidad;
	Serializador * serializador;
public:
	RecepcionClientesThreadParams(int socketServer, Disponibilidad*,ColaEventos * cola, Serializador * ser);
	virtual ~RecepcionClientesThreadParams();
	ColaEventos* getCola();
	Disponibilidad* getDisponibilidad();
	Serializador* getSerializador();
	int getSocketServer();
};


class RecepcionClientesThread {
private:
	ColaEventos * colaIn;
	Disponibilidad * dispo;
	ThreadPTM * th;
	int socket;
	Serializador * serializador;
	void deleteAll();
	RecepcionClientesThreadParams * params;
public:
	void procesarRequest(int socketCliente);
	RecepcionClientesThread(int socket, ColaEventos * colaEntrada, Disponibilidad * d);
	virtual ~RecepcionClientesThread();
	void run();
	void cancel();
};

#endif /* RECEPCIONISTACLIENTESTHREAD_H_ */
