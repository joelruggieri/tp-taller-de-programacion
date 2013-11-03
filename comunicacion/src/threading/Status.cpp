/*
 * ThredStatus.cpp
 *
 *  Created on: 26/10/2013
 *      Author: joel
 */

#include "Status.h"
#include "IOThread.h"
#include <iostream>
using namespace std;

bool Status::isAlive() {
	time_t now;
	time(&now);
	double seconds = difftime(now,puntoControl);
	return (seconds < timeout) && vivo;
}
//
void Status::refresh() {
	lock();
	time(&puntoControl);
	unlock();
}

void Status::setThread(IOThread * t) {
	time(&puntoControl);
	this->listener= t;
	vivo = true;
}
Status::Status(int timeout) {
	this->timeout = timeout;
	this->listener = 0;
	time(&puntoControl);
	vivo = true;
}
IOThread* Status::getThread() {
	return this->listener;
}

Status::~Status() {
}

void Status::kill() {
	lock();
	vivo = false;
	unlock();
}

void Status::clean() {
	lock();
	if(this->getThread() && !isAlive()){
		log.debug("Thread liberado por dejar de estar vivo");
		getThread()->cancel();
		delete getThread();
		setThread(NULL);
	}
	unlock();
}

bool Status::allowClient() {
	if(this->getThread()){
		return false;
	}
	return true;
}
