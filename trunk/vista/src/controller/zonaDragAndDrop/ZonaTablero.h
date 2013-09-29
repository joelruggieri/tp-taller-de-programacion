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
#include "../../vista/figura/FiguraView.h"
#include "../../vista/Canvas.h"
#include "../../vista/ViewConBorde.h"
#include <map>
using namespace std;


class ZonaTablero: public Zona{
private:
	bool agregarTemplate(FiguraView * dragueable);
	FiguraView * getFiguraTemplate(float x, float y);
	Canvas * canvas;
	ViewConBorde * viewCanvas;
public:
	ZonaTablero(float, float, SDL_Texture *);
	virtual ~ZonaTablero();
	void dibujarse(SDL_Renderer *);
	void dibujarse(SDL_Renderer *, SDL_Rect &);
	bool removerFigura(FiguraView*);
	bool click(float x, float y);
	Canvas* getCanvas();
	bool mouseScroll(float x, float y, int amountScrolled);
};

#endif /* ZONATABLERO_H_ */

