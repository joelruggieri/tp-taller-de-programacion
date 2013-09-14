/*
 * Observable.cpp
 *
 *  Created on: 14/09/2013
 *      Author: jonathan
 */

#include "Observable.h"
#include "Observer.h"
Observable::Observable() {
	// TODO Auto-generated constructor stub

}

Observable::~Observable() {
	// TODO Auto-generated destructor stub
}

void Observable::notifY() {
	list<Observer*>::iterator it;
	for(it=this->observers.begin(); it!= this->observers.end(); ++it){
		(*it)->notify(this);
	}
}

void Observable::addObserver(Observer* obs) {
	this->observers.push_back(obs);
}
