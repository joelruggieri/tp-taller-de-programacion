/*
 *
 *  Created on: 13/09/2013
 *      Author: jonathan
 */

#ifndef SCROLLVIEW_H_
#define SCROLLVIEW_H_

#include "View.h"
#include "SDL2/SDL.h"
#include "FlechaScrollView.h"
#include "../modelo/Observer.h"
#include "../modelo/Observable.h"
#include "../modelo/Scroll.h"
class ScrollView: public View, public Observer {
private:
	int contArriba;
	int contAbajo;
	int sleep;

	FlechaScrollView * arriba, *abajo;
public:
	ScrollView(FlechaScrollView * flechaArriba, FlechaScrollView* flechaAajo, Scroll* scroll, int sleep);
	virtual ~ScrollView();
	void dibujarse(SDL_Renderer*);
	void dibujarse(SDL_Renderer*, SDL_Rect &);
	void notify(Observable*);
	void resizear();
};

#endif /* SCROLLVIEW_H_ */
