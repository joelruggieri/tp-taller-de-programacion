/*
 * MainServerThread.h
 *
 *  Created on: 26/10/2013
 *      Author: jonathan
 */

#ifndef MAINSERVERTHREAD_H_
#define MAINSERVERTHREAD_H_



//Este thread se encarga de esperar la primer conexion para generar una partida.
//Una vez que genera una partida pasa al control de la partida.
class MainServerThread {
public:
	MainServerThread();
	virtual ~MainServerThread();
};

#endif /* MAINSERVERTHREAD_H_ */
