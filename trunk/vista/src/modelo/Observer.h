/*
 * Observer.h
 *
 *  Created on: 14/09/2013
 *      Author: jonathan
 */

#ifndef OBSERVER_H_
#define OBSERVER_H_
namespace CLIENTE {
class Observable;
enum event_type{DESTRUIR_VISTA, CAMBIO_VISTA};
class Observer {
public:
	virtual ~Observer(){};
	virtual void notify(Observable*, event_type) = 0;
};
}
#endif /* OBSERVER_H_ */
