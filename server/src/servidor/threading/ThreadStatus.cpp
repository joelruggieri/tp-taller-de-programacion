/*
 * ThredStatus.cpp
 *
 *  Created on: 26/10/2013
 *      Author: joel
 */

#include "ThreadStatus.h"
//#include <ratio>
using namespace std;
//using namespace chrono;
#include "JugadorThread.h"
ThreadStatus::ThreadStatus(int timeout, int nro){// :puntoControl(chrono::duration<int>(1)){
	this->timeout = timeout;
	this->listener = NULL;
	this->jugador = nro;
	this->socketDesc = 0;
	this->colaSalida=new ColaEventos();
	time(&puntoControl);
};
bool ThreadStatus::isAlive() {
	time_t now;
	time(&now);
	double seconds = difftime(now,puntoControl);
	return seconds < timeout;
}

void ThreadStatus::refresh() {
	time(&puntoControl);
}

//NO SEAS HIJO DE PUTA Y A T PONELE EL NRO DE JUGADOR QUE TIENE EL STATUS.
void ThreadStatus::setThread(JugadorThread* t) {
	this->refresh();
	//ENTREGA3 REVISAR, PERO VOY A HACER CLEAN DE LA COLA CUANDO ME SETEAN UN THREAD NUEVO, ASI NO LE LLEGA INFO VIEJA
	this->colaSalida->clear();
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

void ThreadStatus::setSocketDesc(int desc) {
	this->socketDesc = desc;
}

int ThreadStatus::getSockedDesc() {
	return socketDesc;
}

ColaEventos* ThreadStatus::getColaSalida() {
	return this->colaSalida;
}
