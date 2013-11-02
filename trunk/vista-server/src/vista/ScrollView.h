/*
 *
 *  Created on: 13/09/2013
 *      Author: jonathan
 */

#ifndef SCROLLVIEW_H_
#define SCROLLVIEW_H_

#include "View.h"
#include "SDL2/SDL.h"
#include "../modelo/Observer.h"
#include "../modelo/Observable.h"
#include "../modelo/Scroll.h"
#include "src/mensajes/ViewMsj.h"
#include <list>
using namespace std;

class ScrollView: public View, public Observer {
private:
//	int contArriba;
//	int contAbajo;
//	int sleep;

public:
	ScrollView(Scroll* scroll, int sleep);
	virtual ~ScrollView();
	void dibujarse(list<ViewMsj*> & lista);
	void notify(Observable*, event_type);
//	void resizear();
};

#endif /* SCROLLVIEW_H_ */
