/*
 * ZonaPlay.h
 *
 *  Created on: 2/10/2013
 *      Author: jonathan
 */

#ifndef ZONAPLAY_H_
#define ZONAPLAY_H_

#include "ZonaDragAndDrop.h"
#include "../../vista/BotonSwitch.h"
class ZonaPlay: public Zona {
private:
	bool agregarTemplate(FiguraView * dragueable);
	FiguraView * getFiguraTemplate(float x, float y);
	BotonSwitch * boton;
	View * vista;
public:
	ZonaPlay(float x, float y);
	virtual ~ZonaPlay();
	bool mouseScroll(float x, float y, int amountScrolled);
	void dibujarse(SDL_Renderer *);
	void dibujarse(SDL_Renderer *, SDL_Rect &);
	bool click(float x, float y);
};

#endif /* ZONAPLAY_H_ */
