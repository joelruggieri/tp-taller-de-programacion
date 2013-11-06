/*
 * ViewController.cpp
 *
 *  Created on: 04/11/2013
 *      Author: jonathan
 */

#include "ViewController.h"


namespace CLIENTE {

ViewController::ViewController(ColaEventos* colaSalida) {
	this->salida = salida;

}

void ViewController::receiveEvent(ViewMsj*) {
	lock();
	//ENTREGA3 TIENE QUE RECIBIR EL MENSAJE, TOMAR EL ID OBTENER LA VIEW Y DARLE UPDATE
	//SI NO EXISTE LA VISTA TIENE QUE CREARLA EN LA POSICION QUE DIGA EL MENSAJE.
	unlock();
}

void ViewController::sendEvent(UserEventMsj* m) {
	salida->push(m);
}

void ViewController::addView(int id, View* v) {
	lock();
	vistas.insert(pair<int,View *> (id,v));
	unlock();
}

void ViewController::dibujarse(SDL_Renderer*) {
	lock();
	unlock();
}

ViewController::~ViewController() {
	// TODO Auto-generated destructor stub
}

}
