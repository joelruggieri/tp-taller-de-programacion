/*
 * FactoryView.h
 *
 *  Created on: 21/09/2013
 *      Author: jonathan
 */

#ifndef FACTORYVIEW_H_
#define FACTORYVIEW_H_

#include "SDL2/SDL.h"
#include "View.h"
class FactoryView: public View {
private:
public:
	FactoryView();
	virtual ~FactoryView();
	void dibujarse(list<ViewMsj*> & lista);
//	void resizear();
};

#endif /* FACTORYVIEW_H_ */
