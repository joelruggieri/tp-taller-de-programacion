/*
 * ObserverFiguraHelper.h
 *
 *  Created on: 19/10/2013
 *      Author: jonathan
 */

#ifndef OBSERVERFIGURAHELPER_H_
#define OBSERVERFIGURAHELPER_H_

#include "ObserverModelo.h"
#include "FiguraObserver.h"
class ObserverFiguraHelper: public ObserverModelo {
private:
	FiguraObserver * obs;
	ObservableModelo * last;
public:
	ObserverFiguraHelper(FiguraObserver* obs);
	void notifyEvent(ObservableModelo*, Evento_type);
	virtual ~ObserverFiguraHelper();
	ObservableModelo * getLastObservable();
};

#endif /* OBSERVERFIGURAHELPER_H_ */
