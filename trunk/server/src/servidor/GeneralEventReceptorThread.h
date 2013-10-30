/*
 * GeneralEventReceptorThread.h
 *
 *  Created on: 26/10/2013
 *      Author: jonathan
 */

#ifndef GENERALEVENTRECEPTORTHREAD_H_
#define GENERALEVENTRECEPTORTHREAD_H_
#include "src/controller/GeneralEventController.h"
#include <thread>
#include "ColaEventos.h"
class GeneralEventReceptorThread {

private:
	thread th;
	ColaEventos * colaIn, * colaOut;
public:

	//Este es un thread aparte que tiene que ir levantando de la colaEntrada de eventos y pasandoselos al general event controller
	GeneralEventReceptorThread(GeneralEventController *, ColaEventos * in, ColaEventos out);
	void run();
	virtual ~GeneralEventReceptorThread();
};

#endif /* GENERALEVENTRECEPTORTHREAD_H_ */
