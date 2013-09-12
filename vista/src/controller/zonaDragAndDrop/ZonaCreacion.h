/*
 * ZonaCreacion.h
 *
 *  Created on: 30/08/2013
 *      Author: jonathan
 */

#ifndef ZONACREACION_H_
#define ZONACREACION_H_

#include "ZonaDragAndDrop.h"
#include "EslabonCreacion.h"
#include "../viewFactory/ViewFiguraFactory.h"
#include <list>
#include "../../vista/Canvas.h"
using namespace std;

class ZonaCreacion: public Zona {
private:
	EslabonCreacion * inicioCadena;
	EslabonCreacion * ultimo;
	static const int ANCHO_VIEW_DEF = 10;
	bool agregarTemplate(FiguraView * dragueable);
	FiguraView * getFiguraTemplate(float x, float y);
	list<Dibujable* > vistasFactories;
	void inicializar(list<ViewFiguraFactory*> *, float x, float margenSuperior);
	Canvas * canvas;
public:
	ZonaCreacion(list<ViewFiguraFactory*> *, float x, float margenSuperior, SDL_Texture *);
	virtual ~ZonaCreacion();
	void agregarEslabon(EslabonCreacion* eslabon);
	void dibujarse(SDL_Renderer *);
	bool removerFigura(FiguraView*);
};

#endif /* ZONACREACION_H_ */
