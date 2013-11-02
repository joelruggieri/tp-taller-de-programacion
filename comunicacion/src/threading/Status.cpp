/*
 * ThredStatus.cpp
 *
 *  Created on: 26/10/2013
 *      Author: joel
 */

#include "Status.h"
#include "IOThread.h"
bool Status::isAlive() {
	time_t now;
	time(&now);
	double seconds = difftime(now,puntoControl);
	return seconds < timeout;
}
//
void Status::refresh() {
	time(&puntoControl);
}

void Status::setThread(IOThread * t) {
	this->refresh();
	this->listener= t;
//	this->colaSalida->clear();
}

Status::Status(int timeout) {
	this->timeout = timeout;
	this->listener = 0;
	time(&puntoControl);
}
IOThread* Status::getThread() {
	return this->listener;
}

Status::~Status() {
}
