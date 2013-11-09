/*
 * CreacionMsj.cpp
 *
 *  Created on: 08/11/2013
 *      Author: ezequiel
 */

#include "CreacionMsj.h"

CreacionMsj::CreacionMsj(string tag, float x, float y) :
		UserEventMsj(false, false) {
	this->tagObjeto = tag;
	this->x = x;
	this->y = y;
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
	nodo->push_back(this->x);
	nodo->push_back(this->y);
}

NetworkMensaje* CreacionMsj::deserialize(YAML::const_iterator& it) {
	string tag = it->as<string>();
	it++;
	float x = it->as<float>();
	it++;
	float y = it->as<float>();
	it++;
	return new CreacionMsj(tag, x, y);

}

float CreacionMsj::getX() const {
	return x;
}

void CreacionMsj::setX(float x) {
	this->x = x;
}

float CreacionMsj::getY() const {
	return y;
}

void CreacionMsj::setY(float y) {
	this->y = y;
}
