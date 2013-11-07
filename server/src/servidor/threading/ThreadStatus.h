/*
 * ThredStatus.h
 *
 *  Created on: 26/10/2013
 *      Author: joel
 */

#ifndef THREDSTATUS_H_
#define THREDSTATUS_H_
#include <ctime>
#include "Disponibilidad.h"
#include "src/threading/ObjetoCompartido.h"
#include "src/threading/ColaEventos.h"
#include "src/threading/IOThread.h"
#include "src/threading/Status.h"
#include "src/Jugador.h"
using namespace std;
class JugadorThread;

class ThreadStatus: public Status {
private:
	Jugador* jugador;
	//int jugador;
	ColaEventos * colaSalida;
	typedef Status super;
public:
	ThreadStatus(int timeout,Jugador* jugador);
	void setThread(IOThread*);
	int getNroJugador();
	Jugador* getJugador();
	ColaEventos * getColaSalida();
	virtual ~ThreadStatus();
};

#endif /* THREDSTATUS_H_ */
