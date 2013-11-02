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
ThreadStatus::ThreadStatus(int timeout, int nro):Status(timeout){// :puntoControl(chrono::duration<int>(1)){
	this->jugador = nro;
	this->colaSalida=new ColaEventos();
};

void ThreadStatus::setThread(IOThread* t) {
	super::setThread(t);
	//ENTREGA3 REVISAR, PERO VOY A HACER CLEAN DE LA COLA CUANDO ME SETEAN UN THREAD NUEVO, ASI NO LE LLEGA INFO VIEJA
	this->colaSalida->clear();
}

ThreadStatus::~ThreadStatus() {
	// TODO Auto-generated destructor stub
}

int ThreadStatus::getNroJugador() {
	return jugador;
}

ColaEventos* ThreadStatus::getColaSalida() {
	return this->colaSalida;
}
