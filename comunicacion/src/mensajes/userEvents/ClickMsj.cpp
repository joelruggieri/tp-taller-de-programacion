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

void ClickMsj::acept(UserEventVisitor* v) {
		v->visit(this);
}

bool ClickMsj::isDown() const {
	return down;
}

bool ClickMsj::isLeft() const {
	return left;
}

float ClickMsj::getX() const {
	return x;
}

float ClickMsj::getY() const {
	return y;
}
