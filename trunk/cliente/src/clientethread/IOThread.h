/*
 * IOThread.h
 *
 *  Created on: 01/11/2013
 *      Author: ezequiel
 */

#ifndef IOTHREAD_H_
#define IOTHREAD_H_
#include "src/threading/ColaEventos.h"
#include "src/threading/ThreadPTM.h"
#include "src/SerializacionException.h"
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
	IOThread(ColaEventos* , ColaEventos* , int );
	virtual ~IOThread();
	void run(Status* status);
private:
	ThreadPTM* thEntrada;
	ThreadPTM* thSalida;
	ColaEventos* colaEntrada;
	ColaEventos* colaSalida;
	IOThreadParams* param1;
	IOThreadParams* param2;
	int socket;
};

#endif /* IOTHREAD_H_ */
