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
	string descripcion;
public:
	RecepcionClientesThreadParams(int socketServer, Disponibilidad*,ColaEventos * cola, Serializador * ser, string desc);
	virtual ~RecepcionClientesThreadParams();
	ColaEventos* getCola();
	Disponibilidad* getDisponibilidad();
	Serializador* getSerializador();
	int getSocketServer();
	string getDescripcion();
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
	string descripcion;
public:
	void procesarRequest(int socketCliente);
	RecepcionClientesThread(int socket, ColaEventos * colaEntrada, Disponibilidad * d,string descripcion);
	virtual ~RecepcionClientesThread();
	void run();
	void cancel();
};

#endif /* RECEPCIONISTACLIENTESTHREAD_H_ */
