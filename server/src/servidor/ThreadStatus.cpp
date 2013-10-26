/*
 * ThredStatus.cpp
 *
 *  Created on: 26/10/2013
 *      Author: joel
 */

#include "ThreadStatus.h"
using namespace std;
using namespace chrono;

ThreadStatus::ThreadStatus(int timeout): puntoControl(chrono::duration<int>(1)){
	this->timeout = timeout;
	this->listener = NULL;
};
bool ThreadStatus::isAlive() {
//	chrono::duration<int,std::milli> transcurrido = system_clock::now() - puntoControl ;
//	return transcurrido.count() < this->timeout;
	return false;
}

void ThreadStatus::refresh() {
	puntoControl = system_clock::now();
}

void ThreadStatus::setThread(JugadorThread* t) {
	this->refresh();
	this->listener= t;
}

ThreadStatus::~ThreadStatus() {
	// TODO Auto-generated destructor stub
}

