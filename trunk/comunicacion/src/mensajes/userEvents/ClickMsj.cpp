/*
 * ClickDownMsj.cpp
 *
 *  Created on: 3/11/2013
 *      Author: jonathan
 */

#include "ClickMsj.h"

ClickMsj::ClickMsj(float x, float y, bool down, bool left, bool shift, bool ctrl):UserEventMsj(shift, ctrl) {
	this->x = x;
	this->y = y;
	this->down = down;
	this->left = left;
}

ClickMsj::~ClickMsj() {
	// TODO Auto-generated destructor stub
}

void ClickMsj::procesar(UserEventVisitor* v) {
		v->visit(this);
}
