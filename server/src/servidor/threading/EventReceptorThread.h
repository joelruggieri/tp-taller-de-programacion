/*
 * EventReceptorThread.h
 *
 *  Created on: 26/10/2013
 *      Author: jonathan
 */

#ifndef EVENTRECEPTORTHREAD_H_
#define EVENTRECEPTORTHREAD_H_
#include "src/controller/GeneralEventController.h"
//#include <thread>
#include "src/threading/ColaEventos.h"
#include "src/threading/ThreadPTM.h"

class EventReceptorThreadParams {
private:
	ColaEventos * colaIn;
	GeneralEventController * controller;
public:
	EventReceptorThreadParams(GeneralEventController * c, ColaEventos * cola);
	virtual ~EventReceptorThreadParams();
	ColaEventos* getColaIn();
	GeneralEventController* getController();
};

class EventReceptorThread {

private:
	ThreadPTM * th;
	ColaEventos * colaIn, *colaOut;
	GeneralEventController * controller;
	EventReceptorThreadParams * params;
	void clearAll();
public:

	//Este es un thread aparte que tiene que ir levantando de la colaEntrada de eventos y pasandoselos al general event controller
	EventReceptorThread(GeneralEventController *, ColaEventos * in, ColaEventos * out);
	void run();
	void cancel();
	virtual ~EventReceptorThread();
};

#endif /* EVENTRECEPTORTHREAD_H_ */

