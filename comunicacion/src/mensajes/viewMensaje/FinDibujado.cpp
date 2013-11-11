/*
 * FinDibujado.cpp
 *
 *  Created on: 11/11/2013
 *      Author: jonathan
 */

#include "FinDibujado.h"

FinDibujado::FinDibujado():ViewMsj(-2,'a') {

}

FinDibujado::~FinDibujado() {
	// TODO Auto-generated destructor stub
}

void FinDibujado::serialize(YAML::Node* nodo) {
	nodo->push_back(TAG_FIN_DIBUJADO);
}

NetworkMensaje* FinDibujado::deserialize(YAML::const_iterator& it) {
	return new FinDibujado();
}

void FinDibujado::acept(ViewMsjVisitor* v) {
	v->visit(this);
}

ViewMsj* FinDibujado::clone(int destinatario) {
	ViewMsj * c = new FinDibujado();
	c->setDestinatario(destinatario);
	return c;
}
