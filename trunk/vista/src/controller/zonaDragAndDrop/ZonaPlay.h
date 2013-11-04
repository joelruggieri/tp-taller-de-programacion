/*
 * ZonaPlay.h
 *
 *  Created on: 2/10/2013
 *      Author: jonathan
 */

#ifndef ZONAPLAY_H_
#define ZONAPLAY_H_
#include "../../modelo/Cuadrado.h"
#include "../../vista/BotonSwitch.h"
class ZonaPlay {
private:
	BotonSwitch * boton;
	View * vista;
	Cuadrado * cuerpo;
public:
	ZonaPlay(float x, float y);

	virtual ~ZonaPlay();
	bool mouseScroll(float x, float y, int amountScrolled);
	void dibujarse(SDL_Renderer *);
	void dibujarse(SDL_Renderer *, SDL_Rect &);
	bool click(float x, float y);
};

#endif /* ZONAPLAY_H_ */
