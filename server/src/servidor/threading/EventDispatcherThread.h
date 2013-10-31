/*
 * EventDispatcherThread.h
 *
 *  Created on: 29/10/2013
 *      Author: jonathan
 */

#ifndef EVENTDISPATCHERTHREAD_H_
#define EVENTDISPATCHERTHREAD_H_
#include "Disponibilidad.h"
#include "src/threading/ColaEventos.h"
#include "src/threading/ThreadPTM.h"
#include "src/Logger.h"

class EventDispatcherThreadParams {
private:
	ColaEventos * cola;
	Disponibilidad * dispo;
public:
	EventDispatcherThreadParams(ColaEventos * cola, Disponibilidad * disponibilidad);
	virtual ~EventDispatcherThreadParams();
	ColaEventos* getCola();
	Disponibilidad* getDispo();
};

class EventDispatcherThread {
private:
	EventDispatcherThreadParams * params;
	ThreadPTM * th;
	Logger log;
	void cleanAll();
public:
	EventDispatcherThread(ColaEventos * colaSalida, Disponibilidad * dispo);
	virtual ~EventDispatcherThread();
	void run();
	void cancel();

};

#endif /* EVENTDISPATCHERTHREAD_H_ */
