/*
 * ObserverModelo.h
 *
 *  Created on: 18/10/2013
 *      Author: jonathan
 */

#ifndef OBSERVERMODELO_H_
#define OBSERVERMODELO_H_

#include "ObservableModelo.h"
#include "Evento.h"
class ObserverModelo {
public:
	ObserverModelo();
	virtual ~ObserverModelo();
	virtual void notifyEvent(ObservableModelo*, Evento_type) = 0;
};

#endif /* OBSERVERMODELO_H_ */
