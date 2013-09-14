/*
 * Observer.h
 *
 *  Created on: 14/09/2013
 *      Author: jonathan
 */

#ifndef OBSERVER_H_
#define OBSERVER_H_

class Observable;

class Observer {
public:
	virtual ~Observer(){};
	virtual void notify(Observable*) = 0;
};

#endif /* OBSERVER_H_ */
