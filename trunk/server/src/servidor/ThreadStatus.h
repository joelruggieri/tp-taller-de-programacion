/*
 * ThredStatus.h
 *
 *  Created on: 26/10/2013
 *      Author: joel
 */

#ifndef THREDSTATUS_H_
#define THREDSTATUS_H_
#include <chrono>
#include "Disponibilidad.h"
using namespace std;
class JugadorThread;

class ThreadStatus {
	chrono::system_clock::time_point puntoControl;
private:
	JugadorThread * listener;
	int timeout, jugador;
public:
	ThreadStatus(int timeout, int nro);
	void setThread(JugadorThread*);
	bool isAlive();
	void refresh();
	int getNroJugador();
	JugadorThread * getThread();
	virtual ~ThreadStatus();
};

#endif /* THREDSTATUS_H_ */
