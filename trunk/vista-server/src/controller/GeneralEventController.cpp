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
	int nroJugador = m->getDestinatario();
	MouseEvent mouse (m->getX(),m->getY(),false,false,m->isCtrl(),m->isShift());
	JuegoEventsController* jugador = this->controllers[nroJugador];
	mouse.mouseMotion(jugador);
//	jugador->mouseMotion()
}

void GeneralEventController::visit(ClickMsj* m) {
	int nroJugador = m->getDestinatario();
	MouseEvent mouse (m->getX(),m->getY(),m->isLeft(),m->isDown(),m->isCtrl(),m->isShift());
	JuegoEventsController* jugador = this->controllers[nroJugador];
		mouse.mouseClick(jugador);
//	MouseEvent mouse(m->getX(), m->getY(),m->isLeft(),m->isDown(),m->isCtrl(),m->isShift());
	//ENTREGA3 PASAR AL JUGADOR QUE CORRESPONDA SEGUN EL DESTINATARIO QUE TRAIGA EL MSJ. HACER jugador.click(mouse)
}

void GeneralEventController::visit(KeyMsj* m) {
	int nroJugador = m->getDestinatario();
	JuegoEventsController* jugador = this->controllers[nroJugador];
	KeyEvent key (m->getTecla(), m->isPresionada());
	key.keyPressed(jugador);

//	KeyEvent key (m->getTecla(),m->isPresionada());
	//ENTREGA3 PASAR AL JUGADOR QUE CORRESPONDA SEGUN EL DESTINATARIO QUE TRAIGA EL MSJ. HACER jugador.key(mouse)
}

void GeneralEventController::addJugador(JuegoEventsController* j) {
	this->controllers.insert(pair <int, JuegoEventsController*>(j->getNumeroJugador(), j));
}

void GeneralEventController::visit(JugadorListo * m) {
	bool listo = m->isListo();

//	ENTREGA3 AVISAR A ALGUIEN QUE EL JUGADOR ESTA LISTO O NO, DEPENDE EL BOOL DEL MENSAJE.
}
