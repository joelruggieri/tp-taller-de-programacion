/*
 * ClienteThread.h
 *
 *  Created on: 30/10/2013
 *      Author: jonathan
 */

#ifndef CLIENTETHREAD_H_
#define CLIENTETHREAD_H_
#include "src/threading/ColaEventos.h"
#include "Status.h"
#include "thread"
class ClienteThread {
private:
	ColaEventos * in, * out;
	Status * status;
	thread * thEntrada;
	thread  * thSalida;
	int socket;
public:
	ClienteThread(ColaEventos * in, ColaEventos * out, Status * status, int socketId);
	virtual ~ClienteThread();
	void run();

};

#endif /* CLIENTETHREAD_H_ */
