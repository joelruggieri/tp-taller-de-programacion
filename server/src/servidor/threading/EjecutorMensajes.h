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

class EjecutorMensajes: public UserEventVisitor, public MensajeVisitor {
public:
	EjecutorMensajes();
	virtual ~EjecutorMensajes();
	void visit(MouseMotionMsj *);
	void visit(ClickMsj *);
	void visit(KeyMsj *);
	void visit(UserEventMsj *);
	void visit(ViewMsj *);
};

#endif /* EJECUTORMENSAJES_H_ */
