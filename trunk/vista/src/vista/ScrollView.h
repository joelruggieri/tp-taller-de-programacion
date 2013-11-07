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
#include "../modelo/Scroll.h"


namespace CLIENTE {
class ScrollView: public View{
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
	void notify(Observable*, event_type);
	void resizear();
};
}
#endif /* SCROLLVIEW_H_ */
