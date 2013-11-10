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
	list<ViewMsj*> dumpTablero;
	tablero->dibujarse(dumpTablero);

	list<NetworkMensaje*> salidaFinal;

	list<JuegoEventsController*>::iterator itJugadores;
	list<ViewMsj*>::iterator itDump;
	ViewMsj * nuevo;
	for (itDump = dumpTablero.begin(); itDump != dumpTablero.end(); ++itDump) {
		for (itJugadores = jugadores.begin(); itJugadores != jugadores.end(); ++itJugadores) {
			//POR CADA JUGADOR PASO EL DUMP A LA SALIDA.
			nuevo = (*itDump)->clone((*itJugadores)->getNumeroJugador());
			salidaFinal.push_back(nuevo);
		}
		delete (*itDump);
	}
	list<JuegoEventsController*>::iterator itJugadores2;
	for (itJugadores = jugadores.begin(); itJugadores != jugadores.end(); ++itJugadores) {
		nuevo = (*itJugadores)->dibujarEdicion();
		if (nuevo != NULL) {
			for (itJugadores2 = jugadores.begin(); itJugadores2 != jugadores.end(); ++itJugadores2) {
				salidaFinal.push_back(nuevo->clone((*itJugadores2)->getNumeroJugador()));
			}
			delete nuevo;
		}
	}
	salida->push(salidaFinal);
}

DrawController::~DrawController() {

}

