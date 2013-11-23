/*
 * ObservableModelo.h
 *
 *  Created on: 19/10/2013
 *      Author: jonathan
 */

#ifndef OBSERVABLEMODELO_H_
#define OBSERVABLEMODELO_H_
#include <list>
#include "Evento.h"
using namespace std;

class ObserverModelo;
class ObservableModelo {
private:
	list<ObserverModelo *> observers;
public:
	ObservableModelo();
	void addObserver(ObserverModelo * o);
	void removeObserver(ObserverModelo * o);
	void notify(Evento_type);
	void getObservers(list<ObserverModelo*>&);
	virtual ~ObservableModelo();
};

#endif /* OBSERVABLEMODELO_H_ */
