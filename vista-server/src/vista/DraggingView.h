/*
 * DraggingView.h
 *
 *  Created on: 10/09/2013
 *      Author: jonathan
 */

#ifndef DRAGGINGVIEW_H_
#define DRAGGINGVIEW_H_
#include "SDL2/SDL.h"
#include "Dibujable.h"
#include "Dragueable.h"
class DraggingView: public Dibujable {
private:
	Dragueable * dragueable;
public:
	DraggingView(Dragueable*);
	virtual ~DraggingView();
	void dibujarse(list<ViewMsj*> & lista);
};

#endif /* DRAGGINGVIEW_H_ */
