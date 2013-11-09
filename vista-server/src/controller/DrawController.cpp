/*
 * DrawController.h
 *
 *  Created on: 04/10/2013
 *      Author: jonathan
 */

#include "DrawController.h"
#include "src/mensajes/viewMensaje/ViewObjetoUpdateMsj.h"
#include <src/ConstantesComunicacion.h>
DrawController::DrawController(ColaEventos* salida) {
	this->salida = salida;
	tablero = NULL;
	angulo = 0;
}

void DrawController::addJugador(JuegoEventsController*) {
}

void DrawController::setTablero(ZonaTablero* t) {
	this->tablero = t;
}

void DrawController::dibujar(list<JuegoEventsController*>& jugadores) {
	JuegoEventsController* front = jugadores.front();
	list<ViewMsj*> msjs;
	list<ViewMsj*> msjs2;
	front->dibujarse(msjs);
	front->dibujarse(msjs2);
	tablero->dibujarse(msjs);
	tablero->dibujarse(msjs2);
	list<ViewMsj*>::iterator it;
	list<NetworkMensaje*>nwm;
	if (msjs.size() > 0) {
		for(it=msjs.begin() ; it != msjs.end(); ++it){
			(*it)->setDestinatario(0);
			nwm.push_back(*it);
		}
		for(it=msjs2.begin() ; it != msjs2.end(); ++it){
			(*it)->setDestinatario(1);
			nwm.push_back(*it);
		}

		salida->push(nwm);
	}

}

DrawController::~DrawController() {

}

