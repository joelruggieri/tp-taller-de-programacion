/*
 * ZonaTablero.h
 *
 *  Created on: 30/08/2013
 *      Author: jonathan
 */

#ifndef ZONATABLERO_H_
#define ZONATABLERO_H_

#include "ZonaDragAndDrop.h"
#include <list>
#include "src/figura/Mapa.h"
#include "../../vista/figura/FiguraView.h"
#include "../../vista/Dibujable.h"

class ZonaTablero: public ZonaDragAndDrop{
private:
	bool dropTemplate(FiguraView * dragueable);
	FiguraView * dragTemplate(float x, float y);
	Mapa * mapa;
	list<FiguraView*> figuras;
	Dibujable * fondo;
public:
	ZonaTablero(Mapa *, float, float, SDL_Texture *);
	virtual ~ZonaTablero();
	void dibujarse(SDL_Renderer *);
};

#endif /* ZONATABLERO_H_ */
