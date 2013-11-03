/*
 * KeyMsj.cpp
 *
 *  Created on: 3/11/2013
 *      Author: jonathan
 */

#include "KeyMsj.h"

KeyMsj::KeyMsj(char character, bool pressed, bool shift, bool ctrl):UserEventMsj(shift,ctrl) {
	this->chara = character;
	this->pressed = pressed;
}

KeyMsj::~KeyMsj() {
	// TODO Auto-generated destructor stub
}

void KeyMsj::procesar(UserEventVisitor* v) {
		v->visit(this);
}
