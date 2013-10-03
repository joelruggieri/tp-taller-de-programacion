/*
 * BotonSwitch.h
 *
 *  Created on: 2/10/2013
 *      Author: jonathan
 */

#ifndef BOTONSWITCH_H_
#define BOTONSWITCH_H_
#include "View.h"
class BotonSwitch: public View {
private:
	bool presionado;
	int evento1,evento2;
	SDL_Texture * t1, *t2;
public:
	BotonSwitch(float x,float y,float w,float h,int eventoUno, int eventoDos, SDL_Texture * text1, SDL_Texture * text2);
	virtual ~BotonSwitch();
	void dibujarse(SDL_Renderer*);
	void dibujarse(SDL_Renderer*, SDL_Rect&);
	void click();
};

#endif /* BOTONSWITCH_H_ */
