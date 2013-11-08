/*
 * MensajeInterno.h
 *
 *  Created on: 07/11/2013
 *      Author: jonathan
 */

#ifndef MENSAJEINTERNO_H_
#define MENSAJEINTERNO_H_
#include "MensajeInternoVisitor.h"
#include "../NetworkMensaje.h"
class MensajeInterno: public NetworkMensaje {
public:
	MensajeInterno();
	virtual ~MensajeInterno();
	void acept(MensajeVisitor *);
	virtual void acept(MensajeInternoVisitor *) = 0;
};

#endif /* MENSAJEINTERNO_H_ */
