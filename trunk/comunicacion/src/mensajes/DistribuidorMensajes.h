/*
 * DistribuidorMensajes.h
 *
 *  Created on: 5/11/2013
 *      Author: jonathan
 */

#ifndef DISTRIBUIDORMENSAJES_H_
#define DISTRIBUIDORMENSAJES_H_
#include "userEvents/UserEventVisitor.h"
#include "viewMensaje/ViewMsjVisitor.h"
#include "MensajePlanoVisitor.h"
#include "MensajeVisitor.h"
#include "internos/MensajeInternoVisitor.h"
#include "NetworkMensaje.h"
#include "src/Logger.h"

//Esta clase es un dispatcher de los mensajes por tipo.
//Despues ed despacharlo lo destruye.
class DistribuidorMensajes: public MensajeVisitor {
private:
	Logger log;
	UserEventVisitor * user;
	ViewMsjVisitor * views;
	MensajePlanoVisitor * planos;
	MensajeInternoVisitor * internos;
public:
	DistribuidorMensajes(UserEventVisitor*, ViewMsjVisitor *, MensajePlanoVisitor *,MensajeInternoVisitor *  );
	void procesar(NetworkMensaje * msj);
	virtual ~DistribuidorMensajes();
	void visit(UserEventMsj *);
	void visit(ViewMsj *);
	void visit(MensajePlano *);
	void visit(MensajeInterno *);
};

#endif /* DISTRIBUIDORMENSAJES_H_ */

