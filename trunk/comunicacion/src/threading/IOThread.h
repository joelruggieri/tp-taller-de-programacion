/*
 * IOThread.h
 *
 *  Created on: 01/11/2013
 *      Author: ezequiel
 */

#ifndef IOTHREAD_H_
#define IOTHREAD_H_
#include "ColaEventos.h"
#include "ThreadPTM.h"
#include "../SerializacionException.h"
#include "Status.h"
#include "src/Logger.h"
class IOThreadParams{
private:
	ColaEventos * cola;
	int  socketDesc;
	Status * status;
	int jugador;

public:
	IOThreadParams(ColaEventos * cola,Status * status, int socketDesc, int jugador);
	virtual ~IOThreadParams();
	ColaEventos* getCola();
	int getSocketDesc();
	Status* getStatus();
	int getJugador();
};


class IOThread {
public:
	IOThread(ColaEventos* , ColaEventos* , Status *, int, int );
	virtual ~IOThread();
	void run();
	void cancel();
private:
	Logger log;
	Status * status;
	void deleteAll();
	ThreadPTM* thEntrada;
	ThreadPTM* thSalida;
	ColaEventos* colaEntrada;
	ColaEventos* colaSalida;
	IOThreadParams* param1;
	IOThreadParams* param2;
	int socket;
	int jugador;
};

#endif /* IOTHREAD_H_ */
