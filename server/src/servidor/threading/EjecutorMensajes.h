/*
 * EjecutorMensajes.h
 *
 *  Created on: 3/11/2013
 *      Author: jonathan
 */

#ifndef EJECUTORMENSAJES_H_
#define EJECUTORMENSAJES_H_
#include "src/mensajes/userEvents/UserEventVisitor.h"
#include "src/mensajes/MensajeVisitor.h"
#include "src/controller/GeneralEventController.h"
#include "src/mensajes/NetworkMensaje.h"
#include "src/Logger.h"
class EjecutorMensajes: public MensajeVisitor {
private:
	Logger log;
	GeneralEventController *  controller;
public:
	EjecutorMensajes(GeneralEventController *  c);
	virtual ~EjecutorMensajes();
	void consumir(NetworkMensaje *);
	void visit(MouseMotionMsj *);
	void visit(ClickMsj *);
	void visit(KeyMsj *);
	void visit(UserEventMsj *);
	void visit(ViewMsj *);
	void visit(MensajePlano *);
};

#endif /* EJECUTORMENSAJES_H_ */
