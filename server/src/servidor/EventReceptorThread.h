/*
 * EventReceptorThread.h
 *
 *  Created on: 26/10/2013
 *      Author: jonathan
 */

#ifndef EVENTRECEPTORTHREAD_H_
#define EVENTRECEPTORTHREAD_H_
#include "src/controller/GeneralEventController.h"
#include <thread>
#include "src/threading/ColaEventos.h"
class EventReceptorThread {

private:
	thread * th;
	ColaEventos * colaIn, * colaOut;
public:

	//Este es un thread aparte que tiene que ir levantando de la colaEntrada de eventos y pasandoselos al general event controller
	EventReceptorThread(GeneralEventController *, ColaEventos * in, ColaEventos * out);
	void run();
	virtual ~EventReceptorThread();
};

#endif /* EVENTRECEPTORTHREAD_H_ */
