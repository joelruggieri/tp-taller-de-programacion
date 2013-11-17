/*
 * ViewBotonStartMsj.cpp
 *
 *  Created on: 13/11/2013
 *      Author: jonathan
 */

#include "ViewBotonStartMsj.h"


ViewBotonStartMsj::ViewBotonStartMsj(int id, bool listo): ViewMsj(id, 'a'){
	this->listo = listo;
}

ViewBotonStartMsj::~ViewBotonStartMsj() {
	// TODO Auto-generated destructor stub
}

void ViewBotonStartMsj::acept(ViewMsjVisitor*v) {
	v->visit(this);
}

void ViewBotonStartMsj::serialize(YAML::Emitter & out) {
	out <<TAG_BOTON_LISTO;
	out <<this->id;
	out <<this->listo;
}

NetworkMensaje* ViewBotonStartMsj::deserialize(YAML::const_iterator& it) {
	int id = it->as<int>();
	it++;
	bool listo = it->as<bool>();
	it++;
	return new ViewBotonStartMsj(id,listo);
}

ViewMsj* ViewBotonStartMsj::clone(int destinatario) {
	ViewMsj * m = new ViewBotonStartMsj(this->id, listo);
	return m;
}


bool ViewBotonStartMsj::isListo() {
	return listo;
}
