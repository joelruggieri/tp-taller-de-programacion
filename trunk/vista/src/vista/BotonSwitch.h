/*
 * BotonSwitch.h
 *
 *  Created on: 2/10/2013
 *      Author: jonathan
 */

#ifndef BOTONSWITCH_H_
#define BOTONSWITCH_H_
#include "View.h"

namespace CLIENTE {

class BotonSwitch: public View {
private:
	bool presionado;
	SDL_Texture * t1, *t2;
public:
	BotonSwitch(float x,float y,float w,float h,SDL_Texture * text1, SDL_Texture * text2);
	virtual ~BotonSwitch();
	void dibujarse(SDL_Renderer*);
	void dibujarse(SDL_Renderer*, SDL_Rect&);
	void click();
};
}
#endif /* BOTONSWITCH_H_ */
