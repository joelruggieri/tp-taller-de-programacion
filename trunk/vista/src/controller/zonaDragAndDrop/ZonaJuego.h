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

class ZonaJuego: public Zona {
private:
	Zona * zonaTablero;
	Zona * zonaCreacion;
	bool agregarTemplate(FiguraView * dragueable);
	bool clickTemplate(float x, float y);
public:
	ZonaJuego(Zona* zonaCreacion, Zona * zonaTablero, Cuadrado * dimensiones);
	virtual ~ZonaJuego();
	float getScrollY() const;
	void setScrollY(float scrollY);
	list<Figura*> getFiguras();
	void dibujarse(SDL_Renderer *);
	bool click(float, float);
	bool removerFigura(FiguraView*);
};

#endif /* ZONAJUEGO_H_ */
