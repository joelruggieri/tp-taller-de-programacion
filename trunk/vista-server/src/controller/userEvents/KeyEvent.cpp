/*
 * KeyEvent.cpp
 *
 *  Created on: 04/11/2013
 *      Author: jonathan
 */

#include "KeyEvent.h"

KeyEvent::KeyEvent(char t, bool pressed) {
	this->tecla = t;
	this->presionada= pressed;
}

char KeyEvent::getTecla() const {
	return tecla;
}

KeyEvent::~KeyEvent() {
	// TODO Auto-generated destructor stub
}

bool KeyEvent::isPresionada() const {
	return presionada;
}

void KeyEvent::keyPressed(JuegoEventsController* j) {
//	if (this->presionada()) j->
	//No hay presion de tecla por ahora para tomar
}
