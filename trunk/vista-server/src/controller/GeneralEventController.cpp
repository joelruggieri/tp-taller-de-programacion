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

GeneralEventController::GeneralEventController(DrawController * dController, FlujoDeJuegoController * fcontroller) {
	flowController = fcontroller;
	this->drawController = dController;
}
GeneralEventController::~GeneralEventController() {
	delete drawController;
	delete flowController;
}

void GeneralEventController::procesarEventos(UserEventMsj* m) {
	m->acept(this);
}

void GeneralEventController::visit(MouseMotionMsj* m) {
	int nroJugador = m->getDestinatario();
	std::map<int, JuegoEventsController *>::iterator jugador = this->controllers.find(nroJugador);
	if (jugador == controllers.end()) {
		string lg = "Jugador no encontrado ";
		log.concatenar(lg, nroJugador);
		log.debug(lg);
	} else {
		MouseEvent mouse(m->getX(), m->getY(), false, false, m->isCtrl(), m->isShift());
		mouse.mouseMotion(jugador->second);
	}
}

void GeneralEventController::visit(ClickMsj* m) {
	int nroJugador = m->getDestinatario();
	string lg = "Se recibe mensaje del destinatario ";
	log.concatenar(lg, nroJugador);
	log.debug(lg);
	std::map<int, JuegoEventsController *>::iterator jugador = this->controllers.find(nroJugador);
	if (jugador == controllers.end()) {
		lg = "Jugador no encontrado ";
		log.concatenar(lg, nroJugador);
		log.debug(lg);
	} else {
		MouseEvent mouse(m->getX(), m->getY(), m->isLeft(), m->isDown(), m->isCtrl(), m->isShift());
		mouse.mouseClick(jugador->second);
	}
}

void GeneralEventController::visit(KeyMsj* m) {
	int nroJugador = m->getDestinatario();

	std::map<int, JuegoEventsController *>::iterator jugador = this->controllers.find(nroJugador);
	if (jugador == controllers.end()) {
		string lg = "Jugador no encontrado ";
		log.concatenar(lg, nroJugador);
		log.debug(lg);
	} else {
		KeyEvent key(m->getTecla(), m->isPresionada());
		key.keyPressed(jugador->second);
	}
}

void GeneralEventController::addJugador(JuegoEventsController* j) {
	this->controllers.insert(pair<int, JuegoEventsController*>(j->getNumeroJugador(), j));
}

void GeneralEventController::visit(JugadorListo * m) {
	std::map<int, JuegoEventsController *>::iterator jugador = this->controllers.find(m->getDestinatario());
	if (jugador == controllers.end() || jugador->second->isEditando()) {
		return;
	}
	flowController->cambiarEstadoJugador(m->getDestinatario(),m->isListo());
}

void GeneralEventController::visit(DrawEvent*) {
	if(this->flowController->isGanado()){
		drawController->pasarAGanado();
	}
	drawController->dibujar();
}

void GeneralEventController::visit(CreacionMsj* m) {
	int nroJugador = m->getDestinatario();
	string lg = "Se recibe mensaje del destinatario ";
	log.concatenar(lg, nroJugador);
	log.debug(lg);
	std::map<int, JuegoEventsController *>::iterator jugador = this->controllers.find(nroJugador);
	if (jugador == controllers.end()) {
		lg = "Jugador no encontrado ";
		log.concatenar(lg, nroJugador);
		log.debug(lg);
	} else {
		if(!jugador->second->isEditando()){
			jugador->second->crearVista(m->getTagObjeto(), m->getX(), m->getY());
		}
	}
}

void GeneralEventController::visit(ConexionUsuario* c) {
	map<int,JuegoEventsController*>::iterator it = controllers.find(c->getDestinatario());
	JuegoEventsController * j = (*it).second;
	if(c->isConectado()){
		drawController->addJugador(j);
	} else {
		drawController->removeJugador(j);
	}
}

void GeneralEventController::visit(StepModelo*) {
	flowController->paso();
}
