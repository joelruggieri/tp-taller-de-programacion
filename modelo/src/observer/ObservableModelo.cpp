/*
 * ObservableModelo.cpp
 *
 *  Created on: 19/10/2013
 *      Author: jonathan
 */

#include "ObservableModelo.h"
#include "ObserverModelo.h"
ObservableModelo::ObservableModelo() {
	// TODO Auto-generated constructor stub

}

void ObservableModelo::addObserver(ObserverModelo* o) {
	this->observers.push_back(o);
}

void ObservableModelo::removeObserver(ObserverModelo* o) {
	this->observers.remove(o);
}

ObservableModelo::~ObservableModelo() {
	// TODO Auto-generated destructor stub
}

void ObservableModelo::notify(Evento_type e) {
	list<ObserverModelo*>::iterator it;
	for(it=this->observers.begin(); it!= this->observers.end(); ++it){
		(*it)->notifyEvent(this, e);
	}
}
