/*
 * UserEventMsj.cpp
 *
 *  Created on: 3/11/2013
 *      Author: jonathan
 */

#include "UserEventMsj.h"
#include "../MensajeVisitor.h"
UserEventMsj::UserEventMsj(bool shift, bool ctrl) {
	this->ctrl = ctrl;
	this->shift = shift;
}

UserEventMsj::~UserEventMsj() {
	// TODO Auto-generated destructor stub
}

bool UserEventMsj::isCtrl() const {
	return ctrl;
}

bool UserEventMsj::isShift() const {
	return shift;
}
void UserEventMsj::acept(MensajeVisitor* v) {
	v->visit(this);
}


