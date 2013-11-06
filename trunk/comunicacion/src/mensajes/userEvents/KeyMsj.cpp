/*
 * KeyMsj.cpp
 *
 *  Created on: 3/11/2013
 *      Author: jonathan
 */

#include "KeyMsj.h"

KeyMsj::KeyMsj(char character, bool pressed, bool shift, bool ctrl):UserEventMsj(shift,ctrl) {
	this->tecla = character;
	this->pressed = pressed;
}

KeyMsj::~KeyMsj() {
	// TODO Auto-generated destructor stub
}

void KeyMsj::acept(UserEventVisitor* v) {
		v->visit(this);
}

bool KeyMsj::isPresionada() const {
	return pressed;
}

char KeyMsj::getTecla() const {
	return tecla;
}
