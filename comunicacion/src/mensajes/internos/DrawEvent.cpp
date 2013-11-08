/*
 * DrawEvent.cpp
 *
 *  Created on: 07/11/2013
 *      Author: jonathan
 */

#include "DrawEvent.h"

DrawEvent::DrawEvent() {
	// TODO Auto-generated constructor stub

}

DrawEvent::~DrawEvent() {
	// TODO Auto-generated destructor stub
}

void DrawEvent::acept(MensajeInternoVisitor* v) {
	v->visit(this);
}

void DrawEvent::serialize(YAML::Node* nodo) {
	nodo->push_back(TAG_INTERNO_DRAW);
}

NetworkMensaje* DrawEvent::deserialize(YAML::const_iterator& it) {
	return new DrawEvent();
}
