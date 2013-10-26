/*
 * GeneralEventReceptorThread.h
 *
 *  Created on: 26/10/2013
 *      Author: jonathan
 */

#ifndef GENERALEVENTRECEPTORTHREAD_H_
#define GENERALEVENTRECEPTORTHREAD_H_
#include "src/controller/GeneralEventController.h"
class GeneralEventReceptorThread {
public:

	//Este es un thread aparte que tiene que ir levantando de la cola de eventos y pasandoselos al general event controller
	GeneralEventReceptorThread(GeneralEventController *);
	virtual ~GeneralEventReceptorThread();
};

#endif /* GENERALEVENTRECEPTORTHREAD_H_ */
