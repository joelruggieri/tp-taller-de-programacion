/*
 * ViewMsj.cpp
 *
 *  Created on: 02/11/2013
 *      Author: jonathan
 */

#include "ViewMsj.h"

ViewMsj::ViewMsj(int id) {
	this->id = id;
}

ViewMsj::~ViewMsj() {
	// TODO Auto-generated destructor stub
}

void ViewMsj::acept(MensajeVisitor* v) {
	v->visit(this);
}

int ViewMsj::getId() {
	return id;
}
