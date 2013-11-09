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


GeneralEventController::GeneralEventController(DrawController * dController) {
	this->drawController = dController;
}
GeneralEventController::~GeneralEventController() {
	delete drawController;
}




void  GeneralEventController::procesarEventos(UserEventMsj* m) {
	m->acept(this);
}

void GeneralEventController::visit(MouseMotionMsj* m) {
	int nroJugador = m->getDestinatario();
	std::map<int, JuegoEventsController *>::iterator jugador = this->controllers.find(nroJugador);
	if(jugador == controllers.end()){
		string lg = "Jugador no encontrado ";
		log.concatenar(lg, nroJugador);
		log.debug(lg);
	} else {
		MouseEvent mouse (m->getX(),m->getY(),false,false,m->isCtrl(),m->isShift());
		mouse.mouseMotion(jugador->second);
	}
}

void GeneralEventController::visit(ClickMsj* m) {
	int nroJugador = m->getDestinatario();
	string lg = "Se recibe mensaje del destinatario ";
	log.concatenar(lg, nroJugador);
	log.debug(lg);
	std::map<int, JuegoEventsController *>::iterator jugador = this->controllers.find(nroJugador);
	if(jugador == controllers.end()){
		lg = "Jugador no encontrado ";
		log.concatenar(lg, nroJugador);
//		log.concatenar(lg, m->getX());
//		log.concatenar(lg,m->getY());
		log.debug(lg);
	} else {
		MouseEvent mouse (m->getX(),m->getY(),m->isLeft(),m->isDown(),m->isCtrl(),m->isShift());
		mouse.mouseClick(jugador->second);
	}
//	MouseEvent mouse(m->getX(), m->getY(),m->isLeft(),m->isDown(),m->isCtrl(),m->isShift());
	//ENTREGA3 PASAR AL JUGADOR QUE CORRESPONDA SEGUN EL DESTINATARIO QUE TRAIGA EL MSJ. HACER jugador.click(mouse)
}

void GeneralEventController::visit(KeyMsj* m) {
	int nroJugador = m->getDestinatario();

	std::map<int, JuegoEventsController *>::iterator jugador = this->controllers.find(nroJugador);
	if(jugador == controllers.end()){
		string lg = "Jugador no encontrado ";
		log.concatenar(lg, nroJugador);
		log.debug(lg);
	} else {
		KeyEvent key (m->getTecla(), m->isPresionada());
		key.keyPressed(jugador->second);
	}
	//ENTREGA3 PASAR AL JUGADOR QUE CORRESPONDA SEGUN EL DESTINATARIO QUE TRAIGA EL MSJ. HACER jugador.key(mouse)
}

void GeneralEventController::addJugador(JuegoEventsController* j) {
	this->controllers.insert(pair <int, JuegoEventsController*>(j->getNumeroJugador(), j));
}

void GeneralEventController::visit(JugadorListo * m) {
//	bool listo = m->isListo();

//	ENTREGA3 AVISAR A ALGUIEN QUE EL JUGADOR ESTA LISTO O NO, DEPENDE EL BOOL DEL MENSAJE.
}

void GeneralEventController::visit(DrawEvent*) {
 drawController->dibujar();
}

void GeneralEventController::visit(CreacionMsj* m) {
	int nroJugador = m->getDestinatario();
		string lg = "Se recibe mensaje del destinatario ";
		log.concatenar(lg, nroJugador);
		log.debug(lg);
		std::map<int, JuegoEventsController *>::iterator jugador = this->controllers.find(nroJugador);
		if(jugador == controllers.end()){
			lg = "Jugador no encontrado ";
			log.concatenar(lg, nroJugador);
	//		log.concatenar(lg, m->getX());
	//		log.concatenar(lg,m->getY());
			log.debug(lg);
		} else {
			jugador->second->crearVista(m->getTagObjeto(), m->getX(), m->getY());
		}
}
