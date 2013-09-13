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
	FiguraView * getFiguraTemplate(float x, float y);
public:
	ZonaJuego(Zona* zonaCreacion, Zona * zonaTablero, Cuadrado * dimensiones);
	virtual ~ZonaJuego();
	float getScrollY() const;
	void setScrollY(float scrollY);
	void dibujarse(SDL_Renderer *);
	bool removerFigura(FiguraView*);
	FiguraView * getVista(float x, float y);
	bool click(float x, float y);
};

#endif /* ZONAJUEGO_H_ */
