/*
 * MouseMotion.cpp
 *
 *  Created on: 3/11/2013
 *      Author: jonathan
 */

#include "MouseMotionMsj.h"

MouseMotionMsj::MouseMotionMsj(float x, float y, bool shift, bool ctrl):UserEventMsj(shift, ctrl) {
	this->x = x;
	this->y = y;
}

MouseMotionMsj::~MouseMotionMsj() {
	// TODO Auto-generated destructor stub
}

void MouseMotionMsj::acept(UserEventVisitor* v) {
		v->visit(this);
}

float MouseMotionMsj::getX() {
	return x;
}

float MouseMotionMsj::getY() {
	return y;
}

void MouseMotionMsj::serialize(YAML::Emitter & out) {
	out << TAG_MOUSE_MOTION;
	out << this->isShift();
	out << this->isCtrl();
	out << this->x;
	out << this->y;
}

NetworkMensaje* MouseMotionMsj::deserialize(YAML::const_iterator& it) {
	bool shift = it->as<bool>();
	it++;
	bool ctrl = it->as<bool>();
	it++;
	float x = it->as<float>();
	it++;
	float y = it->as<float>();
	it++;

	NetworkMensaje * salida = new MouseMotionMsj(x,y,shift,ctrl);
	return salida;
}
