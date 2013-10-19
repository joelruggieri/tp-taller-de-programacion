/*
 * FiguraObserver.h
 *
 *  Created on: 19/10/2013
 *      Author: jonathan
 */

#ifndef FIGURAOBSERVER_H_
#define FIGURAOBSERVER_H_

#include "ObservableModelo.h"
#include "Evento.h"
class FiguraObserver {
public:
	virtual ~FiguraObserver(){};
	virtual void notifyEvent(Evento_type) = 0;
};

#endif /* FIGURAOBSERVER_H_ */
