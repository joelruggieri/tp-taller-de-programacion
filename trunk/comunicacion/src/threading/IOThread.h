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
//class Status;
class IOThreadParams{
private:
	ColaEventos * cola;
	int  socketDesc;
	Status * status;
public:
	IOThreadParams(ColaEventos * cola,Status * status, int socketDesc);
	virtual ~IOThreadParams();
	ColaEventos* getCola();
	int getSocketDesc();
	Status* getStatus();
};


class IOThread {
public:
	IOThread(ColaEventos* , ColaEventos* , Status *, int );
	virtual ~IOThread();
	void run();
	void cancel();
private:
	Status * status;
	void deleteAll();
	ThreadPTM* thEntrada;
	ThreadPTM* thSalida;
	ColaEventos* colaEntrada;
	ColaEventos* colaSalida;
	IOThreadParams* param1;
	IOThreadParams* param2;
	int socket;
};

#endif /* IOTHREAD_H_ */
