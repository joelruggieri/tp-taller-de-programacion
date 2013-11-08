/*
 * MensajeInterno.cpp
 *
 *  Created on: 07/11/2013
 *      Author: jonathan
 */

#include "MensajeInterno.h"

MensajeInterno::MensajeInterno() {
	// TODO Auto-generated constructor stub

}

MensajeInterno::~MensajeInterno() {
	// TODO Auto-generated destructor stub
}

void MensajeInterno::acept(MensajeVisitor* v) {
	v->visit(this);
}
