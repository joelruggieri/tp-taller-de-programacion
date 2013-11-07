/*
 * ViewMsj.cpp
 *
 *  Created on: 02/11/2013
 *      Author: jonathan
 */

#include "ViewMsj.h"

ViewMsj::ViewMsj(int id, char sel) {
	this->id = id;
	this->selector = sel;
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

char ViewMsj::getSelector() {
return this->selector;
}
