/*
 * Highlight.cpp
 *
 *  Created on: 13/11/2013
 *      Author: jonathan
 */

#include "Highlight.h"
#include "ViewMsjVisitor.h"

Highlight::Highlight(int id): ViewMsj(id, 'a') {

}

Highlight::~Highlight() {
}

void Highlight::acept(ViewMsjVisitor* v) {
	v->visit(this);
}

void Highlight::serialize(YAML::Node* nodo) {
	nodo->push_back(TAG_HIGHLIGHT);
	nodo->push_back(id);
}

NetworkMensaje* Highlight::deserialize(YAML::const_iterator& it) {
	int id = it->as<int>();
	it++;
	return new Highlight(id);
}

ViewMsj* Highlight::clone(int destinatario) {
	ViewMsj * msj = new Highlight(id);
	msj->setDestinatario(destinatario);
	return msj;
}

