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
public:
	ZonaPlay(float x, float y);
	virtual ~ZonaPlay();
	bool mouseScroll(float x, float y, int amountScrolled);
	void dibujarse(list<ViewMsj*> & lista);
	bool click(float x, float y);
};

#endif /* ZONAPLAY_H_ */
