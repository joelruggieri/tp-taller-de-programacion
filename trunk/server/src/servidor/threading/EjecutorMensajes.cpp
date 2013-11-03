/*
 * EjecutorMensajes.cpp
 *
 *  Created on: 3/11/2013
 *      Author: jonathan
 */

#include "EjecutorMensajes.h"
#include "src/mensajes/userEvents/MouseMotionMsj.h"
#include "src/mensajes/userEvents/ClickMsj.h"
#include "src/mensajes/userEvents/KeyMsj.h"
#include "src/mensajes/userEvents/UserEventMsj.h"
#include "src/mensajes/viewMensaje/ViewMsj.h"
#include "src/mensajes/MensajePlano.h"

EjecutorMensajes::EjecutorMensajes(GeneralEventController *  c) {
	this->controller = c;
}

EjecutorMensajes::~EjecutorMensajes() {
	// TODO Auto-generated destructor stub
}

void EjecutorMensajes::visit(MouseMotionMsj*) {
	log.debug("Se recibe en receptor un mouse motion");
}

void EjecutorMensajes::visit(ClickMsj*) {
	log.debug("Se recibe en receptor un clickMsj");
}

void EjecutorMensajes::visit(KeyMsj*) {
	log.debug("Se recibe en receptor un keymsj");
}

void EjecutorMensajes::visit(UserEventMsj* m) {
	log.debug("Se recibe en receptor un userevent");
	m->procesar(this);
}

void EjecutorMensajes::consumir(NetworkMensaje* m) {
	m->acept(this);
	delete m;
}

void EjecutorMensajes::visit(ViewMsj*) {
}

void EjecutorMensajes::visit(MensajePlano*m ) {
	log.debug("Se recibe mensaje plano" + m->getMensaje());
}
