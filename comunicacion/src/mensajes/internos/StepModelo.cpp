/*
 * StepModelo.cpp
 *
 *  Created on: 09/11/2013
 *      Author: jonathan
 */

#include "StepModelo.h"

StepModelo::StepModelo() {
}

StepModelo::~StepModelo() {
	// TODO Auto-generated destructor stub
}

void StepModelo::acept(MensajeInternoVisitor* v) {
	v->visit(this);
}

void StepModelo::serialize(YAML::Emitter & out) {
}

NetworkMensaje* StepModelo::deserialize(YAML::const_iterator& it) {
	return new StepModelo();
}
