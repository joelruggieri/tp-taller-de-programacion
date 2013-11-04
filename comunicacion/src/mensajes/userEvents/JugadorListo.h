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
	void procesar(UserEventVisitor *);
	virtual ~JugadorListo();
	bool isListo() const;
};

#endif /* JUGADORLISTO_H_ */