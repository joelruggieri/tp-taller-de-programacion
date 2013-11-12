/*
 * DrawController.h
 *
 *  Created on: 04/10/2013
 *      Author: jonathan
 */

#include "DrawController.h"
#include "src/mensajes/viewMensaje/FinDibujado.h"
#include <src/ConstantesComunicacion.h>
#include <src/Logger.h>
DrawController::DrawController(ColaEventos* salida) {
	this->salida = salida;
	tablero = NULL;
	angulo = 0;
	plat = new PlataformaView(10, 10, 20, NULL);
	plat->setModelo(new Plataforma(10, 10, 20, 10));
}

void DrawController::addJugador(JuegoEventsController* c) {
	cout << "agregado " << c->getNumeroJugador() << endl;
	controllers.push_back(c);
}

void DrawController::setTablero(ZonaTablero* t) {
	this->tablero = t;
}

void DrawController::dibujar() {
	Logger log;
//	log.debug("Iniciando dibujado");
	list<ViewMsj*> dumpTablero;
	tablero->dibujarse(dumpTablero);

	list<NetworkMensaje*> salidaFinal;

	list<JuegoEventsController*>::iterator itJugadores;
	list<ViewMsj*>::iterator itDump;
	ViewMsj * nuevo;
	for (itDump = dumpTablero.begin(); itDump != dumpTablero.end(); ++itDump) {
		for (itJugadores = controllers.begin(); itJugadores != controllers.end(); ++itJugadores) {
			//POR CADA JUGADOR PASO EL DUMP A LA SALIDA.
			nuevo = (*itDump)->clone((*itJugadores)->getNumeroJugador());
//			salida->push(nuevo);
			salidaFinal.push_back(nuevo);
		}
		delete (*itDump);
	}
	list<JuegoEventsController*>::iterator itJugadores2;
	ViewMsj*  fin;
	for (itJugadores = controllers.begin(); itJugadores != controllers.end(); ++itJugadores) {
		nuevo = (*itJugadores)->dibujarEdicion();
		if (nuevo != NULL) {
			for (itJugadores2 = controllers.begin(); itJugadores2 != controllers.end(); ++itJugadores2) {
				salidaFinal.push_back(nuevo->clone((*itJugadores2)->getNumeroJugador()));
//				salida->push(nuevo->clone((*itJugadores2)->getNumeroJugador()));
			}
			delete nuevo;
		}
		fin = new FinDibujado();
		fin->setDestinatario((*itJugadores)->getNumeroJugador());
		salidaFinal.push_back(fin);
	}
	salida->push(salidaFinal);
//	log.debug("Finalizando dibujado");
}

DrawController::~DrawController() {

}

void DrawController::removeJugador(JuegoEventsController* c) {
	cout << "removido " << c->getNumeroJugador() << endl;
	controllers.remove(c);
}
