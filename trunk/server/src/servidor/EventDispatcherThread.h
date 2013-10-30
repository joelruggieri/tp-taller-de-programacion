/*
 * EventDispatcherThread.h
 *
 *  Created on: 29/10/2013
 *      Author: jonathan
 */

#ifndef EVENTDISPATCHERTHREAD_H_
#define EVENTDISPATCHERTHREAD_H_
#include "Disponibilidad.h"
#include "ColaEventos.h"
#include "src/Logger.h"
#include "thread"
//
class EventDispatcherThread {
private:
	Disponibilidad * disponibilidad;
	ColaEventos * cola;
	thread * th;
	Logger log;
public:
	EventDispatcherThread(ColaEventos * colaSalida, Disponibilidad * dispo);
	virtual ~EventDispatcherThread();
	void run();
};

#endif /* EVENTDISPATCHERTHREAD_H_ */
