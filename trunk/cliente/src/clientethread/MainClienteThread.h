/*
 * MainClienteThread.h
 *
 *  Created on: 01/11/2013
 *      Author: ezequiel
 */

#ifndef MAINCLIENTETHREAD_H_
#define MAINCLIENTETHREAD_H_
#include "src/threading/ColaEventos.h"
class MainClienteThread {
public:
	MainClienteThread();
	virtual ~MainClienteThread();
	void run();
private:
	ColaEventos* colaEntrada;
	ColaEventos* colaSalida;
};

#endif /* MAINCLIENTETHREAD_H_ */
