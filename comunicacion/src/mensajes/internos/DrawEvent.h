/*
 * DrawEvent.h
 *
 *  Created on: 07/11/2013
 *      Author: jonathan
 */

#ifndef DRAWEVENT_H_
#define DRAWEVENT_H_

#include "MensajeInterno.h"

class DrawEvent: public MensajeInterno {
public:
	DrawEvent();
	virtual ~DrawEvent();
	void acept(MensajeInternoVisitor *);
	void serialize(YAML::Node * nodo);
	NetworkMensaje * deserialize(YAML::const_iterator & it);
};

#endif /* DRAWEVENT_H_ */
