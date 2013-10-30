/*
 * Observable.h
 *
 *  Created on: 14/09/2013
 *      Author: jonathan
 */

#ifndef OBSERVABLE_H_
#define OBSERVABLE_H_
#include <list>
#include "Observer.h"
using namespace std;

class Observable {
	list<Observer*> observers;
public:
	Observable();
	virtual ~Observable();
	void notifY(event_type);
	void addObserver(Observer*);
};

#endif /* OBSERVABLE_H_ */
