/*
 * ZonaJuego.h
 *
 *  Created on: 30/08/2013
 *      Author: jonathan
 */

#ifndef ZONAJUEGO_H_
#define ZONAJUEGO_H_
#include "ZonaDragAndDrop.h"
#include "../../vista/Dibujable.h"

#include "../../vista/figura/FiguraView.h"

class ZonaJuego: public ZonaDragAndDrop {
private:
	ZonaDragAndDrop * zonaTablero;
	ZonaDragAndDrop * zonaCreacion;
	bool dropTemplate(FiguraView * dragueable);
	FiguraView * dragTemplate(float x, float y);
public:
	ZonaJuego(SDL_Texture * texturaCanvas);
	virtual ~ZonaJuego();
	float getScrollY() const;
	void setScrollY(float scrollY);
	list<Figura*> getFiguras();
	void dibujarse(SDL_Renderer *);
};

#endif /* ZONAJUEGO_H_ */
