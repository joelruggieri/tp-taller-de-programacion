/*
 * ZonaJuego.h
 *
 *  Created on: 30/08/2013
 *      Author: jonathan
 */

#ifndef ZONAJUEGO_H_
#define ZONAJUEGO_H_
#include "ZonaDragAndDrop.h"

#include "../../vista/figura/FiguraView.h"

class ZonaJuego: public ZonaDragAndDrop {
private:
	ZonaDragAndDrop * zonaTablero;
	ZonaDragAndDrop * zonaCreacion;
	bool dropTemplate(FiguraView * dragueable);
	FiguraView * dragTemplate(float x, float y);
public:
	ZonaJuego();
	virtual ~ZonaJuego();
	float getScrollY() const;
	void setScrollY(float scrollY);
	list<Figura*> getFiguras();
};

#endif /* ZONAJUEGO_H_ */
