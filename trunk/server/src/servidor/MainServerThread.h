/*
 * MainServerThread.h
 *
 *  Created on: 26/10/2013
 *      Author: jonathan
 */

#ifndef MAINSERVERTHREAD_H_
#define MAINSERVERTHREAD_H_

#include "src/Nivel.h"
#include "src/Logger.h"
#include "src/ManejadorErrores.h"
//Este thread se encarga de esperar la primer conexion para generar una partida.
//Una vez que genera una partida pasa al control de la partida.
class MainServerThread {
private:
	Nivel *n;
	Logger log;
public:
	MainServerThread(const char* nivel);
	void run();
	virtual ~MainServerThread();
};

#endif /* MAINSERVERTHREAD_H_ */
