/*
 * ObserverFiguraHelper.cpp
 *
 *  Created on: 19/10/2013
 *      Author: jonathan
 */

#include "ObserverFiguraHelper.h"


ObserverFiguraHelper::ObserverFiguraHelper(FiguraObserver* obs) {
	this->obs = obs;
}

void ObserverFiguraHelper::notifyEvent(ObservableModelo* o, Evento_type type) {
	this->last = o;
	this->obs->notifyEvent(type);
}

ObserverFiguraHelper::~ObserverFiguraHelper() {

}

ObservableModelo* ObserverFiguraHelper::getLastObservable() {
	return this->last;
}
