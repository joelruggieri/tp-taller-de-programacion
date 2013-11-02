/*
 * MainClienteThread.h
 *
 *  Created on: 01/11/2013
 *      Author: ezequiel
 */

#ifndef MAINCLIENTETHREAD_H_
#define MAINCLIENTETHREAD_H_
#include "src/threading/ColaEventos.h"
#include "src/threading/IOThread.h"
#include <sys/socket.h>
#include <string>
#include "src/Logger.h"
using namespace std;

enum RESULTADO_CONEXION {SERVIDOR_ERROR, SERVIDOR_OCUPADO, SERVIDOR_CONECTADO};

class MainClienteThread {
public:
	MainClienteThread();
	virtual ~MainClienteThread();
	void run();
private:
	IOThread * thread;
	Logger log;
	ColaEventos* colaEntrada;
	RESULTADO_CONEXION conectar(int &socket);
	string tryConnect(int &socketfd);
	ColaEventos* colaSalida;
};

#endif /* MAINCLIENTETHREAD_H_ */
