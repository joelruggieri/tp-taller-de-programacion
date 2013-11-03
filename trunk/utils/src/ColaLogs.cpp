/*
 * ColaLogs.cpp
 *
 *  Created on: 03/11/2013
 *      Author: jonathan
 */

#include "ColaLogs.h"
#include <string>
#include <list>
using namespace std;
namespace LOG {

ColaLogs::ColaLogs() {
	pthread_mutex_init(&(this->mutex), NULL);

}

ColaLogs::~ColaLogs() {
	pthread_mutex_destroy(&(this->mutex));
}

void ColaLogs::lock() {
	pthread_mutex_lock(&(this->mutex));
}

void ColaLogs::unlock() {
	pthread_mutex_unlock(&(this->mutex));
}


void ColaLogs::push(string msj) {
	lock();
	this->buffer.push_back(msj);
	unlock();
}

string ColaLogs::front() {
	lock();
	string retorno = "";
	if(buffer.size() > 0) {
		retorno = buffer.front();
		buffer.remove(retorno);
	}
	unlock();
	return retorno;
}

bool ColaLogs::hasNext() {
	lock();
	bool ret = buffer.size() > 0;
	unlock();
	return ret;
}

} /* namespace LOG */
