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

class ZonaTablero: public ZonaDragAndDrop {
private:
	bool dropTemplate(FiguraView * dragueable);
	FiguraView * dragTemplate(float x, float y);
	Mapa * mapa;
	list<FiguraView*> figuras;
public:
	ZonaTablero(Mapa *);
	virtual ~ZonaTablero();

};

#endif /* ZONATABLERO_H_ */
