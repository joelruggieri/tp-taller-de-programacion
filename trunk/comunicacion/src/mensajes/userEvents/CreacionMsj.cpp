/*
 * CreacionMsj.cpp
 *
 *  Created on: 08/11/2013
 *      Author: ezequiel
 */

#include "CreacionMsj.h"

CreacionMsj::CreacionMsj(string tag): UserEventMsj(false, false) {
this->tagObjeto = tag;
}

CreacionMsj::~CreacionMsj() {
	// TODO Auto-generated destructor stub
}

void CreacionMsj::acept(UserEventVisitor* v) {
	v->visit(this);
}

void CreacionMsj::serialize(YAML::Node* nodo) {
	nodo->push_back(TAG_CREACION_OBJETO);
	nodo->push_back(this->tagObjeto);
}

NetworkMensaje* CreacionMsj::deserialize(YAML::const_iterator& it) {
	string tag = it->as<string>();
	it++;
	return new CreacionMsj(tag);

}
