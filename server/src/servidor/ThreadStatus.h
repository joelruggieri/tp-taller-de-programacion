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
using namespace std;
//using namespace chrono;
//
//
//typedef duration<signed int-type >= 64 bits,nano>        nanoseconds;
//typedef duration<signed int-type >= 55 bits,micro>       microseconds;
//typedef duration<signed int-type >= 45 bits,milli>       milliseconds;
//typedef duration<signed int-type >= 35 bits>             seconds;
//typedef duration<signed int-type >= 29 bits,ratio<60>>   minutes;
//typedef duration<signed int-type >= 23 bits,ratio<3600>> hours;
class JugadorThread;

class ThreadStatus {
	chrono::system_clock::time_point puntoControl;
private:
	JugadorThread * listener;
	int timeout;
public:
	ThreadStatus(int timeout);
	void setThread(JugadorThread*);
	bool isAlive();
	void refresh();
	virtual ~ThreadStatus();
};

#endif /* THREDSTATUS_H_ */
