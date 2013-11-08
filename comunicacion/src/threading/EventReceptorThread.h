/*
 * EventReceptorThread.h
 *
 *  Created on: 26/10/2013
 *      Author: jonathan
 */

#ifndef EVENTRECEPTORTHREAD_H_
#define EVENTRECEPTORTHREAD_H_
#include "../mensajes/DistribuidorMensajes.h"
#include "../mensajes/userEvents/UserEventVisitor.h"
#include "../mensajes/viewMensaje/ViewMsjVisitor.h"
#include "../mensajes/MensajePlanoVisitor.h"
#include "../mensajes/internos/MensajeInternoVisitor.h"
#include "ColaEventos.h"
#include "ThreadPTM.h"
class EventReceptorThreadParams {
private:
	ColaEventos * colaIn;
	DistribuidorMensajes * distribuidor;
public:
	EventReceptorThreadParams(DistribuidorMensajes * c, ColaEventos * cola);
	virtual ~EventReceptorThreadParams();
	ColaEventos* getColaIn();
	DistribuidorMensajes * getDistribuidor();
};

class EventReceptorThread {

private:
	ThreadPTM * th;
	ColaEventos * colaIn;
	EventReceptorThreadParams * params;
	DistribuidorMensajes * distribuidor;
	void clearAll();
public:

	//Este es un thread aparte que tiene que ir levantando de la colaEntrada de eventos y pasandoselos al general event controller
	EventReceptorThread(ColaEventos *, UserEventVisitor*, ViewMsjVisitor *, MensajePlanoVisitor *, MensajeInternoVisitor* );
	void run();
	void cancel();
	virtual ~EventReceptorThread();
};

#endif /* EVENTRECEPTORTHREAD_H_ */

