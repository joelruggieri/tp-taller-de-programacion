/*
 * StepModelo.h
 *
 *  Created on: 09/11/2013
 *      Author: jonathan
 */

#ifndef STEPMODELO_H_
#define STEPMODELO_H_

#include "MensajeInterno.h"

class StepModelo: public MensajeInterno {
public:
	StepModelo();
	virtual ~StepModelo();
	void acept(MensajeInternoVisitor *);
	void serialize(YAML::Emitter & out);
	NetworkMensaje * deserialize(YAML::const_iterator &);
};

#endif /* StepModelo_H_ */
