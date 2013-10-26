/*
 * ThredStatus.cpp
 *
 *  Created on: 26/10/2013
 *      Author: joel
 */

#include "ThreadStatus.h"
#include <ratio>
using namespace std;
using namespace chrono;
#include "JugadorThread.h"
ThreadStatus::ThreadStatus(int timeout, int nro): puntoControl(chrono::duration<int>(1)){
	this->timeout = timeout;
	this->listener = NULL;
	this->jugador = nro;
};
bool ThreadStatus::isAlive() {
     int transcurrido = duration_cast<milliseconds>(system_clock::now() - puntoControl).count();
	return transcurrido < this->timeout;
}

void ThreadStatus::refresh() {
	puntoControl = system_clock::now();
}

//NO SEAS HIJO DE PUTA Y A T PONELE EL NRO DE JUGADOR QUE TIENE EL STATUS.
void ThreadStatus::setThread(JugadorThread* t) {
	this->refresh();
	this->listener= t;
}

ThreadStatus::~ThreadStatus() {
	// TODO Auto-generated destructor stub
}

JugadorThread* ThreadStatus::getThread() {
	return this->listener;
}

int ThreadStatus::getNroJugador() {
	return jugador;
}
