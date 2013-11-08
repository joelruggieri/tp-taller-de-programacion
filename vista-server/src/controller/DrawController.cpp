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
}

void DrawController::addJugador(JuegoEventsController*) {
}

void DrawController::setTablero(ZonaTablero* t) {
	this->tablero = t;
}

void DrawController::dibujar() {
	ViewObjetoUpdateMsj * msje = new ViewObjetoUpdateMsj(50,50,0,101,OBJ_SIMPLE_S_BALANCIN);
	msje->setDestinatario(0);
	salida->push(msje);

}

DrawController::~DrawController(){

}
