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
#include "src/threading/ObjetoCompartido.h"
#include "src/threading/ColaEventos.h"
using namespace std;
class JugadorThread;

class ThreadStatus: public ObjetoCompartido {
	chrono::system_clock::time_point puntoControl;
private:
	JugadorThread * listener;
	int timeout, jugador, socketDesc;
	ColaEventos * colaSalida;
public:
	ThreadStatus(int timeout, int nro);
	void setThread(JugadorThread*);
	void setSocketDesc(int desc);
	bool isAlive();
	void refresh();
	int getNroJugador();
	int getSockedDesc();
	ColaEventos * getColaSalida();
	JugadorThread * getThread();
	virtual ~ThreadStatus();
};

#endif /* THREDSTATUS_H_ */
