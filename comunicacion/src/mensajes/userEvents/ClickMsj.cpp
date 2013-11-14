/*
 * ClickDownMsj.cpp
 *
 *  Created on: 3/11/2013
 *      Author: jonathan
 */

#include "ClickMsj.h"
#include "../../ConstantesComunicacion.h"
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

void ClickMsj::serialize(YAML::Emitter & out) {
		out << TAG_CLICK;
		out << this->isShift();
		out << this->isCtrl();
		out << this->isLeft();
		out << this->isDown();
		out << this->x;
		out << this->y;
}

NetworkMensaje* ClickMsj::deserialize(YAML::const_iterator& it) {
	bool shift = it->as<bool>();
	it++;
	bool ctrl = it->as<bool>();
	it++;
	bool left = it->as<bool>();
	it++;
	bool down = it->as<bool>();
	it++;
	float x = it->as<float>();
	it++;
	float y = it->as<float>();
	it++;

	NetworkMensaje * salida = new ClickMsj(x,y,down,left,shift,ctrl);
	return salida;
}
