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

ThreadStatus::ThreadStatus(int timeout): puntoControl(chrono::duration<int>(1)){
	this->timeout = timeout;
	this->listener = NULL;
};
bool ThreadStatus::isAlive() {
     int transcurrido = duration_cast<milliseconds>(system_clock::now() - puntoControl).count();
	return transcurrido < this->timeout;
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

