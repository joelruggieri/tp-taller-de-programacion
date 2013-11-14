/*
 * JugadorListo.h
 *
 *  Created on: 04/11/2013
 *      Author: jonathan
 */

#ifndef JUGADORLISTO_H_
#define JUGADORLISTO_H_

#include "UserEventMsj.h"

class JugadorListo: public UserEventMsj {
private:
	bool listo;
public:
	JugadorListo(bool listo);
	void acept(UserEventVisitor *);
	virtual ~JugadorListo();
	bool isListo() const;
	void serialize(YAML::Emitter & out);
	NetworkMensaje * deserialize(YAML::const_iterator & it);
};

#endif /* JUGADORLISTO_H_ */
