/*
 * GeneralEventController.cpp
 *
 *  Created on: 07/09/2013
 *      Author: jonathan
 */

#include "GeneralEventController.h"

#include <iostream>
#include <list>
#include <string>
#include "src/mensajes/userEvents/ClickMsj.h"
#include "src/mensajes/userEvents/MouseMotionMsj.h"
#include "src/mensajes/userEvents/KeyMsj.h"
#include "src/mensajes/userEvents/JugadorListo.h"
#include "userEvents/MouseEvent.h"
#include "userEvents/KeyEvent.h"
#include "src/Logger.h"


GeneralEventController::GeneralEventController() {
	this->drawController = NULL;
//	SDL_SetWindowMaximumSize(this->v
}
GeneralEventController::~GeneralEventController() {
}




void  GeneralEventController::procesarEventos(UserEventMsj* m) {
	m->procesar(this);
}

void GeneralEventController::visit(MouseMotionMsj* m) {
//	MouseEvent mouse (m->getX(),m->getY(),false,false,false,false);
	//ENTREGA3 PASAR AL JUGADOR QUE CORRESPONDA SEGUN EL DESTINATARIO QUE TRAIGA EL MSJ. HACER jugador.mouseMotion(mouse)
}

void GeneralEventController::visit(ClickMsj* m) {
//	MouseEvent mouse(m->getX(), m->getY(),m->isLeft(),m->isDown(),m->isCtrl(),m->isShift());
	//ENTREGA3 PASAR AL JUGADOR QUE CORRESPONDA SEGUN EL DESTINATARIO QUE TRAIGA EL MSJ. HACER jugador.click(mouse)
}

void GeneralEventController::visit(KeyMsj* m) {
//	KeyEvent key (m->getTecla(),m->isPresionada());
	//ENTREGA3 PASAR AL JUGADOR QUE CORRESPONDA SEGUN EL DESTINATARIO QUE TRAIGA EL MSJ. HACER jugador.key(mouse)
}

void GeneralEventController::visit(JugadorListo * m) {
//	ENTREGA3 AVISAR A ALGUIEN QUE EL JUGADOR ESTA LISTO O NO, DEPENDE EL BOOL DEL MENSAJE.
}
